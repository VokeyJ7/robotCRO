print("Initializing Visual and Motor systems...")
print("System initialization can take up to 3 minutes, thank you for your patience.")


from groq import Groq
from google import genai
from google.genai import types
from dotenv import load_dotenv
import os
import serial
import time
import subprocess

import time


from control import get_key
from camera import capture




load_dotenv(dotenv_path="gemini.env")

api_key = os.environ.get("GEMINI_API_KEY")

client = genai.Client(api_key=api_key)
system_prompt = "You are the brain of a robot that I am constructing. I will proide you prompts. Return your answer immediately. Be concise and say exactly what I tell you to. Introduce yourself as CRO (Car Robot Operator) a Gemini AI Agent for this Car Robot before you state your response to my prompt."



arduino2 = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0043_7583033333835120C1C2-if00", 9600, timeout=1)



def speak(text):
	subprocess.run([
		"espeak-ng",
		text

	])


response =  client.models.generate_content(model="gemini-3-flash-preview", config=types.GenerateContentConfig(system_instruction=system_prompt), contents="The motor and visual systems are operational, say something.")
print("System initialization complete.")
speak(response.text)


lens = subprocess.Popen(
    ["rpicam-hello", "--timeout", "0"],
    stdout=subprocess.DEVNULL,
    stderr=subprocess.DEVNULL
)


chat_mode = False

	
while True:
	
	key = get_key()
	if key == 'r':
		chat_mode = True
		arduino2.write('q'.encode('utf-8'))
		words = input("Write here: ")
		speak(words)
		chat_mode = False
		
	
	
	
	
	if not chat_mode:
		if key in ['w', 'a', 's', 'd', 'q']:
			arduino2.write(key.encode('utf-8'))
			print(f"sent {key}")
	
	if key == "c":
		arduino2.write('q'.encode('utf-8'))
		print(f"sent c")
		image = capture()
		response = client.models.generate_content(model="gemini-3-flash-preview", config=types.GenerateContentConfig(system_instruction=system_prompt), contents=[image, "Describe the image you see concisely. Return an answer immediately."])
		speak(response.text)
		

	if key == 'e':
		arduino2.write('q'.encode('utf-8'))
		lens.terminate()
		speak("Motor, Visual, and Audio systems shutting down.")	
		break
		

	
		


		

	







