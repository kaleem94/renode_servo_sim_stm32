// code to read angle of servo with adc on pin A1 and send pwm control signal to 9g servo on pin 9

#include <Arduino.h>
#include <Servo.h>
#define servoPin 9
Servo myservo;
int angle = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    myservo.attach(servoPin);

}

void loop() {
    // Tell the servo to go to a particular angle:
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);

    // Sweep from 0 to 180 degrees:
    for (angle = 0; angle <= 180; angle += 1) {
        myservo.write(angle);
        delay(15);
    }

    // And back from 180 to 0 degrees:
    for (angle = 180; angle >= 0; angle -= 1) {
        myservo.write(angle);
        delay(30);
    }
    delay(1000);
}