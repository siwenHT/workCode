from django.urls import path

from . import views

app_name = 'pushNoticeFile'
urlpatterns = [
    path('', views.IndexView.as_view(), name='index'),
    path('<int:pk>/', views.DetailView.as_view(), name='detail'),
    path('<int:pk>/chooseNotice/', views.chooseOldLogView.as_view(), name='chooseNotice'),
    path('<int:pk>/pushNotice/', views.pushNotice, name='pushNotice'),
]