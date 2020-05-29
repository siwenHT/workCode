import datetime

from django.db import models
from django.utils import timezone

class SshCfg(models.Model):
    user = models.CharField(max_length=50)
    psw = models.CharField(max_length=50)
    ip = models.CharField(max_length=20)
    port = models.IntegerField()
    desc_text = models.CharField(max_length=200)
    host_url = models.CharField(max_length=50, null=True)
    server_root = models.CharField(max_length=50, null=True)

    def __str__(self):
        return self.desc_text

class CdnCfg(models.Model):
    secret_id = models.CharField(max_length=80)
    secret_key = models.CharField(max_length=80)
    desc_text = models.CharField(max_length=200)

    def __str__(self):
        return self.desc_text

class NoticeCfg(models.Model):
    desc_text = models.CharField(max_length=200)
    ssh = models.ForeignKey(SshCfg, on_delete = models.SET_NULL, null = True)
    cdn = models.ForeignKey(CdnCfg, on_delete = models.SET_NULL, null = True)

    def __str__(self):
        return self.desc_text

class Game(models.Model):
    game_name = models.CharField(max_length=100)
    platform = models.CharField(max_length=30)
    sdk = models.CharField(max_length=50)
    desc_text = models.CharField(max_length=200)
    version_url = models.CharField(max_length=200)
    notice_url = models.CharField(max_length=200)
    noticeCfg = models.ForeignKey(NoticeCfg, on_delete=models.SET_NULL, null = True)

    def __str__(self):
        return self.game_name

class NoticeLog(models.Model):
    noticeCfg = models.ForeignKey(NoticeCfg, on_delete=models.CASCADE)
    text = models.CharField(max_length=4096)
    date = models.DateTimeField('notice Time')

    def __str__(self):
        count = len(self.text)
        if count > 50:
            return self.text[0:49]
        else:
            return self.text


