# Generated by Django 2.2.7 on 2019-11-27 08:59

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('pushNoticeFile', '0009_auto_20191127_1657'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='noticecfg',
            name='host_url',
        ),
        migrations.RemoveField(
            model_name='noticecfg',
            name='server_root',
        ),
        migrations.AddField(
            model_name='sshcfg',
            name='host_url',
            field=models.CharField(max_length=50, null=True),
        ),
        migrations.AddField(
            model_name='sshcfg',
            name='server_root',
            field=models.CharField(max_length=50, null=True),
        ),
    ]
