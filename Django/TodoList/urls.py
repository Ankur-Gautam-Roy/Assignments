from django.urls import path
from . import views

urlpatterns = [
     path('', views.task_list, name='task_list'),
    path('addlist/', views.add_list, name='add_list'),
    path('deleteList/?P<int:id>', views.deleteList, name='deleteList'),
    path('updateList/?P<int:id>', views.updateList, name='updateList'),
]