# Try some Python code on the Pi

** How do you know what the shell script is doing? **
* by using `nano` to view the scripts and seeing the strings located in them

Adapt the scripts so that they say what you want them to say.

Now try the shellscripts in the ``speechToText`` directory. 

These scripts use a program called [``vosk``](https://alphacephei.com/vosk/) to recognize numbers. 

**How do we use ``vosk`` to recognize words and phrases?**

* the script records speech by accessing a microphone and then runs a python script that has a KaldiRecognizer, which matches the audio to words in the provided list

**Include the output of vosk recognizing phrases you taught it to look for.**

* looking for: "yo good afternoon evening morning [unk]"

```
{
    'result': [{'conf': .500634, 'end': 1.709495, 'start': 1.29, 'word': 'morning'},
    {'conf': .906319, 'end': 2.105738, 'start': 1.709495, 'word': 'morning'},
    {'conf': .937634, 'end': 2.685972, 'start': 2.274791, 'word': 'morning'},
    ],
    'text': 'morning morning morning'
}

```

**Include the listing for a shell script and model files that you use to get vosk to recognize these phrases.**

* in speech2text/vosk_demo_mic.sh and speech2text/test_words.py


# Connect the Arduino and the RPi

**What would you change to make sayHelloPi say something else?**

* change data string to be whatever we want

**How could you make it so that the Pi would only say something if the lights came on in the room?**

* edit the helloPi.ino code to read sensor data from a light sensor and then send a string through the serial port

**How could you make it so that the Pi would say different things based on different sensor values read by the Arduino?**

* in hellopi.ino code, send sensor values through the serial port
* in sayHellopi.py code, play a different .wav file (with the call() method) based on the value read from the 'message' variable

Next, try out ``HelloArduino``. First have ``HelloArduino.ino`` listen for messages from ``HelloArduino.py``. Next, use ``morse_code_translator.ino``. What happens differently? 

* for hellarduino.ino, the arduino monitors serial port and blinks everytime a message is received (which was sent from the helloarduino.py code)
* for morse_code_translator.ino, the arduino monitors the serial port and takes in a message from the port (when a message arrives) and blinks the LED in morse code


Change the ``HelloArduino.py`` program to take in inputs from the user to have them translated to morse code on the Arduino.

* in helloArduino/HelloArduino.py

## Your own voice agent 

Program a simple application that understands different basic greetings (for example, Yo!, Good morning! And Good afternoon!) and responds either visibly, physically or auditorially in kind!

You are free to adapt this assignment to have the agent respond to any other set of vocabulary for any other purpose.

**Record someone trying out your design**

* [demo](https://photos.app.goo.gl/DtT1psHFPfUKtefp7)


**Submit your code to Github**

* flashed helloArduino/HelloArduino.ino onto arduino
* speech2text/vosk_demo_mic.sh and speech2text/test_words.py have logic to record and detect user's speech
