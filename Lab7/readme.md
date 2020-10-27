How can we *view* the web from a command line interface? Two ways! First, we can just use a text based browser, like lynx.
```
$ sudo apt install lynx
$ lynx http://cornell.edu
```
We can also use X windows to view the internet in a more familiar way:

Epiphany browser: ` $ sudo apt install epiphany`
Midori browser: `$ sudo apt install midori`
Which one did you like more? Uninstall the other one!
```
$ sudo apt uninstall [package that you did not prefer]

```

* i like epiphany better, midori feels slower

From a remote browser, check to make sure your webserver is working.

** customize the code enough that the webpage served up is clearly your own, and include a screenshot and any modified code in the lab folder. **

* in basicserver.py and webpage.png

# Flash the HelloYou Sketch onto the Arduino

Make sure your arduino is connected to your Raspberry Pi with a USB cable. Using the Arduino IDE on the Raspberry Pi, open `helloYou/helloYou.ino`.

Look at the code. How does the Arduino communicate with the Pi when the code is running?

* arduino checks when button is pressed and sends information through serial port

** What messages are sent from the Arduino to the Pi? **

* "light" and "dark" messages

** What messages are expected from the Pi to the Arduino? **

* "H" to turn led on

** What happens if the Pi sends an unexpected message to the Arduino? **

* led turns off

** How fast does the Arduino communicate with the Pi? What would you change to make it send messages less often? **

* 9600 baud rate which is bits per second. Lower the rate to send messages less often

Compile and flash the `helloYou.ino` code onto the Arduino.

# Run the HelloYou server on the RPi

Using your favorite text editor, open `helloYou/server.py`.

Look at the code. What interface does the Pi use to communicate with the Arduino when the code is running?

* serial port

What messages are sent from the Pi to the Arduino? 

* "H" and "L" depending if the ledON or ledOFF button was pressed on the website


What messages are expected from the Arduino to the Pi?

* "light" and "dark", which change the website background to light and dark respectively


What happens if the Arduino sends an unexpected message to the Pi?

* nothing


What part of the code controls what is served when a browser requests a page from the server?

* the flask code in helloYou.py (e.g. the app.route function sends the index.html page)


What messages are sent to the console? When?

* 'ledON' and 'ledOFF' when the respective button is pressed on the website


## Internet of Cornell Tech Things 

* code that doesn't use mqtt is in ctt2/
* code that uses mqtt is in helloFromHere/ 
* [video here](https://photos.app.goo.gl/LnJM91ykGnsPHeaW8)!

## Video doorbell

Now, using design a video doorbell, or any application where you can remotely control and observe action at another location. It is okay to partner up on this assignment so that you and someone else in the class have devices that communicate with one another. 

** Please include video of the project **
** All supporting designs materials and code should be in your lab assignment folder, and documented enough that you could recreate it from scratch if you had memory loss. **

* in doorbell/doorbell.py and doorbell/doorbell.ino
* main idea is that anyone can ring and activate the doorbell if their button is configured to send the right message over the right mqtt topic
* [here is the video](https://photos.app.goo.gl/NugXeBanAKKStL836)