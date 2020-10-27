import serial
import time
# import threading
import paho.mqtt.client as mqtt
# import paho.mqtt.publish as publish

from flask import Flask, render_template
from flask_socketio import SocketIO, emit
from threading import Thread

broker="mqtt.eclipse.org"
#broker="test.mosquitto.org"

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
	print("Connected with result code "+str(rc))
	# Subscribing in on_connect() means that if we lose the connection and
	# reconnect then subscriptions will be renewed.
	client.subscribe("ixe/")

def on_message(client, userdata, msg):
	receivedMessage = str(msg.payload.decode("utf-8"))
	print("received message = "+receivedMessage)
	ser.write(receivedMessage.encode())

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker, 1883, 60)

client.loop_start()

# Arduino communication
ser = serial.Serial('/dev/ttyUSB0', 9600)
ser.flushInput()

def read_from_port(ser):
    while True:
        reading = ser.readline().decode().strip()
        print(reading)
        print(type(reading))
        client.publish("ixe/", reading)
        ser.flushInput()
        time.sleep(1)
        #socketio.emit('server-msg', reading)

thread = Thread(target=read_from_port, args=[ser])
thread.start()

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)


@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('connect')
def test_connect():
    print('Client connected')
    emit('my response', {'data': 'Connected'})

@socketio.on('disconnect')
def test_disconnect():
    print('Client disconnected')

@socketio.on('redLedON')
def red_led_on():
    print("Turn the red LED on!")
    ser.write(b"red")

    #client.publish("here/", b"red")
    #ser.flushInput()
    #time.sleep(1)


@socketio.on('greenLedON')
def green_led_on():
    print("Turn the green LED on!")
    ser.write(b"green")

    #client.publish("here/", b"green")
    #ser.flushInput()
    #time.sleep(1)

@socketio.on('blueLedON')
def blue_led_on():
    print("Turn the blue LED on!")
    ser.write(b"blue")

    #client.publish("here/", b"blue")
    #ser.flushInput()
    #time.sleep(1)


def main():
	try:
		while True:
			reading = ser.readline().decode().strip()
			print(reading)
			print(type(reading))
			client.publish("ixe/", reading)
			ser.flushInput()
			time.sleep(1)
	except KeyboardInterrupt:
		ser.close()
		client.disconnect()
		client.loop_stop()
		print ("done")

if __name__ == '__main__':
        app.run(host='0.0.0.0', threaded=True)
        socketio.run(app)
        main()

'''
def read_from_port(ser, delay, run_event):
	while run_event.is_set():
      		reading = ser.readline().decode().strip()
                print(reading)
		client.publish("there/", reading)
                # publish.single("there/", reading, hostname=broker)
	        time.sleep(delay)
		ser.flushInput()

def main():
    	run_event = threading.Event()
    	run_event.set()
    	d1 = 1
    	t1 = threading.Thread(target = read_from_port, args = (ser,d1,run_event))
	d2 = 2
	t2 = threading.Thread(target = read_from_topic, args = ("paul",d2,run_event))

    	t1.start()
#    	time.sleep(.5)
#    	t2.start()

    	try:
		print("main loop")
        	while True:
			time.sleep(.1)

    	except KeyboardInterrupt:
        	print ("attempting to close threads. Max wait ="+str(d1))
        	run_event.clear()
      		t1.join()
        	client.loop_stop()
        	print ("threads successfully closed")

if __name__ == '__main__':
	main()
'''
