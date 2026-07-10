<div align="center">

# 🚗 CAN-Based Automotive Dashboard

### Multi-ECU Real-Time Vehicle Dashboard using PIC18F4580 & CAN Bus

![License](https://img.shields.io/badge/License-MIT-green.svg)
![Language](https://img.shields.io/badge/Language-Embedded%20C-blue.svg)
![Platform](https://img.shields.io/badge/MCU-PIC18F4580-orange.svg)
![Protocol](https://img.shields.io/badge/Protocol-CAN%20Bus-red.svg)
![IDE](https://img.shields.io/badge/IDE-MPLAB%20X-informational.svg)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)

A three-node embedded system that simulates how modern vehicles use CAN Bus
to let independent Electronic Control Units (ECUs) share data — instead of
wiring every sensor directly to a central unit.

[Overview](#-overview) •
[Features](#-features) •
[Architecture](#-system-architecture) •
[Hardware](#-hardware-used) •
[Getting Started](#-getting-started) •
[Demo](#-hardware-demonstration)

</div>

---

## 📖 Overview

Modern vehicles contain dozens of Electronic Control Units (ECUs) — for the
engine, transmission, dashboard, body electronics, and more. Rather than
wiring each one directly to every other, they share a single two-wire **CAN
Bus**, exchanging only the data each module needs.

This project reproduces that architecture at a small scale using **three
PIC18F4580 microcontrollers**, each acting as an independent ECU, connected
over a real CAN Bus using **MCP2551 transceivers**. Together they acquire
speed, gear, RPM, and indicator inputs, exchange them as CAN frames, and
render them live on a dashboard LCD.

| ECU | Role |
|---|---|
| **ECU-1** | Reads vehicle speed (ADC) and gear position (keypad); transmits over CAN |
| **ECU-2** | Reads engine RPM (ADC) and indicator switches; transmits over CAN |
| **ECU-3** | Receives all CAN frames, decodes them, and drives the dashboard LCD + indicator LEDs |

---

## ✨ Features

- 🔗 Real-time multi-ECU communication over CAN Bus
- 🎚️ Vehicle speed acquisition via ADC
- ⚙️ Gear selection via 4×4 matrix keypad
- 🔄 Engine RPM acquisition via ADC
- 💡 Left/right indicator monitoring and control
- 🆔 Message-ID-based CAN communication (no polling required)
- 📟 Live 16×2 LCD dashboard display
- ⏱️ Timer0 interrupt-driven indicator blinking
- 🧩 Modular Embedded C firmware — separate drivers per peripheral, per ECU
- 📈 Scalable design — new ECUs/parameters can be added without touching existing nodes

---

## 🏗️ System Architecture

<p align="center">
  <img src="Images/Block Diagram.png" alt="System Block Diagram" width="850">
</p>

```
                    ┌────────────────────┐
                    │       ECU-1        │
                    │  Speed & Gear ECU   │
                    │  (ADC + Keypad)     │
                    └──────────┬──────────┘
                               │
                          CAN Bus (CANH/CANL)
                               │
        ┌──────────────────────┴──────────────────────┐
        │                                              │
┌───────┴────────┐                          ┌──────────┴─────────┐
│     ECU-2       │                          │       ECU-3        │
│ RPM & Indicator  │                          │   Dashboard ECU     │
│  ECU (ADC + I/O) │                          │ (LCD + Indicators)  │
└──────────────────┘                          └─────────────────────┘
```

Each ECU is built around a PIC18F4580 with its own MCP2551 CAN transceiver.
The bus is terminated with 120 Ω resistors at both ends per the CAN
physical-layer specification.

---

## 🔌 Circuit Diagram

<p align="center">
  <img src="Images/Circuit Diagram.png" alt="Circuit Diagram" width="850">
</p>

---

## 🧠 ECU Responsibilities

<details>
<summary><b>ECU-1 — Speed & Gear ECU</b></summary>

- Reads vehicle speed via ADC (potentiometer input)
- Reads gear selection from a 4×4 matrix keypad
- Transmits Speed (`0x10`) and Gear Position (`0x20`) over CAN

</details>

<details>
<summary><b>ECU-2 — RPM & Indicator ECU</b></summary>

- Reads engine RPM via ADC (potentiometer input)
- Monitors left and right indicator switches
- Transmits RPM (`0x30`) and Indicator Status (`0x50`) over CAN

</details>

<details>
<summary><b>ECU-3 — Dashboard ECU</b></summary>

- Receives all CAN frames via MCP2551
- Decodes incoming message IDs
- Updates the 16×2 LCD with Speed, Gear, RPM, and Indicator status
- Drives indicator LEDs using Timer0-interrupt-based blinking

</details>

---

## 🆔 CAN Message IDs

| Message ID (HEX) | Parameter | Transmitted By |
|---|---|---|
| `0x10` | Vehicle Speed | ECU-1 |
| `0x20` | Gear Position | ECU-1 |
| `0x30` | Engine RPM | ECU-2 |
| `0x40` | Reserved (future expansion) | — |
| `0x50` | Indicator Status | ECU-2 |

---

## 🔁 Communication Flow

```
Speed (Potentiometer) → ADC → ECU-1 → CAN Bus → ECU-3 → LCD
Gear   (Matrix Keypad) →       ECU-1 → CAN Bus → ECU-3 → LCD
RPM    (Potentiometer) → ADC → ECU-2 → CAN Bus → ECU-3 → LCD
Indicators (Switches)  →       ECU-2 → CAN Bus → ECU-3 → Timer0 ISR → LEDs
```

---

## 📁 Repository Structure

```
CAN-Based-Automotive-Dashboard/
│
├── ECU1.X/                  # Speed & Gear ECU firmware (MPLAB X project)
│   ├── adc.c / adc.h
│   ├── can.c / can.h
│   ├── clcd.c / clcd.h
│   ├── digital_keypad.c / digital_keypad.h
│   ├── ecu1.c
│   ├── ecu1_sensor.c / ecu1_sensor.h
│   ├── msg_id.h
│   └── uart.c / uart.h
│
├── ECU2.X/                  # RPM & Indicator ECU firmware
│   ├── adc.c / adc.h
│   ├── can.c / can.h
│   ├── digital_keypad.c / digital_keypad.h
│   ├── ecu2_sensor.c / ecu2_sensor.h
│   ├── ecu_2_main.c
│   ├── msg_id.h
│   ├── ssd_display.c / ssd_display.h
│   └── uart.c / uart.h
│
├── ECU3.X/                  # Dashboard ECU firmware
│   ├── can.c / can.h
│   ├── clcd.c / clcd.h
│   ├── main.c
│   ├── message_handler.c / message_handler.h
│   ├── msg_id.h
│   ├── timer0.c / timer0.h
│   └── uart.c / uart.h
│
├── Images/                  # Block/circuit diagrams and hardware photos
├── Videos/                  # Demo.mp4 And The_Architecture_Shift__Engineering_a_CAN-Based_Dashboard.mp4 — full system demonstration
├── .gitignore
├── LICENSE                  # MIT License
└── README.md
```

---

## 🛠️ Hardware Used

| Component | Purpose |
|---|---|
| PIC18F4580 (×3) | Core microcontroller for each ECU |
| MCP2551 (×3) | CAN transceiver — differential CANH/CANL signaling |
| 16×2 Character LCD | Dashboard display |
| 4×4 Matrix Keypad | Gear selection input |
| Potentiometers (×2) | Simulated speed and RPM analog inputs |
| Push Buttons | Left/right indicator switches |
| LEDs | Left/right indicator outputs |
| 8 MHz Crystal Oscillator | System clock for each MCU |
| 7805 Voltage Regulator | Regulated +5V supply |
| 120 Ω Resistors (×2) | CAN Bus termination |

## 💻 Software & Tools

- **Embedded C** — firmware language
- **MPLAB X IDE** — development environment
- **MPLAB XC8 Compiler** — code generation for PIC18F4580
- **Git & GitHub** — version control

---

## 🚀 Getting Started

### Prerequisites
- [MPLAB X IDE](https://www.microchip.com/mplabx) installed
- [XC8 Compiler](https://www.microchip.com/xc8) installed
- A PIC18F4580 programmer/debugger (e.g. PICkit, ICD)
- 3× PIC18F4580 boards wired per the [circuit diagram](Images/Circuit%20Diagram.png), sharing a common CAN bus

### Build & Flash
```bash
git clone https://github.com/Fahedshaikh32/CAN-Based-Automotive-Dashboard.git
```
1. Open `ECU1.X`, `ECU2.X`, and `ECU3.X` individually in MPLAB X IDE.
2. Build each project (Clean and Build).
3. Flash each `.hex` output to its corresponding PIC18F4580 board.
4. Power on all three boards on the shared CAN bus — the dashboard ECU (ECU-3) will begin displaying live data on the LCD.

---

## 🎥 Hardware Demonstration

<p align="center">
  <img src="Images/Full hardware setup.jpg" alt="Full Hardware Setup" width="45%">
  &nbsp;
  <img src="Images/PIC18 rydolab Development board.jpg" alt="Development Board" width="45%">
</p>

📹 **[Watch the full demo video](Videos/Demo.mp4)** — system startup, live speed/RPM/gear updates, and indicator control.

---

## 🔮 Future Improvements

- [ ] CAN FD support
- [ ] OBD-II diagnostics integration
- [ ] Engine temperature & fuel level monitoring
- [ ] TFT display upgrade
- [ ] Fault detection & diagnostic trouble codes
- [ ] SD card / EEPROM data logging
- [ ] FreeRTOS-based architecture
- [ ] STM32 port

---

## 🧩 Skills & Concepts Demonstrated

`Embedded C` `CAN Bus / ECAN Peripheral` `ADC Interfacing` `LCD Interfacing`
`Matrix Keypad Scanning` `Timer Interrupts` `GPIO Programming`
`Modular Firmware Design` `Distributed Embedded Systems` `Real-Time Communication`

---

## 👤 Author

**Fahed Akil Shaikh**
Bachelor of Engineering — Electronics & Telecommunication Engineering

Embedded Systems • Firmware Development • CAN Bus • Automotive Embedded Systems

---

## 📄 License

This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for details.

<div align="center">

⭐ If you found this project useful, consider giving it a star!

</div>
