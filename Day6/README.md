# Adaptive Headlight Brightness Controller

This project is an Arduino-based prototype for an adaptive headlight brightness controller. It demonstrates a simple sensor-driven lighting system that responds to ambient darkness and the distance of an object ahead, making it a practical proof of concept for reducing glare from overly bright vehicle lights.

The circuit uses an `Arduino Nano`, an `LDR`, an `ultrasonic sensor`, and a `red LED` on a breadboard. The LED stands in for a vehicle headlight, while the sensors decide when the light should turn on and how bright it should be.

The build uses:
- An `Arduino Nano`
- An `LDR` or standard photoresistor module to detect ambient light
- An `ultrasonic sensor` such as the `HC-SR04` to measure distance
- A `red LED` used as a stand-in for the headlight
- A breadboard and jumper wires for connections

## Wiring / Pinout

The sketch uses the following Arduino Nano pins:

- `D9` -> `TRIG` pin of the ultrasonic sensor
- `D10` -> `ECHO` pin of the ultrasonic sensor, such as an `HC-SR04`
- `D3` -> `LED` positive leg through a current-limiting resistor
- `A0` -> `LDR` output from the voltage divider or photoresistor module
- `5V` -> Power for the sensor circuit
- `GND` -> Common ground for all components

For the LDR, use it as part of a voltage divider so the Arduino can read changing light levels on `A0`.

## How It Works

The sketch continuously reads two inputs:

1. `LDR sensor`
   - Measures the surrounding light level using `analogRead()`.
   - If the environment is bright enough, the LED is turned off.
   - If it is dark, the system becomes active.

2. `Ultrasonic sensor`
   - Measures the distance to an object in front of the sensor.
   - The Arduino sends a trigger pulse and reads the echo time.
   - That time is converted into distance in centimeters.

When the environment is dark, the Arduino uses the distance reading to control the LED brightness with PWM:

- A closer object results in a brighter LED
- A farther object results in a dimmer LED
- The brightness is limited to a valid PWM range using `constrain()`

This makes the circuit a good prototype for an adaptive lighting system. In a real vehicle setup, the same concept can be tuned further so the light output behaves as needed for safety and visibility.

## Pin Connections

According to the sketch:

- `TRIG_PIN` -> Arduino Nano pin `D9`
- `ECHO_PIN` -> Arduino Nano pin `D10`
- `LED_PIN` -> Arduino Nano pin `D3`
- `LDR_PIN` -> Arduino Nano analog pin `A0`

## Circuit Overview

### LDR

The LDR is connected as an analog input so the Arduino can detect whether the area is bright or dark.

### Ultrasonic Sensor

The ultrasonic sensor sends out sound pulses and measures the reflected echo to estimate distance.

### LED

The red LED represents the headlight output. Its brightness is controlled using PWM from pin `D3`.

## Code Logic

The main loop does the following:

1. Reads the ambient light from the LDR
2. Sends a trigger pulse to the ultrasonic sensor
3. Measures the returned echo pulse
4. Converts the echo duration into distance
5. If it is dark, calculates LED brightness based on distance
6. Outputs the brightness to the LED using `analogWrite()`
7. Prints values to the Serial Monitor for debugging

## Serial Monitor Output

The sketch runs at `9600 baud` and prints:

- LDR value
- Distance in centimeters
- LED brightness value

This is useful for checking whether the sensor readings are working correctly during testing.

## Suggested Use

This prototype can be used as a base for:

- Automatic vehicle lighting
- Headlight dimming systems
- Smart road safety demonstrations
- Sensor-based PWM brightness control

## Notes

- The current sketch uses a simple threshold for the LDR.
- The ultrasonic-to-brightness mapping can be adjusted to match a different use case.
- For a real headlight system, the brightness logic should be tuned carefully for safety and reliability.

## File

- Main sketch: `Day6.ino`
