# Autonomous-Mobile-Robot-Control-System
Embedded mobile robotic platform featuring autonomous navigation, obstacle avoidance, light tracking and infrared remote control.


![Project Status](https://img.shields.io/badge/Status-Completed-success)
![Platform](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-C++-orange)
![PCB](https://img.shields.io/badge/PCB-Custom%20Designed-success)
![License](https://img.shields.io/badge/License-MIT-green)

---

# Project Overview

This project presents the design and development of an embedded mobile robotic platform capable of operating in both manual and autonomous modes.

The robot integrates multiple sensing technologies and embedded control algorithms to perform autonomous navigation, obstacle avoidance and light source tracking while also supporting wireless infrared remote control.

The project was developed following a complete engineering workflow, from circuit prototyping and firmware development to PCB design, assembly and system integration.

---

# Project Objectives

- Design a fully functional embedded robotic platform
- Develop a custom PCB
- Integrate multiple sensing technologies
- Implement autonomous navigation algorithms
- Develop wireless infrared remote control
- Implement obstacle avoidance
- Implement light tracking
- Integrate hardware and embedded software

---

# Main Features

- Autonomous obstacle avoidance
- Light source tracking
- Wireless infrared remote control
- DC motor control
- Embedded decision logic
- Real-time sensor acquisition
- Custom PCB
- Arduino-based embedded firmware
- Modular software architecture

---

# Development Process

The project followed an iterative engineering development process.

## Phase 1 — Initial Prototype

The first version was assembled on a breadboard to validate:

- Motor control
- Infrared communication
- Ultrasonic sensor
- Light sensors
- Embedded firmware

📷 **Breadboard Prototype** 

<img width="960" height="1280" alt="Placa_1" src="https://github.com/user-attachments/assets/78789232-1eca-46e0-9a6d-99f3607baeeb" />


---

## Phase 2 — PCB Design

After validating the prototype, a custom PCB was designed using Autodesk Eagle.

The PCB integrates all sensors, connectors and control electronics required by the robot.

📷 **PCB Schematic**

<img width="1333" height="743" alt="Esquema_SCH_final" src="https://github.com/user-attachments/assets/8dfbe59e-de4a-414e-bf28-9803b457ff97" />

📷 **PCB Layout**

<img width="1402" height="790" alt="BRD_final" src="https://github.com/user-attachments/assets/2c0c99b8-72a6-4a7b-b59e-840961181770" />

---

## Phase 3 — PCB Assembly

The PCB was manufactured and assembled by soldering all electronic components.

The board was then integrated into the mobile robot chassis.

📷 **PCB Assembly Image**

<img width="805" height="495" alt="image" src="https://github.com/user-attachments/assets/b102be25-b45b-4ab6-89b1-26a6b62b1acc" />

---

## Phase 4 — Final Robot

The completed platform integrates:

- Arduino
- Motor Driver
- Infrared Receiver
- Ultrasonic Sensor
- Light Sensors
- Custom PCB
- DC Motors
- Battery Pack

📷 **Robot Image**

<img width="1280" height="960" alt="Robo_2" src="https://github.com/user-attachments/assets/7682f1ef-af93-4551-bc1f-c61378eba486" />


---

# Hardware

| Component | Purpose |
|------------|---------|
| Arduino | Main controller |
| DC Motors | Robot locomotion |
| Motor Shield | Motor control |
| Ultrasonic Sensor | Obstacle detection |
| Infrared Receiver | Wireless remote control |
| Photodiodes | Light tracking |
| Custom PCB | Hardware integration |
| Battery Pack | Power supply |

---

# Software

- Arduino IDE
- C++
- Embedded Programming
- Motor Control
- Sensor Processing
- Decision Logic

---

# System Architecture

```text
                  Infrared Remote
                         │
                         ▼
                 Infrared Receiver
                         │
                         ▼
                 Arduino Controller
                         │
       ┌─────────────────┼─────────────────┐
       │                 │                 │
       ▼                 ▼                 ▼
Ultrasonic Sensor   Light Sensors    Motor Driver
       │                                   │
       └─────────────────┬─────────────────┘
                         ▼
                     DC Motors
                         │
                         ▼
                  Mobile Robot Motion
```

---

# Robot Operating Modes

## Manual Mode

The robot is controlled using an infrared remote controller.

The user can:

- Move forward
- Move backward
- Turn left
- Turn right
- Stop

---

## Autonomous Mode

The robot continuously measures the surrounding environment using the ultrasonic sensor.

When an obstacle is detected, the embedded control algorithm selects a new direction to avoid collisions.

---

## Light Tracking Mode

The robot uses two photodiodes to detect the direction of a light source.

The embedded firmware compares both sensor readings and adjusts the robot trajectory accordingly.

---

# Software Architecture

The firmware is organised into multiple functional modules:

- Motor Control
- Obstacle Detection
- Light Tracking
- Infrared Communication
- Robot Motion
- Decision Logic

---

# PCB Design

A dedicated PCB was designed using Autodesk Eagle to improve:

- Reliability
- Mechanical robustness
- Wiring organization
- Ease of assembly

📷 **Eagle Schematic**

<img width="1333" height="743" alt="Esquema_SCH_final" src="https://github.com/user-attachments/assets/6be910ce-fd69-4c73-b736-cea0588bf036" />


📷 **PCB Routing**

<img width="1402" height="790" alt="BRD_final" src="https://github.com/user-attachments/assets/9157d781-1645-4c06-8e0a-24f09aba363c" />

---

# Results

The final platform successfully demonstrates:

- Autonomous navigation
- Wireless robot control
- Obstacle avoidance
- Light source tracking
- Embedded software integration
- PCB design and assembly
- Hardware/software integration

---

# Engineering Skills Demonstrated

- Embedded Systems
- Mobile Robotics
- Arduino Programming
- PCB Design
- Schematic Design
- Sensor Integration
- Infrared Communication
- Motor Control
- Embedded Debugging
- Electronics Assembly
- Hardware Integration
- Autonomous Navigation

---

# Challenges

Several engineering challenges were encountered during development:

- Sensor calibration
- Noise filtering
- Infrared communication reliability
- Motor synchronization
- PCB debugging
- Embedded software integration

These challenges were progressively solved through testing, debugging and iterative hardware improvements.

---

# Future Improvements

Possible future developments include:

- Bluetooth control
- Wi-Fi communication
- PID motor control
- Wheel encoders
- Closed-loop navigation
- SLAM algorithms
- Camera vision
- Object detection
- ROS integration

---


# License

This project is licensed under the MIT License.

---

# Author's

**Tomás Ferreira**
**Adriana Pires**

Electrical & Telecommunications Engineers

**Areas of Interest**

- Industrial Automation
- Embedded Systems
- Robotics
- Industrial Electronics
- Control Engineering
- Industry 4.0

Feel free to explore my other engineering projects and connect with me on LinkedIn.

## Contact
- Email: ferreiratomas994@gmail.com
- Outlkook tomasff52@ua.pt
- LinkedIn: (https://www.linkedin.com/in/tomas-ferreira-52635a2b8/?isSelfProfile=true)

