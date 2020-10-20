//helloArduino.ino
// by Wend
//
//

int ledPin=13;
String message;

void blink(){
digitalWrite(ledPin, HIGH);
delay(100);
digitalWrite(ledPin, LOW);
delay(100);
}

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  if(Serial.available()){         //From RPi to Arduino
    message = Serial.readString();  //conveting the value of chars to integer
    if (message.indexOf("morning") != -1) {
      Serial.println("good morning to you!");
    }
    else if (message.indexOf("afternoon") != -1) {
      Serial.println("good afternoon to you!");
    }
    else if (message.indexOf("evening") != -1) {
      Serial.println("good evening to you!");
    }
    else {
      Serial.println("HI");
    }
    
    //Serial.println(message);
    blink();
  }
}
