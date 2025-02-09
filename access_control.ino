#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_IN 7    // Trigger pin for entry sensor
#define ECHO_IN 6    // Echo pin for entry sensor
#define TRIG_OUT 5   // Trigger pin for exit sensor
#define ECHO_OUT 4   // Echo pin for exit sensor
#define BUZZER 3     // Buzzer pin

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD address: 0x27, 16x2 display

int peopleCount = 0;
const int maxCapacity = 10;

void setup() {
    pinMode(TRIG_IN, OUTPUT);
    pinMode(ECHO_IN, INPUT);
    pinMode(TRIG_OUT, OUTPUT);
    pinMode(ECHO_OUT, INPUT);
    pinMode(BUZZER, OUTPUT);
    
    lcd.init();
    lcd.backlight();
    
    lcd.setCursor(0, 0);
    lcd.print("Room Capacity:");
    updateLCD();
}

void loop() {
    if (detectPerson(TRIG_IN, ECHO_IN)) {
        peopleCount++;
        updateLCD();
        delay(1000); // Avoid multiple counts
    }

    if (detectPerson(TRIG_OUT, ECHO_OUT) && peopleCount > 0) {
        peopleCount--;
        updateLCD();
        delay(1000);
    }

    if (peopleCount > maxCapacity) {
        digitalWrite(BUZZER, HIGH); // Trigger alarm
    } else {
        digitalWrite(BUZZER, LOW);
    }
}

bool detectPerson(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;

    return (distance > 2 && distance < 50); // Detects objects between 2cm and 50cm
}

void updateLCD() {
    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(peopleCount);
    lcd.print("   "); // Clear extra digits
}
