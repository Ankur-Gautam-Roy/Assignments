from django.shortcuts import redirect, render
from .models import Task
from django.utils import timezone
from django.shortcuts import render


def task_list(request):
    tasks = Task.objects.order_by('deadline')
    return render(request, 'TodoList\index.html', {'tasks':tasks})

def add_list(request):
    print(request.POST.get('task1'), request.method)
    if request.method=="POST":
        taskObj = Task()
        taskObj.title =request.POST.get('task1')
        taskObj.description =request.POST.get('desc')
        taskObj.start_date =request.POST.get(str('start_date'))
        taskObj.deadline =request.POST.get(str('deadline'))
        taskObj.save()

    
    return render(request, 'TodoList\\addList.html', {})

def updateList(request,id):
    if request.method == "POST":
        db = Task()
        db.id = id
        db.title = request.POST.get('task1')
        db.description = request.POST.get('desc')
        db.start_date = request.POST.get('start_date')
        db.deadline = request.POST.get('deadline')
        db.save()
        return redirect('task_list')

    tasks = Task.objects.filter(id = id)
    return render(request, 'TodoList\\updateList.html', {'title' : str(tasks[0].title) , 'description':str(tasks[0].description) , 'start_date': str(tasks[0].start_date), 'deadline':str(tasks[0].deadline) })
 

def deleteList(request , id):
    Task.objects.filter(id = id).delete()
    return redirect('task_list')