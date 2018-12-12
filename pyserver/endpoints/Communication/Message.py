class Message:
    def __init__(self):
        self.sender = 0
        self.target = 0
        self.message_type = 0
        self.length = 0
        self.data: bytes = None
