# Digital-Voltmeter-Using-8051-Microcontroller

# Digital Voltmeter using 8051 Microcontroller

This project implements a Digital Voltmeter using the 8051 microcontroller (AT89C51), an ADC, and a 16x2 LCD display. The voltmeter reads analog input voltages, converts them using the ADC, and displays the voltage value on an LCD screen. The project includes:

- A working embedded C program
- HEX file generation using Keil µVision
- Successful Proteus simulation
- Physical implementation using hardware components

---

## Hardware Used

- AT89C51 Microcontroller (8051)
- 16x2 LCD Display (mapped to `P0`, control on `P2.0`, `P2.1`)
- ADC0804 (or similar) for analog-to-digital conversion
- Voltage Divider Circuit (for ADC input scaling)
- 7-segment display (optional or used as input visual indicator)
- Power supply & basic components (resistors, capacitors, etc.)

---

## Software & Tools

- Keil µVision: Code compilation and HEX file generation
- Proteus: Circuit simulation and validation
- 8051 C Compiler: Embedded code development in C

---

## Features

- Reads analog voltage input through ADC
- Converts voltage to digital value and calculates actual voltage
- Displays voltage value on 16x2 LCD in the format `x.xx Volts`
- Simulated and tested successfully on Proteus and hardware

---

## File Structure

| File                | Description                                |
|---------------------|--------------------------------------------|
| `voltmeter.c`       | Main embedded C source code                |
| `voltmeter.hex`     | HEX file for flashing to 8051 (from Keil)  |
| `voltmeter.pdsprj`  | Proteus simulation project file            |
| `README.md`         | Project documentation (this file)          |

---

## How It Works

1. ADC continuously samples the analog voltage input (through port `P3`)
2. The value is converted into a digital voltage using `val = dat * 0.02`
3. The float value is scaled and formatted to `x.xx`
4. Voltage is displayed on LCD using `lcd = P0`, `rs = P2.0`, `e = P2.1`

---

## LCD Display Output


