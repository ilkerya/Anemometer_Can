// This example demonstrates doing a one-shot measurement "manually".
// Separate calls are made to trigger the conversion and then check
// for conversion complete. While this typically only takes a couple
// 100 milliseconds, that times is made available by separating these
// two steps.

#define CAN_MASTER
//#define CAN_SLAVE

#include <SPI.h>
#include "mcp2515_can.h"
#include <Adafruit_MAX31856.h>
#include <Adafruit_SSD1306.h>

#define TFCARD_SPI_CS  4 //ACTIVE LOW
#define MCP2515_SPI_CS  9 //ACTIVE LOW

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;

#include  "Defs.h"
#include  "Variables.h"
#include  "Display.h"
#include  "Functions.h"
#include  "CanBus.h"

    #ifdef CAN_SLAVE
 
    // Use software SPI: CS, DI, DO, CLK
    Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(10, 11, 12, 13);
    Adafruit_MAX31856 maxthermo_2 = Adafruit_MAX31856(7, 11, 12, 13);
    //Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(10);
    //Adafruit_MAX31856 maxthermo_2 = Adafruit_MAX31856(7);
    //Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(M1_CS, M1_SDI, M1_SDO, M1_SCK);
    //Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(10);
    //Adafruit_MAX31856 maxthermo_2 = Adafruit_MAX31856(M2_CS, M2_SDI, M2_SDO, M2_SCK);

    // use hardware SPI, just pass in the CS pin
    // use hardware SPI, pass in the CS pin and using SPI1
    
    #endif 


void setup() {
  MicroInit();
  //Serial.begin(115200);
 // while (!Serial) delay(10);
  IO_Set();
  delay(10);

  Can_Init();

    #ifdef  CAN_MASTER
        Can_Master();
    #endif
    #ifdef CAN_SLAVE
      Serial.println("MAX31856 thermocouple test");
      Thermo2_Init();
      Thermo1_Init();
      Can_Slave();
    #endif  
}


void loop() {
      Common_Loop(); 

    #ifdef  CAN_MASTER
        Can_Master();
    #endif
    #ifdef CAN_SLAVE
      Thermo1_Loop();
      Thermo2_Loop();

      Can_Slave();
    #endif  
  
}
