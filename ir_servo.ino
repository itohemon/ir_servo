#define IR 3
#define SERVO 12
#define LED 13

#include <Servo.h>

Servo myServo;

int pulse_min = 544;
int pulse_max = 2400;
  
void setup() {
  Serial.begin(9600);
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);

  myServo.attach(SERVO, pulse_min, pulse_max);
  myServo.write(120);
  myServo.detach();
}

void loop() {
  myServo.detach();

  while (1) {
    bool ir = digitalRead(IR);
    Serial.println(ir);
    digitalWrite(LED, LOW);

    delay(100);

    if (!ir) {
      break;
    }
  }

  while (1) {
    bool ir = digitalRead(IR);
    Serial.println(ir);
    digitalWrite(LED, HIGH);

    delay(100);

    if (ir) {
      break;
    }
  }
    
  delay(1500);
  myServo.attach(SERVO, pulse_min, pulse_max);
  myServo.write(30);
  digitalWrite(LED, LOW);
  delay(270);
  myServo.write(120);
  digitalWrite(LED, HIGH);
  delay(500);
}
