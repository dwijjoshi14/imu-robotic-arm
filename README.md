# IMU Robotic Arm Controller

> STM32 + FreeRTOS + MPU-6050 — gesture-driven 3-DOF servo control with real-time angle filtering

![Platform](https://img.shields.io/badge/Platform-STM32F103-03234B?style=flat-square&logo=stmicroelectronics&logoColor=white)
![RTOS](https://img.shields.io/badge/RTOS-FreeRTOS-003366?style=flat-square)
![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Progress-orange?style=flat-square)

## Overview

Tilt an MPU-6050 IMU and a 3-DOF servo arm mirrors the motion in real time. The firmware runs on STM32F103 under FreeRTOS - sensor reading, angle computation, and servo output each run in dedicated tasks, communicating via queues.

## Architecture

IMU Task (I2C, 200Hz)
│  raw accel + gyro → queue
▼
Filter Task
│  complementary filter → fused angles → queue
▼
Servo Task (PWM, 50Hz)
│  angle → pulse width → 3x SG90 servos
▼
Physical arm movement

## Key features

- Complementary filter — merges accelerometer + gyroscope for drift-free angle estimation
- Sub-10ms end-to-end latency (sensor read → servo response)
- FreeRTOS task isolation — sensor failure doesn't crash servo output
- POSIX simulation layer — full logic testable on Linux before flashing

## Hardware

| Component | Purpose |
|---|---|
| STM32F103C8T6 (Blue Pill) | Main MCU |
| MPU-6050 | 6-axis IMU (I2C) |
| SG90 Servos × 3 | 3-DOF arm joints |
| 5V BEC / LiPo | Servo power rail |

## Build & flash

```bash
# Using PlatformIO
pio run --target upload

# Linux POSIX simulation
make sim && ./build/arm_sim
```

## Status

- [x] FreeRTOS task structure
- [x] I2C MPU-6050 driver
- [x] Complementary filter implementation
- [ ] Servo calibration & end-stop limits
- [ ] Serial telemetry / debug overlay
