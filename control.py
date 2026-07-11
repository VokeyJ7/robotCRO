import serial 
import sys
import tty
import termios
import subprocess

def get_key():
	fd = sys.stdin.fileno()
	old= termios.tcgetattr(fd) 
	try:
		tty.setraw(fd)
		key = sys.stdin.read(1) 
	finally:
		termios.tcsetattr(fd, termios.TCSADRAIN, old) 
		
	return key
try:
	
	arduino2 = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0043_7583033333835120C1C2-if00", 9600, timeout=1)



	while True:
		key = get_key()
		if key in ['w', 'a', 's', 'd', 'q']:
			arduino2.write(key.encode('utf-8'))
			print(f"sent{key}")
		
		if key == 'e':
			arduino2.write('q'.encode('utf-8'))
			break
			

except:
		subprocess.run([
		"espeak-ng",
		"Motor System Offline"

	])
