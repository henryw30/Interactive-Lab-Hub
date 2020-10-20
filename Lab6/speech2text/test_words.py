#!/usr/bin/env python3

from vosk import Model, KaldiRecognizer
import sys
import os
import wave

import serial
import time
import json

ser = serial.Serial('/dev/ttyUSB0', 9600)

if not os.path.exists("model"):
    print ("Please download the model from https://github.com/alphacep/vosk-api/blob/master/doc/models.md and unpack as 'model' in the current folder.")
    exit (1)

wf = wave.open(sys.argv[1], "rb")
if wf.getnchannels() != 1 or wf.getsampwidth() != 2 or wf.getcomptype() != "NONE":
    print ("Audio file must be WAV format mono PCM.")
    exit (1)

model = Model("model")
# You can also specify the possible word list
# rec = KaldiRecognizer(model, wf.getframerate(), "zero oh one two three four five six seven eight nine [unk]")
#rec = KaldiRecognizer(model, wf.getframerate(), "apple orange banana strawberry pear watermelon mango [unk]")
rec = KaldiRecognizer(model, wf.getframerate(), "yo good afternoon evening morning [unk]")

while True:
    data = wf.readframes(4000)
    if len(data) == 0:
        break
    if rec.AcceptWaveform(data):
        print(rec.Result())
    else:
        print(rec.PartialResult())

a_result = rec.FinalResult()

obj = json.loads(a_result)
print(obj['text'])
ser.write(bytes(obj['text'], 'utf-8'))
