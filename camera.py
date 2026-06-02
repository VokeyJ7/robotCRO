from picamera2 import Picamera2, Preview
from time import sleep 
import time

camera = Picamera2()
camera_config = camera.create_preview_configuration()
camera.configure(camera_config)
camera.start_preview(Preview.QTGL)

while True:
	camera.start()
	cmd = input(">")
	if cmd == "e":
		camera.stop()
		break
		
		

