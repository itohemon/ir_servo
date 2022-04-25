#define IR 3
#define SERVO 12
#define LED 13

#include <VarSpeedServo.h> 

VarSpeedServo myServo;    // create servo object to control a servo 

#define BOTTOM_DEG 80

void setup() {
  Serial.begin(9600);
  pinMode(IR, INPUT);
  pinMode(LED, OUTPUT);

  myServo.attach(SERVO);
  myServo.write(BOTTOM_DEG, 80, true);
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

  digitalWrite(LED, LOW);

  myServo.attach(SERVO);
  myServo.write(BOTTOM_DEG - 80, 200, true);
  delay(50);
  myServo.write(BOTTOM_DEG - 10, 200, true);
  delay(500);
  myServo.write(BOTTOM_DEG - 20, 100, true);
  delay(250);
  myServo.write(BOTTOM_DEG - 10, 100, true);
  delay(250);
  myServo.write(BOTTOM_DEG - 20, 100, true);
  delay(250);
  myServo.write(BOTTOM_DEG - 10, 100, true);
  delay(250);
  myServo.write(BOTTOM_DEG - 20, 100, true);
  delay(250);
  myServo.write(BOTTOM_DEG, 100, true);
  
  digitalWrite(LED, HIGH);
  
  delay(1000);
}
