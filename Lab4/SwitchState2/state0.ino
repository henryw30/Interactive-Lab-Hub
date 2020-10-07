// This borrows code from Examples->EEPROM->eeprom_clear

void state0Setup() {
  digitalWrite(ledPin, LOW);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);             // Start at top-left corner
  display.println("Clearing EEPROM");
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
  for (int i = 0; i < EEPROMSIZE; i++) {
    EEPROM.write(i, 0);
  }

  // turn the LED on when we're done
  display.println("EEPROM cleared");
  display.display();
}

void state0Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState0() {
  if (lastState != 0) { state0Setup(); }
  state0Loop();
}
