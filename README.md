# Monitoring System built on Arduino
A basic tracking/mointoring system built on Arduino Uno R3 board using RFID and IR Sensor. The concept is that the subject (here Cab) is equipped with an RFID chip (RC522) and at certain distance (here shuttle stop) a RFID reader is placed which notes down the time of the passage and records the same.
Since in this case, a shuttle cab monitoring is taken as task, the number of people travelling has also be noted and for that reason only a People Counter is introduced using IR Sensor, which calculates the number of interrupts and determine the number of people inside the cab. 
And as the major advantage of implementing an Internet of Things (IoT) system is to analyze the data recorded and store it, for the said purpose, [thingspeak](https://thingspeak.com/) is utilized which can visualize data in terms of plots and graphs.

### Repository Structure
- arduino_code.ino: the Embedded C code which is to be uploaded in the Arduino board.
- circuit_scheme.png: figure which depicts the architectural design of the work. Here the RFID having the component device name as RC522 is attached to Arduino Uno R3 through number of pins and so is the Infrared Sensor. Both the sensors work separately without being effected by each other as seen in the diagram because both are independent of each other and communicates with Arduino board only.
- ir-vs-date.png: figure which depicts the graph of ir interrupts in the time period and is used to determine the people entering or leaving the cab, the increase in interrupt determines the rush hour where the facilities are required and so the more and more cabs can be made available by analyzing the pattern.
- people-vs-date.png: extension of IR interrupt which shows the graph of number of people inside the cab vs date. This graph is of most importance as it determines when the cab is being used the most which in turn make the cabs to operate more frequently or more numbers are employed. This trend of usage can be analyzed for future studies and to make the user experience better by preparing the system so that it can handle such kind of traffic.
- pycode.py: The Python code that reads the data from the serial monitor and displays the result at the same time also sends the data to the ThingSpeak.
- review_paper.pdf: a complete report in research paper format
- rfid-vs-date.png: figure depicts the number of RFID tags scanned over a period of time the increase in the graph is the number of tags scanned. From this graph we can determine that at which time cab is moving more frequently.

## In order to exceute the code please upload the ino code to Arduino and run the Python code and not the ino code. 
The code also has the IR sensor part in integrated format, which needs to be deleted if not using People Counter and vice versa.
You need to create account in Thingspeak and link it your python code by inserting your API key in the place specified.
