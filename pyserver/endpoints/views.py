from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from endpoints.Communication.Communication import Communication
from endpoints.Communication.Communication import validate_type
import json

communication = Communication()
if not communication.setup():
    print("failed to setup rs485 communication")


def create_response(msg: str):
    res = {
        "message": msg
    }
    return json.dumps(res)


@csrf_exempt
def index(request, target: int, msg_type: int):
    valid = validate_type(msg_type)
    if not valid:
        return HttpResponse(create_response("invalid type"), status=400)
    else:
        communication.write(request.body, target, msg_type)
        return HttpResponse(create_response("sent!"))


def read(request):
    res = communication.read()
    return HttpResponse(res)
