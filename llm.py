from groq import Groq
from google import genai
from google.genai import types
from dotenv import load_dotenv
import os
import serial
import time

load_dotenv(dotenv_path="gemini.env")

api_key = os.environ.get("GEMINI_API_KEY")

client = genai.Client(api_key=api_key)
system_prompt = "You are the brain of a robot that I am constructing. I will provide you signals sent conditionally from arduinos and those signals will be mapped to responses you will give. The signals provided by the arduinos are 0, 1, or 2. If the signal is 0, say 'System Operational'. If the signal is 1, say 'Motor System Down. Attend to Arduino R3 Immediately'. If the signal is 2, say 'Visual System Down. Attend to Arduino 2 Immediately'. Return your answer immediately. Be concise and say exactly what I tell you to. Introduce yourself as C.R.O (Car Robot Operator) a Gemini AI Agent for this Car Robot before you state the status based on the signal."

# arduino 2 is the motor controller, remember its serial address
arduino1 = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0043_34233303439351105041-if00",9600, timeout=1)
arduino2 = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0043_7583033333835120C1C2-if00", 9600, timeout=1)

time.sleep(2)


while True:
	#line = arduino1.readline().decode("utf-8").strip()
	if True:
		response = client.models.generate_content(model="gemini-3-flash-preview", config=types.GenerateContentConfig(system_instruction=system_prompt), contents="The signal is 0.")
		print(response.text)
		if response.text.strip().lower == "systemoperational":
			arduino2.write(b"System Operational\n")
	break
print(arduino1.name, arduino2.name)





