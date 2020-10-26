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

You will join a network of loosely networked Cornell Tech Things, which use the MQTT to communicate to one another. For the first step in this, we will build a simple client-server between your computer and your Interaction Engine. (Use the ``HelloThere`` and ``HelloFromHere`` code samples to do this!)

```
### Important side note
The ``HelloThere`` and ``HelloFromHere`` examples are used to use an MQTT server/broker that is no longer active. In order to test and experiment with these examples please use the ```mqtt.eclipse.org``` address.

Set up your Arduino so that it can control an RGB LED and read input from a button.
```

Now, change the code for your Interaction Engine so that you can set different buttons on a remote webpage that change the color of the RGB LED. Also, set it so that you can press a button to change the background color on the webpage. (Again, the ``HelloThere`` and ``HelloFromHere`` code samples show you how to communicate with a MQTT server. Merge the code from those samples into your interaction engine code to control the light and to send messages based on the button press.)

Now we will modify our Interaction Engine to send messages to a MQTT server/broker.  

When you start your MQTT client, you will specify “your color”. When you press your button, the client will send this color to the MQTT server, and all the other devices on the server will change their LEDs this color. 

We will use ```mqtt.eclipse.org```, channel IxE for a MQTT server/broker for the course. The TA [has set up a web camera with her devices being broadcast](http://farlab.infosci.cornell.edu:8081) so that you can see if your actions change the LED of her Thing. You should be able to press your button and see the remote LED change to your color. On the remote webpage, you should be able to press a color button and see it show up on your LED.

When everyone in the class is connected to the server, everyone will be able to push their color out to everyone else’s Things by pressing their own buttons.

Technical specification:
```
MQTT_boker: mqtt.eclipse.org 
Topic: ixe/
Acceptable messages (string): 'red' || 'green' || 'blue' (more to be added later)
Webcam: http://farlab.infosci.cornell.edu:8081
```

## OpenCV try out

We included 4 standard OpenCV examples in the IxE.  These examples include contour(blob) detection, face detection with the ``Haarcascade``, flow detection(a type of keypoint tracking), and standard object detection with the [Yolo](https://pjreddie.com/darknet/yolo/) darknet. 

Most examples can be run with a screen (I.e. VNC or ssh -X or with an HDMI monitor), or with just the terminal. The examples are separated out into different folders. Each folder contains a ```HowToUse.md``` file, which explains how to run the python example. 

```shell
pi@ixe00:~/openCV-examples $ tree -l
.
├── contours-detection
│   ├── contours.py
│   └── HowToUse.md
├── data
│   ├── slow_traffic_small.mp4
│   └── test.jpg
├── face-detection
│   ├── face-detection.py
│   ├── faces_detected.jpg
│   ├── haarcascade_eye_tree_eyeglasses.xml
│   ├── haarcascade_eye.xml
│   ├── haarcascade_frontalface_alt.xml
│   ├── haarcascade_frontalface_default.xml
│   └── HowToUse.md
├── flow-detection
│   ├── flow.png
│   ├── HowToUse.md
│   └── optical_flow.py
└── object-detection
    ├── detected_out.jpg
    ├── detect.py
    ├── frozen_inference_graph.pb
    ├── HowToUse.md
    └── ssd_mobilenet_v2_coco_2018_03_29.pbtxt
```

## Video doorbell

Now, using design a video doorbell, or any application where you can remotely control and observe action at another location. It is okay to partner up on this assignment so that you and someone else in the class have devices that communicate with one another. 

** Please include video of the project **
** All supporting designs materials and code should be in your lab assignment folder, and documented enough that you could recreate it from scratch if you had memory loss. **
