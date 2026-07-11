# 🚗 CRO – Car Robot Operator

CRO (Car Robot Operator) is a **Gemini-powered AI robotic control system** built on a **Raspberry Pi 4 Model B** and an **Arduino**. The Raspberry Pi acts as the robot's brain, handling AI, vision, speech, and user input, while the Arduino controls the motors through serial communication.

## Features

* 🤖 Gemini AI integration
* 🎮 Manual WASD robot control
* 📷 Camera image capture and AI scene description
* 🔊 Voice output through a USB speaker (`espeak-ng`)
* 🔌 Raspberry Pi ↔ Arduino serial communication

## Hardware

* Raspberry Pi 4 Model B
* Arduino (motor controller)
* Raspberry Pi Camera
* USB Speaker
* Robot chassis and motors

## Controls

| Key   | Function                                  |
| ----- | ----------------------------------------- |
| **W** | Forward                                   |
| **A** | Left                                      |
| **S** | Reverse                                   |
| **D** | Right                                     |
| **Q** | Stop                                      |
| **R** | Speak typed text                          |
| **C** | Capture image and have Gemini describe it |
| **E** | Shut down CRO                             |

## Installation

Install the required Python packages:

```bash
pip install google-genai python-dotenv pyserial
```

Create a `gemini.env` file:

```text
GEMINI_API_KEY=your_api_key_here
```

Then run:

```bash
python3 main.py
```

## Architecture

```text
Keyboard
    │
    ▼
Raspberry Pi 4
(AI • Vision • Speech)
    │
Serial
    │
    ▼
Arduino
(Motor Controller)
    │
    ▼
Robot Motors
```

## Author

**Veltman Okey-Ejiowhor Jr.**
