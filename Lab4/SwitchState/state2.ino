// This borrows code from Examples->EEPROM->eeprom_write

String textarray = "hello cornell tech!";
int numBits = 8; //num bits in a byte
int endAddr = 2; //number of groups of 8 bits
int readCell = 0; //ints are 10 bits
byte test = 0;

//photo cell info saved within 2 bytes

void state2Setup() {
  digitalWrite(ledPin, LOW);

  Serial.println("Writing data from photo cell to EEPROM");
  readCell = analogRead(photoCell);
  Serial.println(readCell);
  
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
  for (int i = 0; i < endAddr; i++) {
    //info saved as big endian
    test = (readCell & (0xFF00 >> i * numBits)) >> (1 - i) * numBits;
    EEPROM.write(i, test);
  }

  Serial.println("Photo cell info committed to EEPROM!");
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
