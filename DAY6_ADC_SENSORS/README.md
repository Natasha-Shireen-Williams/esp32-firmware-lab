# Day 6: ESP32 ADC and Sensor Interfacing

## Overview

In Day 6, I learned how ESP32 reads real-world analog sensors using its ADC (Analog to Digital Converter) and how raw sensor data is processed before making decisions in an embedded system.

---

## ADC (Analog to Digital Converter)

The ESP32 ADC converts continuous analog voltage signals from sensors into digital values that the microcontroller can process.

Example:

```
Sensor Voltage → ADC Value → Firmware Decision
```

The ESP32 uses a 12-bit ADC:

```
0 - 4095 ADC values
```

---

## ADC Resolution and Saturation

ADC resolution determines how accurately voltage can be measured.

For a 12-bit ADC:

```
2^12 = 4096 levels
```

If the input voltage exceeds the ADC measurement range, the ADC reaches its maximum value:

```
ADC = 4095
```

This condition is called ADC saturation.

---

## ADC Attenuation

ESP32 provides ADC attenuation to increase the measurable input voltage range.

Without attenuation, the ADC can only measure a smaller voltage range.

By configuring attenuation:

```cpp
analogSetPinAttenuation(pin, ADC_11db);
```

the ADC can safely measure higher sensor voltages.

Attenuation changes the ADC measurement range, not the ESP32 operating voltage.

---

## Sensor Calibration

Raw ADC values do not directly represent physical measurements.

Calibration converts raw values into meaningful units.

Example:

```
Raw ADC Value → Moisture Percentage
```

For the soil moisture sensor:

```
Dry Soil → Lower Moisture Percentage

Wet Soil → Higher Moisture Percentage
```

---

## Sensor Filtering

Sensor readings can contain noise and small fluctuations.

Filtering techniques such as moving averages improve stability by combining multiple readings into one reliable value.

```
Multiple Sensor Readings

↓

Average

↓

Stable Output
```

---

## Hysteresis

Hysteresis prevents rapid ON/OFF switching of actuators.

Example:

```
Pump ON  → Moisture below 40%

Pump OFF → Moisture above 50%
```

The gap between these values prevents unnecessary switching.

---

## Sensor Processing Pipeline

A typical embedded sensor system follows:

```
Sensor

↓

ADC Conversion

↓

Filtering

↓

Calibration

↓

Decision Logic

↓

Actuator Control
```

---

## Practical Implementation

Implemented ESP32 ADC code to:

- Read analog sensor values
- Convert raw ADC readings into moisture percentage
- Apply calibration limits
- Display sensor data through Serial Monitor

---

## Concepts Learned

- ESP32 ADC
- Analog sensor interfacing
- ADC resolution
- ADC saturation
- Sensor calibration
- Data filtering
- Hysteresis-based control
- Embedded sensor processing