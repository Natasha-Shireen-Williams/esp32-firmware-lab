# Day 5: PWM, MOSFETs and Motor Control

## Concepts Covered

- Pulse Width Modulation (PWM)
- Duty Cycle
- Frequency
- Resolution
- ESP32 LEDC Peripheral
- MOSFET as a power switch
- Low-side switching
- Flyback diode protection

## PWM

PWM controls average power by rapidly switching a GPIO pin between HIGH (3.3V) and LOW (0V).

The device responds to the average energy delivered.

## ESP32 LEDC

The ESP32 contains a dedicated LEDC hardware peripheral that generates PWM signals without continuous CPU involvement.

## MOSFET Driver

The ESP32 GPIO cannot directly power motors or pumps.

A MOSFET is used as a switch:

ESP32 GPIO → MOSFET Gate → Pump Power Control

## Protection

Motors are inductive loads and create voltage spikes when switched OFF.

A flyback diode protects the circuit by providing a path for the stored inductive energy.

## Embedded Architecture

Sensor → Processing → PWM Output → Driver → Actuator