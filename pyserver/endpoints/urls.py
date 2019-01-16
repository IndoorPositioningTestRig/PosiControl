from django.urls import path, register_converter

from . import views


class NegativeIntConverter:
    regex = '-?\d+'

    def to_python(self, value):
        return int(value)

    def to_url(self, value):
        return '%d' % value


class IntOrFloatConverter:
    regex = "(\d+(?:\.\d+)?)"

    def to_python(self, value):
        return float(value)

    def to_url(self, value):
        return "%d" % value


register_converter(NegativeIntConverter, 'negint')
register_converter(IntOrFloatConverter, 'ifloat')

urlpatterns = [
    path('msg/<int:target>/<int:msg_type>/',
         views.message,
         name='message'
         ),
    path('debug/<int:target>/',
         views.request_debug,
         name='debug'
         ),
    path('pid/<int:target>',
         views.get_pid,
         name="get_pid"
         ),
    path('set_pid/<int:target>/<ifloat:p>/<ifloat:i>/<ifloat:d>/',
         views.set_pid,
         name="set_pid"
         ),
    path('setPoint/<int:target>/<negint:set_point>/<int:encoder>/',
         views.set_point_debug,
         name='set_point'
         ),
    path('ping/<int:target>/',
         views.ping,
         name='ping'
         ),
    path('home/',
         views.home,
         name='home'
         )
]
