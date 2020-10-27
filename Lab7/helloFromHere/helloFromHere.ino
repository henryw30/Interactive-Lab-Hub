String message;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int button = 2;
int buttonState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void loop() {
  if(Serial.available()){         //From RPi to Arduino
      message = Serial.readString();  //conveting the value of chars to integer
     // Serial.println(r);
     if (message == "red") {
       setColor(255, 0, 0);
     }
     else if (message == "green") {
       setColor(0, 255, 0);
     }
     else if (message == "blue") {
       setColor(0, 0, 255);
     }
     else {
     }
//      switch (message) {
//        case 'red':
//          setColor(255, 0, 0); //red
//          break;
//        case 'green':
//          setColor(0, 255, 0); //green
//          break;
//        case 'blue':
//          setColor(0, 0, 255); //red
//          break;
//        default:
//          break; //do nothing  
//      }
    }
    //sensorValue=analogRead(sensorPin);
    int newState = digitalRead(button);
    if (buttonState != newState) {
      buttonState = newState;
      if (buttonState == HIGH) {
        Serial.println("red");
      }
    }
  // put your main code here, to run repeatedly:
  //Serial.println("red");//data that is being Sent
  //delay(200);
}
