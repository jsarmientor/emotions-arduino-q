from arduino.app_utils import *
from arduino.app_bricks.web_ui import WebUI

ui = WebUI()

def handle_emotion(client, data):
    emotion = data.get("emotion")
    if emotion:
        print(f"Received emotion: {emotion}")
        Bridge.call("set_emotion", emotion)

ui.on_message("set_emotion", handle_emotion)

App.run()

