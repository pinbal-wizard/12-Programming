#include <Wire.h>
// Include the required Wire library for I2C<br>#include 
#define bufSize 50

int x = 0;
void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.println("Startup Master");
}

void loop() {
  digitalWrite(13, HIGH);
  if (Serial.available() > 0) 
  {
    char inp[bufSize];
    memset(inp,0, bufSize);
    int availableBytes = Serial.available();
    int rlen = Serial.readBytesUntil(10,inp, bufSize);
     

    Serial.print("I received: ");
    for(int i = 0; i < rlen; i++)
    {
      Serial.print(inp[i]);
    }
    Serial.println();

    char deviceArr[3];
    strncpy(deviceArr, inp, 3);
    int device = atoi(deviceArr);
    char* command;
    command = &inp[3];
    

    Serial.print("Sending to: ");
    Serial.println(device, DEC);
    Serial.print("With: ");
    Serial.println(command);

    Wire.beginTransmission(device);
    Wire.write(command);
    Wire.endTransmission(); 

    Serial.println();
  }
}