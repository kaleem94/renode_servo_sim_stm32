//code to read 9g sservo angle from analog pin A1 and send it to serial port and set the servo angle on pin 8
#include <Arduino.h>
#include <Servo.h>

Servo myservo;

int val = 0;
void setup() {
    pinMode(A1, INPUT); // sets the A1 pin as input
    myservo.attach(8); // attaches the servo on pin 8 to the servo object
    Serial.begin(9600); // starts serial port
}

void loop() {
    val = analogRead(A1); // reads the value of the potentiometer (value between 0 and 1023)
    Serial.println(val); // prints the value read
    myservo.write(val/4); // sets the servo position according to the scaled value
    delay(15); // waits for the servo to get there
}