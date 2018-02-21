#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key; 

byte nuidPICC[4]; // Init array that will store new NUID 

int ledPin = 13;    //pin for led
int inputPin = 2;   //input pin
int pirState = LOW; //no motion initially
int val = 0;

void setup() { 
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  }

void loop()
{
val = digitalRead(inputPin);
if(val == HIGH)
{
  digitalWrite(ledPin, HIGH);
  if(pirState == LOW){
    Serial.println("1"); //turned on
    pirState = HIGH;
    }
  }
else {
  digitalWrite(ledPin, LOW);
  if(pirState == HIGH){
    Serial.println("0");
    pirState = LOW;
    }
  }
  // RFID Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  // Store NUID into nuidPICC array
  //reads and stores the binary data
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
    printHex(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();
  rfid.PICC_HaltA(); // Halt PICC
  rfid.PCD_StopCrypto1(); // Stop encryption on PCD
  //if removed the rfid value will keep on printing

}

//user defined function 
//to dump a byte array as hex values to Serial. 
 //converts the binary to HEX
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i],HEX);
  }
}
