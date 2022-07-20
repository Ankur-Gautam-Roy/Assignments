from django.shortcuts import render
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
        taskObj.start_date =request.POST.get('start_date')
        taskObj.deadline =request.POST.get('deadline')
        taskObj.save()

    
    return render(request, 'TodoList\\addList.html',{})

def sort_list(request):
    tasks = Task.objects.order_by('-deadline')
    return render(request, 'TodoList\index.html', {'tasks':tasks})