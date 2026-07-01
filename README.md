# CAN-Based Automotive Dashboard using PIC18F4580

A real-time **CAN-Based Automotive Dashboard** implemented in **Embedded C** using the **PIC18F4580** microcontroller. The project simulates communication between multiple Electronic Control Units (ECUs) over the **Controller Area Network (CAN) Bus** to display vehicle parameters such as **Speed, Gear Position, RPM, and Indicator Status** on an LCD dashboard.

The system demonstrates how modern automotive ECUs exchange information using message-based communication while ensuring reliable and efficient real-time data transfer.

---

# Overview

Modern vehicles consist of multiple Electronic Control Units (ECUs), each responsible for specific functionalities such as engine management, transmission control, and dashboard display. These ECUs communicate over the **CAN Bus**, enabling fast and reliable data exchange.

This project simulates an automotive dashboard by implementing a multi-node CAN network where sensor data is transmitted between ECUs and displayed on an LCD in real time.

The project demonstrates the use of:

* Embedded C
* CAN Bus Communication
* PIC18F4580 Microcontroller
* ADC (Analog-to-Digital Converter)
* Timer Interrupts
* LCD Interfacing
* Matrix Keypad
* UART
* Embedded Firmware Development
* Modular Programming

---

# Features

* Multi-ECU CAN Bus Communication
* Real-Time Vehicle Data Display
* Speed Monitoring using ADC
* Gear Position Selection using Matrix Keypad
* RPM Monitoring
* Left & Right Indicator Control
* LCD Dashboard Display
* Timer0 Interrupt-based Indicator Blinking
* Message ID Based CAN Communication
* Modular Embedded Firmware Design

---

# Project Architecture

```
                 +----------------------+
                 |   Speed Sensor (ADC) |
                 +----------+-----------+
                            |
                            |
                            ▼
                  +-------------------+
                  |   ECU 1           |
                  | Speed & Gear Node |
                  +---------+---------+
                            |
                            |
                       CAN Bus Network
                            |
      ------------------------------------------------
      |                                              |
      ▼                                              ▼
+--------------+                           +----------------+
|    ECU 2     |                           |    ECU 3       |
| RPM Node     |                           | Dashboard ECU  |
+--------------+                           +----------------+
                                                    |
                                                    ▼
                                            16x2 LCD Display
                                            Speed
                                            Gear
                                            RPM
                                            Indicators
```

---

# System Working

```
Power ON
    │
    ▼
Initialize PIC18F4580
    │
    ├── Initialize CAN Module
    ├── Initialize ADC
    ├── Initialize LCD
    ├── Initialize Timer0
    └── Initialize GPIO
            │
            ▼
Read Speed Sensor (ADC)
            │
            ▼
Read Gear Position (Keypad)
            │
            ▼
Create CAN Frame
            │
            ▼
Assign Message ID
            │
            ▼
Transmit Data on CAN Bus
            │
            ▼
Dashboard ECU Receives Data
            │
            ▼
Identify Message ID
            │
            ▼
Update LCD Display
            │
            ▼
Timer Interrupt Controls Indicators
            │
            ▼
Repeat Continuously
```

---

# CAN Message IDs

| Message            | ID   |
| ------------------ | ---- |
| Speed              | 0x10 |
| Gear Position      | 0x20 |
| RPM                | 0x30 |
| Engine Temperature | 0x40 |
| Indicator Status   | 0x50 |

---

# Project Structure

```
CAN-Based-Automotive-Dashboard/
│
├── ECU1/
│   ├── ecu1.c
│   ├── ecu1_sensor.c
│   ├── adc.c
│   ├── digital_keypad.c
│
├── Dashboard_ECU/
│   ├── main.c
│   ├── message_handler.c
│   ├── timer0.c
│   ├── clcd.c
│
├── Common/
│   ├── can.c
│   ├── can.h
│   ├── msg_id.h
│   ├── uart.c
│
├── include/
│
├── screenshots/
│
├── documentation/
│
├── README.md
└── LICENSE
```

---

# Hardware Used

* PIC18F4580 Microcontroller
* CAN Transceiver
* 16x2 Character LCD
* Matrix Keypad
* Potentiometer (Speed Simulation)
* LEDs (Indicator Simulation)
* Power Supply

---

# Software Used

* MPLAB X IDE
* XC8 Compiler
* Embedded C
* Proteus (Simulation)

---

# Firmware Flow

1. Initialize peripherals.
2. Read speed using ADC.
3. Read gear using keypad.
4. Package data into CAN frames.
5. Assign appropriate CAN Message ID.
6. Transmit data over CAN Bus.
7. Dashboard ECU receives CAN frames.
8. Decode Message ID.
9. Display Speed, Gear, RPM, and Indicator status.
10. Timer0 interrupt controls indicator blinking.
11. Repeat continuously.

---

# Build

Compile using **MPLAB X IDE** with the **XC8 Compiler**.

---

# Demonstration

Dashboard displays:

```
SP : 45
GR : G3
RPM: 2200
IND: <--
```

---

# Key Embedded Concepts Demonstrated

* Embedded C Programming
* CAN Bus Protocol
* PIC18F4580 Peripheral Programming
* ADC Configuration
* Timer0 Interrupts
* GPIO Programming
* LCD Interfacing
* Matrix Keypad Scanning
* UART Communication
* Interrupt Service Routine (ISR)
* Real-Time Embedded Systems
* Firmware Development
* Automotive ECU Communication

---

# Future Improvements

* CAN FD Support
* OBD-II Integration
* TFT LCD Dashboard
* Fault Diagnostics
* Watchdog Timer
* RTOS-based Task Scheduling
* Data Logging
* Bluetooth/Wi-Fi Connectivity
* Vehicle Health Monitoring
* Automotive Safety Features

---

# Technologies Used

* Embedded C
* PIC18F4580
* CAN Bus
* MPLAB X IDE
* XC8 Compiler
* UART
* ADC
* Timer0
* GPIO
* LCD Interfacing

---

# Author

**Fahed Akil Shaikh**

Bachelor of Engineering (Electronics & Telecommunication)

**Embedded Systems | Firmware Development | Automotive Embedded Systems | CAN Bus | Embedded C | Microcontrollers**
