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

int buttonPin = 9;
int ledPin0 = 3;  
int ledPin1 = 4; 
int ledPin2 = 5; 
int ledPin3 = 6; 
int ledPin4 = 7;

unsigned int count = 0;

//print an int to screen
void printToOLED(unsigned int count) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);             // Start at top-left corner
    display.println(count);

    display.display();
}

void setup() {
    // put your setup code here, to run once:
    pinMode(ledPin0, OUTPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    pinMode(buttonPin, INPUT);

    Serial.begin(9600);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    display.clearDisplay();

    printToOLED(count);
}

//whenver button is pressed, increment and light up binary number on leds
//only goes up to 31
void loop() {
    // put your main code here, to run repeatedly:
    while (true) {
        if (digitalRead(buttonPin)) {
            break;
        }

        delay(500);
    }

    count++;
    printToOLED(count);

    for (int i = 0; i < 5; i++) {
        int val = (count >> i) & 1 == 1 ? 1 : 0;
        digitalWrite(val, ledPin0 + i);
    }

    if (count > 31) {
        count = 0;
    }
}
