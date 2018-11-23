from django.urls import path

from . import views

urlpatterns = [
    path('msg/<int:target>/<int:msg_type>/', views.index, name='index'),
]
