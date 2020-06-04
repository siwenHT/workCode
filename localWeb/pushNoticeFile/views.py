# -*- coding:utf-8 -*-
from django.shortcuts import render, loader, get_object_or_404
from django.http import HttpResponse, Http404, HttpResponseRedirect
from django.contrib import auth
from django.urls import reverse
from django.views import generic
from django.contrib.auth.decorators import login_required
from django.utils import timezone

# Create your views here.

from .models import Game, NoticeCfg, NoticeLog
from .pushNotice import pushNoticeFunc

class IndexView(generic.ListView):
    model = NoticeCfg
    # template_name = 'pushNoticeFile/index.html'
    # context_object_name = ''

class DetailView(generic.DetailView):
    model = NoticeCfg
    template_name = 'pushNoticeFile/notice_detail.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['noticeList'] = context['noticecfg'].noticelog_set.order_by('-date')[:5]
        context['oldLog'] = '请输入公告内容'
        return context

class chooseOldLogView(generic.TemplateView):

    def __init__(self, **kwargs):
        super(chooseOldLogView, self).__init__(**kwargs)
        self.request = None
        self.args = None
        self.kwargs = None
        self.curNoticeCfg = None
        self.context = None
        self.template_name = 'pushNoticeFile/notice_detail.html'

    def get_context_data(self, **kwargs):
        tmpContext = super().get_context_data(**kwargs)
        tmpContext['noticecfg'] = get_object_or_404(NoticeCfg, pk = tmpContext['pk'])
        tmpContext['noticeList'] = tmpContext['noticecfg'].noticelog_set.order_by('-date')[:5]
        self.curNoticeCfg = tmpContext['noticecfg']
        return tmpContext

    def handle_context_data(self, **kwargs):
        context = self.get_context_data(**kwargs)
        pk = self.request.POST['noticelog']

        try:
            selected_noticelog = self.curNoticeCfg.noticelog_set.get(pk=pk)
        except (KeyError, NoticeLog.DoesNotExist):
            context['oldLog'] = ''
        else:
            context['oldLog'] = selected_noticelog.text

        return render(self.request, self.template_name, context)

    def post(self, request, *args, **kwargs):
        self.request = request
        self.args = args
        self.kwargs = kwargs
        return self.handle_context_data(**kwargs)

def pushNotice(request, pk):

    tmpCfg = get_object_or_404(NoticeCfg, pk = pk)
    template_name = 'pushNoticeFile/notice_detail.html'
    text = request.POST['context']
    if text and text != "请输入公告内容":
        context = {
            'noticecfg':tmpCfg,
            'oldLog':text,
        }
        tmpCfg.noticelog_set.create(text = text, date = timezone.now())
        tmpCfg.save()
        
        ret = pushNoticeFunc(text, tmpCfg)
        if ret == None:
            context['error_message'] = '公告更新成功'
        else:
            context['error_message'] = ret + ''
    else:
        context = {
            'noticecfg':tmpCfg,
            'error_message':'推送公告不能为空!',
        }

    context['noticeList'] = context['noticecfg'].noticelog_set.order_by('-date')[:5]
    return render(request, template_name, context)