char inChar;

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
      inChar = (char)Serial.read();
      switch (inChar) {
        case 'R':
          setColor(255, 0, 0); //red
          break;
        case 'G':
          setColor(0, 255, 0); //green
          break;
        case 'B':
          setColor(0, 0, 255); //blue
          break;
        default:
          break; //do nothing  
      }
    }
    
    int newState = digitalRead(button);
    if (buttonState != newState) {
      buttonState = newState;
      if (buttonState == HIGH) {
        Serial.println("pink");
      }
      else {
        Serial.println("dark");
      }
    }
}
