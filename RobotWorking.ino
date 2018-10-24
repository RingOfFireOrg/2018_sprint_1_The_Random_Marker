// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Servo leftW;
Servo rightW;

int STOP_VAL_R = 90;
int STOP_VAL_L = 90;
int Counter = 0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  leftW.attach(5);
  leftW.write(STOP_VAL_L);
  rightW.attach(9);
  rightW.write(STOP_VAL_R);
  pinMode(4, OUTPUT);
}

void stop() {
  leftW.write(STOP_VAL_L);
  rightW.write(STOP_VAL_R);
}

void forward() {
  leftW.write(0);
  rightW.write(180);
}

void backup() {
  leftW.write(180);
  rightW.write(0);
}

void loop() {
  if (Counter < 1) {
    forward();
    delay(1700);
    stop();
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    forward();
    delay(1200);
    stop();
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    forward();
    delay(900);
    stop();
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    forward();
    delay(1100);
    stop();
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    forward();
    delay(700);
    stop();
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    Counter = Counter + 2;
  }
    
}