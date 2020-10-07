// This borrows code from Examples->EEPROM->eeprom_write

int addr = 0;
int readCell = 0; //ints are 10 bits

//photo cell info saved within 2 bytes

void state2Setup() {
  digitalWrite(ledPin, LOW);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);             // Start at top-left corner

  display.println("Writing data from photo cell to EEPROM");
  readCell = analogRead(photoCell) / 4;
  display.println(readCell);

  EEPROM.write(addr, readCell);
  addr = (addr + 1) % 1024;

  display.println("Photo cell info committed to EEPROM!");
  display.display();
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) {
      addr = 0;
  }
  state2Setup();
  state2Loop();
}
