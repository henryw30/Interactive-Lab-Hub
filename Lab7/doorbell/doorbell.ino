String message;

int button = 2;
int buttonState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
    //sensorValue=analogRead(sensorPin);
    int newState = digitalRead(button);
    if (buttonState != newState) {
      buttonState = newState;
      if (buttonState == HIGH) {
        Serial.println("ring");
      }
    }
}
