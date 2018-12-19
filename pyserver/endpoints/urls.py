from django.urls import path, register_converter

from . import views


class NegativeIntConverter:
    regex = '-?\d+'

    def to_python(self, value):
        return int(value)

    def to_url(self, value):
        return '%d' % value

register_converter(NegativeIntConverter, 'negint')

urlpatterns = [
    path('msg/<int:target>/<int:msg_type>/', views.message, name='message'),
    path('debug/<int:target>/', views.request_debug, name='debug'),
    path('setPoint/<int:target>/<negint:set_point>/',
         views.set_point_debug,
         name='set_point'
         )
]
