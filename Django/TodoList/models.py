from msilib.schema import TextStyle
from secrets import choice
from django.conf import settings
from django.db import models
from django.utils import timezone


class Task(models.Model):
    id = models.AutoField(primary_key=True)
    title = models.CharField(max_length=200)
    description = models.CharField(max_length=200)
    start_date = models.DateField(blank=True, null=False)
    deadline = models.DateField(blank=True, null=True)
    
    def publish(self):
        self.deadline = timezone.now()
        self.save()

    def __str__(self):
        return self.title  