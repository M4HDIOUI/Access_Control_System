# Access Control System – Arduino Project
This project is an automated room access control system that counts the number of people entering and exiting a room. It uses ultrasonic sensors to detect movement, an I2C LCD to display the count, and a buzzer to alert when the room exceeds capacity.

# Features
✔ Detects people entering and exiting.
✔ Updates live count on I2C LCD.
✔ Triggers buzzer if more than 10 people are in the room.

# Required Components
Arduino Uno
2x HC-SR04 Ultrasonic Sensors
I2C LCD (16x2)
Buzzer
Jumper Wires
Setup & Wiring
Connect Entry Sensor (HC-SR04) → Trig to Pin 7, Echo to Pin 6.
Connect Exit Sensor (HC-SR04) → Trig to Pin 5, Echo to Pin 4.
Connect I2C LCD → SDA to A4, SCL to A5.
Connect Buzzer → Pin 3.
# How It Works
When someone enters, the count increases.
When someone leaves, the count decreases.
If the count exceeds 10, the buzzer sounds an alarm.
How to Upload the Code
Open Arduino IDE.
Install the LiquidCrystal_I2C library if not already installed.
Copy and paste the code into the IDE.
Select Board: Arduino Uno and Port: COMx.
Click Upload.