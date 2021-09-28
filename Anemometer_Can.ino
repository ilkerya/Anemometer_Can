// This example demonstrates doing a one-shot measurement "manually".
// Separate calls are made to trigger the conversion and then check
// for conversion complete. While this typically only takes a couple
// 100 milliseconds, that times is made available by separating these
// two steps.

//#define DEBUG_MODE

#define CAN_MASTER
//#define CAN_SLAVE



#include  "Defs.h"
#include  "Variables.h"
#include  "Display.h"
#include  "Functions.h"
#include  "CanBus.h"

    #ifdef CAN_SLAVE

    // Use software SPI: CS, DI, DO, CLK

    Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(6, 7, 3, 5);   
    Adafruit_MAX31856 maxthermo_2 = Adafruit_MAX31856(10, 11, 12, 13);

    //Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(10);
    //Adafruit_MAX31856 maxthermo_2 = Adafruit_MAX31856(M2_CS, M2_SDI, M2_SDO, M2_SCK);

    // use hardware SPI, just pass in the CS pin
    // use hardware SPI, pass in the CS pin and using SPI1
    
    #endif 


void setup() {
  MicroInit();

  IO_Set();
  delay(10);

  Can_Init();

    #ifdef  CAN_MASTER
        Can_Master();
    #endif
    #ifdef CAN_SLAVE
      Serial.println("MAX31856 thermocouple test");
      Thermo1_Init();
      Thermo2_Init();
      Can_Slave();
    #endif  
}


void loop() {
  
//maxthermo_2.triggerOneShot();

      Common_Loop(); 

    #ifdef  CAN_MASTER
        Can_Master();
            delay(100);
            #ifndef DEBUG_MODE
       UI_Data();      
            #endif
    #endif
    #ifdef CAN_SLAVE
      Thermo1_Loop();
      Thermo2_Loop();


   //   AirFlow2 = analogRead(4);     
   //   Serial.print("   AirFlow2 : ");Serial.println(AirFlow2);
      

 //     AirFlow1 = analogRead(1);
 //     AirFlow2 = analogRead(3);  
      

      Can_Slave();
    #endif  
  
}
