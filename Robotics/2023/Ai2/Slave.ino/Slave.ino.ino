#include <Wire.h>
#include <string.h>

#define LED 13


char buffer[40];
int isReady = 0;

void setup() {
  digitalWrite(LED, HIGH);
  pinMode(LED, OUTPUT);

  if(Serial)
  {
    Serial.begin(9600);
    Serial.println("Startup slave 6");
  }
  
  // Start the I2C Bus as Slave on address 6
  Wire.begin(6); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int howMany)
{
  if(Serial)
  {
    Serial.print("Recived: ");
    Serial.print(howMany);
    Serial.println(" Bytes");
  }

  int messagePosition = 0;
  int availableBytes = Serial.available();
  for(int i=0; i<=availableBytes; i++)
  {
    int temp = Wire.read();
    if(Serial)
    {
      Serial.println(temp, DEC);  
    }
    buffer[messagePosition] = temp;
    messagePosition += 1;
  }
  isReady = 1;
}

void loop() {
  if(isReady == 1)
  {
    if(Serial)
    {
      Serial.println(buffer);
    }
    
    if(strncmp(buffer, "LED", 3) == 0)
    {
      digitalWrite(LED, !digitalRead(LED));

      if(Serial)
      {
        Serial.println("Switching led state");
      }
    }
    memset(buffer,0, bufSize);
    isReady = 0;
  }
}