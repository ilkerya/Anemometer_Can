// This example demonstrates doing a one-shot measurement "manually".
// Separate calls are made to trigger the conversion and then check
// for conversion complete. While this typically only takes a couple
// 100 milliseconds, that times is made available by separating these
// two steps.
#define VERSION_SLAVE  1.12 
#define VERSION_MASTER 1.20 

#include  "Defs.h"
#include  "Variables.h"
#include  "Display.h"
#include  "Functions.h"
#include  "CanBus.h"

    #ifdef CAN_SLAVE

    // Use software SPI: CS, DI, DO, CLK

  //  Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(6, 7, 3, 5);  // AirFlowV1 PCB
    Adafruit_MAX31856 maxthermo_2 = Adafruit_MAX31856(3, 5, 6, 7);  // AirFlowV2 PCB
     
    Adafruit_MAX31856 maxthermo_1 = Adafruit_MAX31856(10, 11, 12, 13);

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
      Can_Master(); // Init for Master Mode
    #endif
    #ifdef CAN_SLAVE  // Init  for Slave  Mode
      Serial.println("MAX31856 thermocouple test");
      Thermo1_Init();
      Thermo2_Init();
      Can_Slave();
    #endif  
}


void loop() {
     Common_Loop(); 
    #ifdef  CAN_MASTER // SuperLoop Only for Master Mode
        Can_Master();
            delay(100);
            #ifndef DEBUG_MODE
              UI_Data();      
            #endif
    #endif

    
    #ifdef CAN_SLAVE  // SuperLoop Only for Slave  Mode
      Thermo1_Loop();
      Thermo2_Loop();

    //maxthermo_2.triggerOneShot();
   //   AirFlow2 = analogRead(4);     
   //   Serial.print("   AirFlow2 : ");Serial.println(AirFlow2);    
    //     AirFlow1 = analogRead(1);
    //     AirFlow2 = analogRead(3);  
      
      Can_Slave();
      Slave_Def_Check();
    #endif  
  
}
