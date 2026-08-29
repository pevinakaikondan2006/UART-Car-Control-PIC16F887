# UART-Based Car Control System Using PIC16F887

A microcontroller-based vehicle control system that receives movement commands through UART communication and controls DC motors accordingly. An LCD provides real-time feedback of the vehicle's current movement state.

## Project Overview

This project demonstrates the integration of a PIC16F887 microcontroller with UART communication, motor control and LCD interfacing.

The system receives commands from a UART terminal and translates them into motor-control signals for forward, reverse, left, right and stop operations.

## System Architecture

```text
             UART TERMINAL
                   |
                   v
          +------------------+
          |    PIC16F887     |
          |                  |
          | UART Receiver    |
          | Command Logic    |
          +--------+---------+
                   |
            +------+------+
            |             |
            v             v
     L293D Motor       16x2 LCD
       Driver        Status Display
            |
            v
        DC Motors
Objectives
Implement UART communication using PIC16F887.
Receive and decode movement commands.
Control motor direction using GPIO outputs.
Interface a 16x2 LCD for status indication.
Develop firmware using Embedded C.
Design and verify the system using Proteus simulation.
## UART Control Commands

| Command | Operation | LCD Display |
|---------|-----------|-------------|
| `F` / `f` | Forward | FORWARD |
| `R` | Reverse | REVERSE |
| `r` | Right | RIGHT |
| `l` | Left | LEFT |
| `S` / `s` | Stop | STOP |
Motor Control Logic
Forward
 RC0 = 1
 RC1 = 0
 RC2 = 1
 RC3 = 0
Reverse
 RC0 = 0
 RC1 = 1
 RC2 = 0
 RC3 = 1
Right
 RC0 = 0
 RC1 = 1
 RC2 = 1
 RC3 = 0
Left
 RC0 = 1
 RC1 = 0
 RC2 = 0
 RC3 = 1
Stop
 RC0 = 0
 RC1 = 0
 RC2 = 0
 RC3 = 0
Proteus Simulation
The complete vehicle control system was designed and tested using Proteus simulation.
Circuit Schematic
�
The simulation includes the microcontroller, UART terminal, L293D motor driver, DC motors and LCD display.
Hardware and Software
 Microcontroller
 PIC16F887
 Communication
bUART
 Motor Control
 L293D Motor Driver
 DC Motors
 Display
 16x2 LCD
 Programming
 Embedded C
Development and Simulation Tools
 MPLAB
 Proteus
 Key Concepts Demonstrated
 Embedded C programming
 PIC microcontroller programming
 UART serial communication
 GPIO control
 LCD interfacing
 Motor-control logic
 Serial command processing
 Embedded-system simulation
 Hardware-software integration
Project Workflow
UART Command
     |
     v
PIC16F887 UART Receiver
     |
     v
Command Identification
     |
     +----> Forward
     |
     +----> Reverse
     |
     +----> Left
     |
     +----> Right
     |
     +----> Stop
     |
     v
Motor Driver
     |
     v
DC Motor Control

        +
        |
        v
   LCD Status
Future Improvements
 Bluetooth-based vehicle control
 ESP32-based wireless control
 Mobile application control
 Ultrasonic obstacle detection
 PWM-based motor speed control
 Autonomous navigation
 IoT-based vehicle monitoring
Skills Demonstrated
Programming: Embedded C, C
Microcontrollers: PIC16F887
Communication: UART
Embedded Systems: GPIO, LCD interfacing, motor control
Tools: MPLAB, Proteus
Author
Pevina K
B.E. Electronics and Communication Engineering
Government College of Engineering Srirangam, Trichy
Areas of Interest
Embedded Systems | IoT | Automotive Electronics | Microcontrollers | VLSI