// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);             // Start at top-left corner

  
  display.println("Reading from EEPROM");

  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    display.print(value); display.print(" ");
    display.display();
    if (i % 60 == 0) {
      display.clearDisplay();
      display.setCursor(0,0);
    }
    
    //Serial.print(value); Serial.print(" ");
  }
  display.println();

  display.println("Done reading from EEPROM");
  display.display();
}

void state1Loop() {
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}
