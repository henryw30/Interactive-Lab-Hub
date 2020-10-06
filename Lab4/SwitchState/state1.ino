// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
  Serial.println("Reading from EEPROM");

  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    Serial.print(value);
    if (i % 2 == 1) {
      Serial.print(" "); //group by int since every 2 bytes is a new int
    }
  }
  Serial.println();

  Serial.println("Done reading from EEPROM");
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}
