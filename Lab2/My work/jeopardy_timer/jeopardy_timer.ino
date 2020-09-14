#include "pitches.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

int sensor_pin = A0;    // select the input pin for the potentiometer
int sensor_value = 0;  // variable to store the value coming from the sensor

int melody[] = {
  NOTE_A4,NOTE_D5,NOTE_A4,NOTE_D4,
  NOTE_A4,NOTE_D5,NOTE_A4,
  NOTE_A4,NOTE_D5,NOTE_A4,NOTE_D5,
  NOTE_FS5,0,NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_B4,NOTE_AS4,
  NOTE_A4,NOTE_D5,NOTE_A4,NOTE_FS4,NOTE_G4,
  NOTE_A4,NOTE_D5,NOTE_A4,
  NOTE_D5,0,NOTE_B4,NOTE_A4,NOTE_G4,
  NOTE_FS4,NOTE_E4,NOTE_D4,0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,
  4,4,2,
  4,4,4,4,
  4,8,8,8,8,8,8,
  4,4,4,8,8,
  4,4,2,
  4,8,8,4,4,
  4,4,4,4
};

//play theme until sensor_value seconds
void playTheme(int sensor_value) {
    unsigned long start = millis() / 1000;

    while (true) {
        // iterate over the notes of the melody:
        for (int thisNote = 0; thisNote < 35; thisNote++) {

            // to calculate the note duration, take one second divided by the note type.
            //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
            int noteDuration = 1000 / noteDurations[thisNote];
            tone(8, melody[thisNote], noteDuration);

            // to distinguish the notes, set a minimum time between them.
            // the note's duration + 30% seems to work well:
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);
            // stop the tone playing:
            noTone(8);

            printToOLED((unsigned long)sensor_value - ((millis() / 1000) - start));

            if (((millis() / 1000) - start) == (unsigned long)sensor_value) {
                return;
            }
        }
    }
}

//write done to screen
void writeDone() {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);             // Start at top-left corner
    display.println("TIME'S UP!");

    display.display();
}

//print an int to screen
void printToOLED(int sensor_value) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);             // Start at top-left corner
    display.println(sensor_value);

    display.display();
}

//infinite loop stop
void stop() {
    writeDone();
    for (;;); //infinite loop
}

void setup() {
    Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    // Show initial display buffer contents on the screen --
    // the library initializes this with an Adafruit splash screen.
    display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    display.clearDisplay();
    
    // draw to display
    sensor_value = analogRead(sensor_pin) / 10; //divide by 10 for better range of times
    printToOLED(sensor_value);

    delay(2000); //pause to show timer
}

void loop() {
    playTheme(sensor_value);
    stop();
}
