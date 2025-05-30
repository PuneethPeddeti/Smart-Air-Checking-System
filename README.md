# Smart Air Checking System
> A compact and intelligent air quality and gas detection system with Bluetooth-based mobile control and live data reporting.

---

##  Table of Contents
- [Overview](#overview)
- [Key Features](#key-features)
- [Hardware Components](#hardware-components)
- [Setup Instructions](#setup-instructions)
- [Bluetooth Commands](#bluetooth-commands)
- [Advantages](#advantages)
- [Future Enhancements](#future-enhancements)
- [Contributors](#contributors)

---

##  Overview

The **Smart Air Checking System** is a compact monitoring device that detects harmful gases like **LPG, Carbon Monoxide (CO), Smoke**, and monitors **air quality** and **ambient temperature** in real time. It uses an **Arduino Nano**, **MQ-series gas sensors**, a **DS18B20 temperature sensor**, and an **HC-05 Bluetooth module** to process and transmit live data to users via a smartphone. It alerts the user when any reading exceeds a defined safe threshold, ensuring a safer indoor environment.

---

##  Key Features

- **Real-Time Gas Monitoring**  
  Detects concentrations of **LPG**, **CO**, **Smoke**, and **Air Pollutants**.

- **Temperature Measurement**  
  Uses DS18B20 sensor for precise ambient temperature readings.

- **Bluetooth Communication**  
  HC-05 module allows wireless data access via mobile.

- **Safety Alerts**  
  Displays warning messages when threshold values are crossed.

- **Command-Based Reporting**  
  Accepts `R` and `A` commands from smartphone to send back real-time values.

---

##  Hardware Components

| Component             | Quantity | Description                                         |
|----------------------|----------|-----------------------------------------------------|
| Arduino Nano         | 1        | Microcontroller to process and control the system   |
| MQ2 Gas Sensor       | 1        | Detects LPG, CO, and smoke                          |
| MQ135 Sensor         | 1        | Measures air quality (NOx, CO2, etc.)               |
| DS18B20 Sensor       | 1        | Digital temperature sensor                          |
| HC-05 Bluetooth      | 1        | Bluetooth module for wireless communication         |
| 4.7kΩ Resistor       | 1        | Pull-up resistor for DS18B20                        |
| Voltage Divider      | 2        | 1kΩ and 2kΩ for HC-05 RX pin protection             |
| Breadboard + Wires   | -        | For connections and prototyping                     |

---

##  Setup Instructions

### 1. Hardware Assembly
- Connect all components as shown in the ['circuit diagram'](https://github.com/PuneethPeddeti/Smart-Air-Checking-System/blob/main/Circuit_Diagram.jpg) .
- Ensure correct orientation of sensors and proper grounding.

### 2. Software Setup
- Open the provided Arduino sketch: [`Smart_Air_Checking_System'](https://github.com/PuneethPeddeti/Smart-Air-Checking-System/tree/main/Smart_Air_Checking_System)
- Upload the code using **Arduino IDE**:
  - Board: `Arduino Nano`
  - Port: Select your COM port
  - Ensure `OneWire` and `DallasTemperature` libraries are installed

---

##  Bluetooth Commands

Use any Bluetooth terminal app or the **Arduino Bluetooth Controller** to communicate.

| Command | Description                             |
|---------|-----------------------------------------|
| `R`     | Reads and returns LPG, CO, and Smoke PPM |
| `A`     | Returns Air Quality (MQ135) and Temp     |

Default HC-05 pairing PIN: `1234` or `0000`

---

##  Advantages

- **Affordable and Compact**  
  Designed using low-cost, widely available sensors and modules.

- **Health & Safety Focused**  
  Helps detect potentially dangerous gas levels early.

- **Customizable Design**  
  Easy to extend with more sensors or communication methods.

- **Educational Value**  
  Ideal for students learning embedded systems and IoT.

---

##  Future Enhancements

- **Cloud Connectivity**: Send data to ThingSpeak, Blynk, or Firebase  
- **OLED Display**: Show readings on a mini local screen  
- **Battery Operation**: Add power management and battery support  
- **Mobile App Integration**: Replace terminal commands with GUI

---

##  Contributors

- ['Puneeth'](https://github.com/PuneethPeddeti) 
