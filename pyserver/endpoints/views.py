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


@csrf_exempt
def request_debug(request, target: int):
    req_dict = {
        "command":"debug"
    }

    communication.write_json(req_dict, target, Communication.REQUEST)
    read = communication.read()
    if type(read) is int:
        return HttpResponse(create_response("failed with code: " + str(read)))

    json_res = json.dumps([ob.to_dict() for ob in read])
    res = HttpResponse(json_res)
    res["access-control-allow-origin"] = "*"
    return res
