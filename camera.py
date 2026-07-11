from time import sleep 
import time
from PIL import Image
import subprocess

def visuals():
	status = True
	

	lens = subprocess.Popen([
		"rpicam-hello",
		"--timeout", "0"
	
	])
	
	return lens
			
			
def capture():
	
	subprocess.run([
		"rpicam-still", "-o", "scene.jpg",
		"--width", "640",
		"--height", "480",
		"--timeout", "500"

	])
			
			
	image = Image.open("scene.jpg")
	return image
		

