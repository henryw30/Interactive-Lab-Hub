#include <Servo.h>

const int LED_PIN = 13; // LED pin - active-high

Servo myservo;

int POS_CLOSE = 5;
int POS_OPEN = 90;
const int SENSOR_PIN = 12;
int SERVO_PIN = 4;


int proximity;
int proximity_next;
int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  myservo.attach(SERVO_PIN);
  myservo.write(POS_CLOSE);

  // wait for sensor calibration
  delay(10000);
  proximity_next = digitalRead(SENSOR_PIN);
}

void loop()
{
  proximity    = proximity_next;
  proximity_next = digitalRead(SENSOR_PIN);

  // mildly mitigate the initial misfires
  if (count <= 500) {
    count++;
  }

    // motion detected
  if (proximity_next == LOW && proximity == HIGH && count > 500)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
    myservo.write(POS_OPEN);
    delay(10000);
  }
  else if (proximity_next == HIGH && proximity == LOW)
  {
    digitalWrite(LED_PIN, LOW);
    myservo.write(POS_CLOSE);
    delay(3000);
    count = 0;
  }
}
