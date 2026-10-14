# Arduino Parking Sensor

Ultrasonic obstacle detector that beeps faster as an object gets closer, like a car parking sensor.

## How it works
- An **HC-SR04** ultrasonic sensor measures the distance (time of flight of the echo).
- A **piezo buzzer** beeps with a rate that depends on the distance:

| Distance | Behaviour |
|---|---|
| 70 – 110 cm | slow beep |
| 50 – 70 cm | medium beep |
| 35 – 50 cm | fast beep |
| < 35 cm | continuous tone |

- To avoid annoying beeping when nothing moves, the buzzer stops after **5 seconds** and only restarts when the measured distance changes by more than 5 cm.

## Hardware & wiring
| Component | Arduino pin |
|---|---|
| HC-SR04 ECHO | D2 |
| HC-SR04 TRIG | D3 |
| Piezo buzzer (+) | D12 |
| VCC / GND | 5V / GND |

## Photos
<!-- Add a photo of the prototype and a short GIF/video here -->
