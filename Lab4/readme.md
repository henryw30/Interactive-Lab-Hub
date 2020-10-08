# Data Logger (and using cool sensors!)


## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

* 0 to 1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have** (hint: where might you look to find this sort of thing)? How many are you using with the range of values you're seeing?

* 10 bits (from data sheet), using 10 based on potentiometer readings (2^10 = 1024)
 
<<<<<<< HEAD
=======
For this lab, you can use the serial monitor, plotter and/or the OLED display whenever you are told to display something, depending on what you think is easier/prettier.
>>>>>>> 92812ac4bf1a3341fe019dd5d7a6f682695fb1ff

## Part B. RGB LED


## Part C. Resistance & Voltage Varying Sensors 
 
### FSR

**a. What voltage values do you see from your force sensor?**

* 949 (0.0049 * 949 = 4.65 V) was the max reading I could get

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

* exponential since the log-log plot of force and resistance is linear

**c. In `Examples->Basic->Fading` the RGB LED values range from 0-255. What do you have to do so that you get the full range of output voltages from the RGB LED when using your FSR to change the LED color?**

* hit the sensor very hard

## Flex Sensor, Photo cell, Softpot

**a. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

* flex sensor - 25k to 100k (might need resistors in parallel since resistance of itself is really high)
* photo cell - 10k resistor
* softpot - is a 10k resistor, so don't really need extra resistors

**b. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

* flex sensor - linear
* photo cell - exponential (log/log is linear)
* softpot - linear


## Part D. I2C Sensors 

### Accelerometer

**a. Include your accelerometer read-out code in your write-up.**
 * in lab4/acceldemo 

## Part E. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

* not necessarily because we can define what happens in each state (via programming)

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

* because we only want to execute the setup code once (not constantly reading/writing to EEPROM when nothing has changed)


**c. How many byte-sized data samples can you store on the Atmega328?**

* 1024 since the biggest sized string it can hold is 1024 bytes

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

* since analog data reads in an int (10 bits), make a mask and shift the bits to mask each byte. Same thing if the data incoming from i2c devices is an int. If it's bigger / smaller adjust the mask and shifting to be byte sized
* also could just divide analog data to fit within a byte, but that means some values from the input devices would be cut off at 2^8 numbers 

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

* divide the data into bytes and then make a for loop to write each byte
* EEPROMPut can be used to write to a chunk of data

Modify the code to take in analog values from your sensors and print them back out to the Arduino Serial Monitor.

* in SwitchState/

### 2. Design your logger
 
**a. Turn in a copy of your final state diagram.**

* [photo cell diagram](https://photos.app.goo.gl/FzhfdGg1HUhnS4jb9)

## Part G. Create your own data logger!
Now it's up to you to integrate the software and hardware necessary to interface with your data logger! Your logger should be able to record a stream of analog data (at a sample rate of your desire) and then play it back at some later point in time on your display of choice.
 
**a. Record and upload a short demo video of your logger in action.**

* code in SwitchState2/

* [demo video](https://photos.app.goo.gl/QgxhYBv8Xys34p6v5)
