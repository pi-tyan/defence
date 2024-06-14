#include <wire.h>
#include <Adafruit_BNO055.h>
#include <Ticker.h>
Ticker bno055ticker
#define BNO055interval 10
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28, &Wire); 
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28)

void setup(void)
{
  pinMode(21, INPUT_PULLUP); 
  pinMode(22, INPUT_PULLUP); 

  Serial.begin(115200);
  Serial.println("Orientation Sensor Raw Data Test"); Serial.println("");

  if (bno.begin()) 
  {
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }

  delay(1000);
}