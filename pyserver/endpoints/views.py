from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def index(request):
    return HttpResponse("hello motherfucker")

def post(request):
    return HttpResponse(request)
    