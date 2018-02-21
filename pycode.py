import time
import serial
#import urllib2
import requests

mymap=dict.fromkeys(range(32))
def cleanStr(mystring):
	message = mystring.decode('ascii')
	return message.translate(mymap)

people = 0
inside = 0
number = 0
flag = 0
ser = serial.Serial('COM3', 9600)

while True:
	number=int(number)
	message = ''
	message = ser.readline()
	message = cleanStr(message)
	print(message)
	if(message=='0' or message=='1'):
		message = int(message)
		people = people + message
		inside = people/2;
		message=str(message)
		inside=str(inside)
		response = requests.get('https://api.thingspeak.com/update?api_key=JIK55LIOLVI8JIGX&field2='+message+'&field3='+inside)
		html = response.text
	else:
		number+=1
		number=str(number)
		res = requests.get('https://api.thingspeak.com/update?api_key=JIK55LIOLVI8JIGX&field1='+number)
		h = res.text
	
	
	time.sleep(1)

