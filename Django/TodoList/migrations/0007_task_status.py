# Generated by Django 3.2.14 on 2022-07-19 10:17

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('TodoList', '0006_rename_task_task_title'),
    ]

    operations = [
        migrations.AddField(
            model_name='task',
            name='status',
            field=models.CharField(default='green', max_length=3),
        ),
    ]
