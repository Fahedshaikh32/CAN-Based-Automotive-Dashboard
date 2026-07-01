# CAN-Based Automotive Dashboard using PIC18F4580

A real-time **CAN-Based Automotive Dashboard** developed in **Embedded C** using **PIC18F4580** microcontrollers.

The project simulates communication between multiple Electronic Control Units (ECUs) over a **Controller Area Network (CAN Bus)** to monitor and display vehicle parameters such as **Speed, Gear Position, RPM, and Indicator Status** on an LCD dashboard.

The system demonstrates automotive communication principles used in modern vehicles, where different ECUs exchange information over a shared CAN network instead of using dedicated point-to-point wiring.

---

# Overview

Modern vehicles contain multiple Electronic Control Units (ECUs) responsible for different functions such as engine control, transmission, dashboard, and body electronics.

Instead of connecting every module using separate wires, all ECUs communicate over a **CAN Bus**, making communication faster, reliable, and scalable.

This project simulates a simplified automotive network consisting of multiple ECUs communicating over CAN Bus.

The project demonstrates practical implementation of:

* Embedded C Programming
* CAN Bus Communication
* PIC18F4580 Microcontroller
* Multi-ECU Architecture
* Real-Time Embedded Systems
* LCD Interface
* ADC Interface
* Timer Interrupts
* Matrix Keypad Interface

---

# Features

* Multi-ECU CAN Communication
* Real-Time Dashboard Display
* Vehicle Speed Monitoring
* Gear Position Monitoring
* RPM Monitoring
* Left & Right Indicator Control
* CAN Message ID Based Communication
* LCD Display Interface
* ADC-Based Speed Input
* Matrix Keypad Controlled Gear Selection
* Timer0 Interrupt Driven Indicator Blinking
* Modular Embedded C Design

---

# System Architecture

```
                         +----------------------+
                         |     ECU 1            |
                         |----------------------|
                         | Speed Sensor (ADC)   |
                         | Gear Selection       |
                         +----------+-----------+
                                    |
                                    |
                              CAN Bus Network
                                    |
          ---------------------------------------------------
          |                                                 |
          |                                                 |
+---------+---------+                           +-----------+-----------+
|      ECU 2        |                           |      ECU 3            |
|-------------------|                           |-----------------------|
| RPM Generator     |                           | Dashboard Controller  |
| Indicator Control |                           | LCD Display           |
+---------+---------+                           +-----------+-----------+
          |                                                 |
          +---------------- CAN Messages -------------------+
```

---

# ECU Responsibilities

## ECU 1

Responsible for

* Reading vehicle speed using ADC
* Reading gear selection from Matrix Keypad
* Transmitting Speed over CAN Bus
* Transmitting Gear Position over CAN Bus

---

## ECU 2

Responsible for

* Generating RPM values
* Controlling Left Indicator
* Controlling Right Indicator
* Transmitting RPM Data
* Transmitting Indicator Status over CAN Bus

---

## ECU 3 (Dashboard ECU)

Responsible for

* Receiving CAN Frames
* Identifying CAN Message IDs
* Processing Vehicle Parameters
* Displaying Speed
* Displaying Gear Position
* Displaying RPM
* Displaying Indicator Status
* Timer Interrupt Based Indicator Blinking

---

# Communication Flow

```
Vehicle Speed
      │
      ▼
ADC Reading
      │
      ▼
ECU1
      │
      ▼
CAN Bus
      │
      ▼
Dashboard ECU
      │
      ▼
LCD Display


Gear Selection
      │
      ▼
Matrix Keypad
      │
      ▼
ECU1
      │
      ▼
CAN Bus
      │
      ▼
Dashboard ECU


RPM
      │
      ▼
ECU2
      │
      ▼
CAN Bus
      │
      ▼
Dashboard ECU


Indicator
      │
      ▼
ECU2
      │
      ▼
CAN Bus
      │
      ▼
Dashboard ECU
      │
      ▼
Timer0 ISR
      │
      ▼
LED Blinking
```

---

# CAN Message IDs

| Parameter                       | Message ID |
| ------------------------------- | ---------: |
| Speed                           |       0x10 |
| Gear                            |       0x20 |
| RPM                             |       0x30 |
| Engine Temperature *(Reserved)* |       0x40 |
| Indicator                       |       0x50 |

---

# Project Structure

```
CAN-Based-Automotive-Dashboard/
│
├── ECU1/
│   ├── adc.c
│   ├── ecu1_sensor.c
│   ├── digital_keypad.c
│   ├── can.c
│   └── main.c
│
├── ECU2/
│   ├── rpm.c
│   ├── indicator.c
│   ├── can.c
│   └── main.c
│
├── ECU3/
│   ├── main.c
│   ├── can.c
│   ├── clcd.c
│   ├── timer0.c
│   ├── message_handler.c
│   └── uart.c
│
├── include/
│
├── screenshots/
│
├── Documentation/
│
├── README.md
│
└── LICENSE
```

---

# Working Principle

1. System powers ON.
2. CAN module, LCD, ADC, Timer, and GPIO are initialized.
3. ECU1 reads Speed and Gear.
4. ECU2 generates RPM and Indicator Status.
5. Each ECU sends data using a unique CAN Message ID.
6. Dashboard ECU continuously receives CAN frames.
7. Received message IDs determine which parameter is being updated.
8. LCD displays Speed, Gear, RPM, and Indicator Status.
9. Timer0 ISR controls LED blinking for indicators.

---

# Technologies Used

* Embedded C
* PIC18F4580
* CAN Bus
* MPLAB X IDE
* XC8 Compiler
* ADC
* UART
* Matrix Keypad
* Character LCD
* Timer0 Interrupt
* GPIO

---

# Embedded Concepts Demonstrated

* CAN Bus Communication
* Interrupt Service Routine (ISR)
* ADC Interfacing
* LCD Interfacing
* Matrix Keypad Scanning
* Timer Configuration
* GPIO Programming
* Embedded C Programming
* Real-Time Communication
* Firmware Development
* Modular Programming

---

# Applications

* Automotive Dashboard Systems
* Vehicle Monitoring Systems
* CAN-Based Industrial Networks
* Automotive ECU Communication
* Embedded System Learning
* Firmware Development Projects

---

# Future Improvements

* CAN FD Support
* OBD-II Diagnostics
* Engine Temperature Monitoring
* Fuel Level Monitoring
* TFT Display Interface
* Fault Detection & Diagnostics
* Data Logging to SD Card
* FreeRTOS Integration
* STM32 Port
* Automotive Bootloader Support

---

# Development Tools

* MPLAB X IDE
* XC8 Compiler
* PIC18F4580 Development Board
* CAN Bus Module
* Character LCD
* Matrix Keypad
* Potentiometer (Speed Simulation)

---

# Author

**Fahed Akil Shaikh**

Bachelor of Engineering (Electronics & Telecommunication)

Embedded Systems | Firmware Development | Automotive Embedded Systems | CAN Bus | Embedded C | Linux Programming
