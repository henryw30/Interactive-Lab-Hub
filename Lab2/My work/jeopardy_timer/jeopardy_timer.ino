#include "../toneMelody/pitches.h"
#include "TimerOne.h"

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

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

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


void writeDone() {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);             // Start at top-left corner
    display.println("TIME'S UP!");

    display.display();
    delay(40);
}

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

    // declare the ledPin as an OUTPUT:
    pinMode(ledPin, OUTPUT);

    //start reading from input and start timer
    //!!!!

    Timer1.initialize(10000000); //10 seconds
    Timer1.attachInterrupt(stop);
}

void loop() {
    

}


