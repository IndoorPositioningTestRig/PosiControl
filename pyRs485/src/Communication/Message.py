class Message:
    def __init__(self):
        self.sender = 0
        self.target = 0
        self.message_type = 0
        self.length = 0
        self.data = ""

    def to_string(self):
        return "Message: (sender: {}, target: {}, type: {}, length: {}, data: {})"\
            .format(self.sender, self.target, self.message_type, self.length, self.data)

    def print(self):
        print(self.to_string())
