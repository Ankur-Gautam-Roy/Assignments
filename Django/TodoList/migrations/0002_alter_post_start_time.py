# Generated by Django 3.2.14 on 2022-07-19 09:36

from django.db import migrations, models
import django.utils.timezone


class Migration(migrations.Migration):

    dependencies = [
        ('TodoList', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='post',
            name='start_time',
            field=models.DateTimeField(default=django.utils.timezone.now),
        ),
    ]
