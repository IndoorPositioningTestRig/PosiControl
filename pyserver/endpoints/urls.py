from django.urls import path

from . import views

urlpatterns = [
    path('msg/<int:target>/<int:msg_type>/', views.index, name='index'),
    path('debug/<int:target>/', views.request_debug, name='debug'),
    path('setPoint/<int:target>/<int:set_point>/', views.set_point_debug, name='set_point')
]
