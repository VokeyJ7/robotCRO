# C.R.O Robot Car: Arduino-Controlled Robot with AI Status Agent

A robotics project that combines Arduino motor control, Raspberry Pi camera support, serial communication, and an AI-powered status agent. The robot car uses Arduino IDE control code for movement and Python scripts to communicate with microcontrollers and generate system status responses through a Gemini-based LLM agent named C.R.O, short for Car Robot Operator.

## Project Overview

This project is a prototype robot car system designed around three main components:

* Arduino-based motor control
* Raspberry Pi camera preview/control
* Python-based AI status agent using Gemini API and serial communication

The system is being developed as a modular robotics platform where embedded control, computer vision, and AI reasoning can eventually work together.

## Core Features

* Four-wheel robot car movement control
* WASD-style command system
* Arduino serial communication
* Motor system status reporting
* Raspberry Pi camera preview
* Gemini AI agent for robot health/status messages
* Multi-Arduino communication setup
* Future-ready structure for visual processing and intelligent control

## Arduino Motor Control

The Arduino controls four wheels using eight digital output pins.

### Movement Commands

| Command | Action        |
| ------- | ------------- |
| `w`     | Move forward  |
| `s`     | Move backward |
| `a`     | Turn left     |
| `d`     | Turn right    |
| `q`     | Stop          |

### Motor Control Logic

The Arduino code controls each wheel by setting motor driver input pins HIGH or LOW. Separate functions handle:

* Forward motion
* Backward motion
* Left turns
* Right turns
* Stop command

The Arduino listens through serial input and maps keyboard commands to movement functions.

## AI Status Agent

The Python LLM module uses the Gemini API to generate concise robot status responses based on signals from Arduino microcontrollers.

### Signal Mapping

| Signal | AI Status Response                                  |
| ------ | --------------------------------------------------- |
| `0`    | System Operational                                  |
| `1`    | Motor System Down. Attend to Arduino R3 Immediately |
| `2`    | Visual System Down. Attend to Arduino 2 Immediately |

The AI agent introduces itself as:

```text
C.R.O (Car Robot Operator)
```

The goal is to create a simple robotic diagnostic layer where microcontroller signals are converted into human-readable status messages.

## Serial Communication

The Python scripts connect to Arduino boards through serial ports using `pyserial`.

Current setup includes:

* Arduino R3 for motor control
* Second Arduino for visual/system communication
* Baud rate: 9600

The Python controller reads or sends system messages through USB serial paths and can write status updates back to connected microcontrollers.

## Camera System

The robot also includes a Raspberry Pi camera module controlled through Python.

The camera script uses:

* `Picamera2`
* Live preview mode
* Keyboard input to stop the camera preview

This provides a foundation for future computer vision integration.

## Current Architecture

The project contains three major software layers:

### 1. Embedded Control Layer

Implemented in Arduino IDE.

Responsible for:

* Motor pin setup
* Wheel control
* Serial command reading
* Movement execution

### 2. Python Communication Layer

Implemented with Python.

Responsible for:

* Serial communication
* Arduino-to-Arduino coordination
* System message routing

### 3. AI Agent Layer

Implemented with Gemini API.

Responsible for:

* Translating numeric system signals into readable robot diagnostics
* Acting as the robot’s status “brain”
* Providing concise operational feedback

## Technologies Used

* Arduino IDE
* Arduino R3
* Python
* PySerial
* Gemini API
* Raspberry Pi
* Picamera2
* Motor Driver Control
* Serial Communication

## Planned Improvements

Future work may include:

* Live computer vision object detection
* Autonomous navigation
* Obstacle avoidance
* Voice or natural-language robot commands
* LLM-assisted troubleshooting
* Real-time sensor dashboard
* Better multi-Arduino signal handling
* Raylib or web-based robot control interface
* Battery monitoring and safety checks

## Author

Veltman Okey-Ejiowhor

Mechanical Engineering Student | Robotics Builder | AI/ML Developer
