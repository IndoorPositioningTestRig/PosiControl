from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from Communication.Communication import Communication
from Communication.Communication import validate_type


communication = Communication()
communication.setup()


def create_response(msg: str):
    res = {
        "message": msg
    }
    return res


@csrf_exempt
def index(request, target: int, msg_type: int):
    valid = validate_type(msg_type)
    if not valid:
        return HttpResponse(create_response("invalid type"), status=400)
    else:
        communication.write_json(request.body, target, msg_type)
        return HttpResponse(create_response("sent!"))


def read(request):
    res = communication.read()
    return HttpResponse(res)
