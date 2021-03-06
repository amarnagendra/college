/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;
void accelerometer();
int x,y,z;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("mahimyam.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    accelerometer();
    
    myFile.println("guldu manoj");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("mahimyam.txt");
  if (myFile) {
    Serial.println("mahimyam.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void accelerometer(){
  // put your main code here, to run repeatedly:
  x= analogRead(A5);
  y=analogRead(A4);
  z=analogRead(A3);
  x=map(x,0,1023,0,255);
  y=map(x,0,1023,0,255);
  z=map(x,0,1023,0,255);
   myFile.println("the x y z values are " );
   myFile.println(x);
   myFile.println(y);
   myFile.println(z);
//  
//    if(oldx-x>1 || oldy-y>1)
//     {  
//      Serial.println(oldx-x);
//      Serial.println("collison detected");
//     }
//    oldx=x;
//    oldy=y;
//    oldz=z;
//    
    
}
void loop()
{}

