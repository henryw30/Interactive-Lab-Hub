
# Motors, Power, Paper Prototyping


## Part A. Actuating DC motors


### Part 1. Connect the Servo to your breadboard


**a. Which color wires correspond to power, ground and signal?**

* red = Vcc
* brown = Gnd
* orange = PWM (signal)


### Part 2. Connect the Servo to your Arduino

**a. Which Arduino pin should the signal line of the servo be attached to?**
Upload the sketch to the Arduino. Your servo should start sweeping back and forth, by about 180 degrees.

* signal -> connected to pin 9 (the pwm line)

Change some parameters in the sketch to make the servo sweep slower, or over a smaller angle.

* in sweep_slow

**b. What aspects of the Servo code control angle or speed?**

* speed = delay parameter
* angle = upper bound in pos in for loop 

## Part C. Integrating input and output

Using what you've learned already, write code to control the servo motor circuit, either:
adjusting the servo motor rotation to reflect the reading on a potentiometer voltage divider circuit, (Yes, it is fine to use any other analog voltage sensor!) or reflecting pre-programmed actions you design. 

* answer in sweep_slow

## Part D. Autonomy!

Remove the USB cable

Use the 9V battery and pigtail to power the Arduino using the Vin and Ground line.

**Include a photo/movie of your autonomous device in action.**

* Arduino is currently not working :( </p>
[but here is how it looks](https://photos.app.goo.gl/LA4CiJUri8kDQvR58)

## Part E. Paper display


**a. Make a video of your paper display in action.**

* Arduino is currently not working :( </p>
[but here is how it looks](https://photos.app.goo.gl/JWV8FUe3og72saLx6)

## Part F. Make it your own

Now modify this set up to make this your own design. 

**a. Make a video of your final design in action.**

* Arduino is currently not working :( </p>
[but here is how it looks](https://photos.app.goo.gl/gHKV7e4LMm6abQ3x6)

* the leds were supposed to light up to display the count in binary form
* code in button_press
