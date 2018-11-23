from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt


@csrf_exempt
def index(request, target: int, msg_type: int):
    return HttpResponse("hello motherfucker")

