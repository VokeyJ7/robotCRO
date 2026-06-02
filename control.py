import serial 
import sys
import tty
import termios
from pynput import keyboard

# arduino 2 is the motor controller
arduino2 = serial.Serial("/dev/serial/by-id/usb-Arduino__www.arduino.cc__0043_7583033333835120C1C2-if00", 9600, timeout=1)

def get_key():
	fd = sys.stdin.fileno()# gets the file descriptor
	old= termios.tcgetattr(fd) # saves the current terminal settings before anything changes 
	try:
		tty.setraw(fd)# sets the terminal to raw mode and eliminates any buffering so all inputs are sent right away
		key = sys.stdin.read(1) # reads exactly one character input and records it
	finally:
		termios.tcsetattr(fd, termios.TCSADRAIN, old) #restores the terminal back to the normal settings saved in "old" 
		# TDSADRAIN means wait until all output is finished before restoring 
	return key

while True:
	key = get_key()
	if key in ['w', 'a', 's', 'd', 'q']:
		arduino2.write(key.encode('utf-8'))
		print(f"sent{key}")
	
	if key == 'e':
		arduino2.write('q'.encode('utf-8'))
		break
		

