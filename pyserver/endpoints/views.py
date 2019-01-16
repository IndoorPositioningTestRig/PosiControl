from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from endpoints.Communication.Communication import Communication
from endpoints.Communication.Communication import validate_type
import json
from typing import List

communication = Communication()
if not communication.setup():
    raise Exception("failed to setup rs485 communication")


def create_response_message(msg: str, status=200):
    dictionary = {
        "message": msg
    }
    return create_response(dictionary, status)


def create_response(raw, status=200):
    res_string = ""
    if type(raw) is dict:
        res_string = json.dumps(raw)
    elif type(raw) is str:
        res_string = raw

    http_res = HttpResponse(res_string, status=status)
    http_res["access-control-allow-origin"] = "*"
    return http_res


@csrf_exempt
def set_pid(request, target: int, p: float, i: float, d: float):
    """ Set the PID values """
    req_dict = {
        "command": "set_pid",
        "p": p,
        "i": i,
        "d": d
    }
    communication.write_json(req_dict, target, Communication.COMMAND)
    return create_response_message("Done")


@csrf_exempt
def get_pid(request, target: int):
    """ Get the PID values """
    req_dict = {
        "command": "get_pid"
    }
    communication.write_json(req_dict, target, Communication.REQUEST)
    communication.flush()
    read = communication.read_pid()
    if read is None:
        return create_response_message("Failed to read", 500)

    return create_response(read)


@csrf_exempt
def ping(request, target: int):
    """ Send a ping and wait for a result """
    req_dict = {
        "command": "ping"
    }
    communication.write_json(req_dict, target, Communication.REQUEST)
    communication.flush()
    res = communication.read_str()
    if res is None:
        return create_response_message("failed to read", status=500)
    else:
        return create_response(res)


@csrf_exempt
def message(request, target: int, msg_type: int):
    """ Send an arbitrary message """
    valid = validate_type(msg_type)
    if not valid:
        return create_response_message("invalid type", status=400)
    else:
        communication.write(request.body, target, msg_type)
        return create_response_message("sent!")


def read_debug(req_dict: dict, target: int):
    """ Send a command then listen for debug data """
    communication.write_json(req_dict, target, Communication.REQUEST)
    communication.flush()
    read = communication.read_data_points()
    if type(read) is int:
        return create_response_message("failed with code: " + str(read), status=500)

    json_res = json.dumps([ob.to_dict() for ob in read])
    return create_response(json_res)


@csrf_exempt
def request_debug(request, target: int):
    """ Request stored debug data """
    req_dict = {
        "command": "debug"
    }
    return read_debug(req_dict, target)


@csrf_exempt
def set_point_debug(request, target: int, set_point: int, encoder: int):
    """ Move to given setPoint and send debug data when done"""
    command = "setPoint_debug"
    if encoder > 0:
        command = "setPointEncoder_debug"

    req_dict = {
        "command": command,
        "setpoint": set_point
    }
    return read_debug(req_dict, target)


def home_target(target: int):
    req_dict = {
        "command": "home",
        "support": False
    }
    communication.write_json(req_dict, target, communication.REQUEST)


def home_support(targets: List[int]):
    req_dict = {
        "command": "home",
        "support": True
    }
    for target in targets:
        communication.write_json(req_dict, target, communication.REQUEST)


def await_home(current) -> bool:
    response = communication.read(120)
    if response is None:
        return False
    if response.message_type != communication.RESPONSE:
        return False
    if response.sender != current:
        print("supporter: " + str(response.sender) + " reported a problem")
        return False

    data_str = response.data.decode("utf-8")
    print("home result: " + data_str)
    data = json.loads(data_str)
    return data["result"]


@csrf_exempt
def home(request):
    all_list = {}
    for i in range(1, 9):
        all_list[i] = False

    # For testing we only use the top 4
    del all_list[5]
    del all_list[6]
    del all_list[7]
    del all_list[8]

    # for current in range(1, 9):
    for current in range(1, 4):
        # Set the current module to home
        home_target(current)

        # Have all the other modules support
        all_list_copy = all_list.copy()
        del all_list_copy[current]
        home_support(list(all_list_copy.keys()))

        # Wait until the current finishes before continuing.
        if await_home(current):
            all_list[current] = True
        else:
            error_msg = "Homing failed with module: " + str(current)
            print(error_msg)
            return create_response_message(error_msg, 500)

    return create_response(all_list, 200)
