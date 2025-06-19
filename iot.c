#include <Servo.h>

// Motor pins
const int motor_1 = 4;
const int motor_2 = 5;
const int motor_3 = 6;
const int motor_4 = 7;

// Sensor pins
const int left_sensor = 8;
const int middle_sensor = 9;
const int right_sensor = 10;

// Servo & pump
const int servo_pin = 11;
const int water_pump = 12;

Servo myservo;

void setup() {
  pinMode(water_pump, OUTPUT);
  pinMode(motor_1, OUTPUT);
  pinMode(motor_2, OUTPUT);
  pinMode(motor_3, OUTPUT);
  pinMode(motor_4, OUTPUT);
  
  pinMode(left_sensor, INPUT);
  pinMode(middle_sensor, INPUT);
  pinMode(right_sensor, INPUT);

  myservo.attach(servo_pin);
  myservo.write(90);
  digitalWrite(water_pump, HIGH); // OFF
  stopMotors();
}

void loop() {
  bool left = digitalRead(left_sensor) == LOW;
  bool middle = digitalRead(middle_sensor) == LOW;
  bool right = digitalRead(right_sensor) == LOW;

  if (middle) {
    moveForward(500);
    sprayAt(90);  // Center
  }
  else if (left) {
    turnLeft(200);         // 🔧 Reduced from 350
    moveForward(400);
    sprayAt(60);
  }
  else if (right) {
    turnRight(200);        // 🔧 Reduced from 350
    moveForward(400);
    sprayAt(120);
  }
  else {
    stopMotors();
    myservo.write(90);
  }
}

// --- Movement ---
void moveForward(int duration) {
  digitalWrite(motor_1, LOW); digitalWrite(motor_2, HIGH);
  digitalWrite(motor_3, LOW); digitalWrite(motor_4, HIGH);
  delay(duration);
  stopMotors();
}

void turnLeft(int duration) {
  digitalWrite(motor_1, HIGH); digitalWrite(motor_2, LOW);
  digitalWrite(motor_3, LOW);  digitalWrite(motor_4, HIGH);
  delay(duration);
  stopMotors();
}

void turnRight(int duration) {
  digitalWrite(motor_1, LOW);  digitalWrite(motor_2, HIGH);
  digitalWrite(motor_3, HIGH); digitalWrite(motor_4, LOW);
  delay(duration);
  stopMotors();
}

void stopMotors() {
  digitalWrite(motor_1, LOW);  
  digitalWrite(motor_2, LOW);   
  digitalWrite(motor_3, LOW);  
  digitalWrite(motor_4, LOW);
}

// --- Spray ---
void sprayAt(int angle) {
  digitalWrite(water_pump, LOW); // ON
  delay(200);

  for (int i = 0; i < 3; i++) {
    myservo.write(angle); delay(200);
    myservo.write(angle - 30); delay(200);
    myservo.write(angle + 30); delay(200);
  }

  myservo.write(90);  // Re-center
  digitalWrite(water_pump, HIGH); // OFF
}