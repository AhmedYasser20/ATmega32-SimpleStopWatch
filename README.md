# Stop Watch System using ATmega32

This GitHub repository contains the code and documentation for a Stop Watch system implemented on an ATmega32 Microcontroller. The system incorporates the following specifications:

## Specifications

1. **Microcontroller**: ATmega32 with a clock frequency of 1 MHz.
2. **Timer Configuration**: Timer1 in ATmega32 is configured with CTC mode to measure the Stop Watch time.
3. **Display**: Six Common Anode 7-segment displays are employed.
4. **Multiplexing**: Multiplexing is employed to control all 7-segments using a single 7447 decoder and NPN BJT transistors for enable/disable control.
5. **Decoder Connection**: The 7447 decoder is connected to the first 4 pins of PORTC.
6. **Enable/Disable Pins**: The first 6 pins in PORTA are used for enabling/disabling the six 7-segments.
7. **Start**: The Stop Watch starts counting as soon as power is connected to the MCU.
8. **Reset**: An External Interrupt (INT0) with a falling edge is configured. A push button with an internal pull-up resistor can be used to reset the Stop Watch time.
9. **Pause**: External Interrupt (INT1) is configured with a rising edge. A push button with an external pull-down resistor can be used to pause the Stop Watch time.
10. **Resume**: External Interrupt (INT2) is configured with a falling edge. A push button with an internal pull-up resistor can be used to resume the Stop Watch time.
11. **Stop LED Indicators**: Added LED indicators to visually indicate the state of the stopwatch (running, paused, or stopped).
12. **Count Up and Count Down Enables**: Implemented count-up and count-down functionality to allow the user to choose the stopwatch mode.

## Usage

Follow these steps to use the Stop Watch system:

1. **Clone the Repository**: Clone this repository to your local machine:

    ```bash
    git clone https://github.com/AhmedYasser20/ATmega32-SimpleStopWatch.git
    ```

2. **Upload Code**: Upload the provided code to your ATmega32 microcontroller using your preferred AVR programming software (e.g., Atmel Studio).

3. **Hardware Connections**: Ensure that you have made the necessary hardware connections as specified in the project documentation.

4. **Power On**: Connect power to the ATmega32. The Stop Watch will start counting automatically.

5. **Reset**: To reset the Stop Watch, press the button connected to the INT0 pin.

6. **Pause/Resume**: To pause the Stop Watch, press the button connected to the INT1 pin. To resume, press the button connected to the INT2 pin.

7. **Choose Stopwatch Mode**: Use the count-up and count-down enables to select the desired stopwatch mode.

## Screenshots
![image](https://github.com/AhmedYasser20/ATmega32-SimpleStopWatch/assets/93765400/f46ff8f2-b7fb-40ba-b273-89c7c6a287cc)


