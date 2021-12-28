int CRC8 = 0;

void updateByte(byte byt) {
  int polynomial8 = 0x0D5;
  CRC8 ^= byt;
  for (int i = 0; i < 8; i++) {
    if ((CRC8 & 0x80) != 0) {
      CRC8 = ((CRC8 << 1) ^ polynomial8);
    } else {
      CRC8 <<= 1;
    }
  }
  CRC8 &= 0xFF;
}

int calculateCRC8 (byte input[], int inputLength) {
  CRC8 = 0;
  for (int i = 0; i < inputLength; i++) {
    updateByte(input[i]);
  }
  return CRC8;
}



unsigned int calculateCRC16 (byte input[], int inputLength) {
  unsigned int crc16 = 0x0000;
  int polynomial = 0xA001;

  for (int i = 0; i < inputLength; i++) {
    unsigned int temp = (crc16 ^ input[i]) & 0xff;

    for (int i = 0; i < 8; i++) {

      if ((temp & 1) == 1) {
        temp = (temp >> 1) ^ polynomial;
      }
      else {
        temp = (temp >> 1);
      }
    }
    crc16 = (crc16 >> 8) ^ temp;
  }

  return crc16;
}

 long calculateCRC32(byte input[], int inputLength) {
  unsigned long crc32 = 0xffffffff;
  long polynomial = 0xEDB88320;

  for (int i = 0; i < inputLength; i++) {
    unsigned long temp = (crc32 ^ input[i]) & 0xff;

    for (int k = 0; k < 8; k++) {

      if ((temp & 1) == 1) {
        temp = (temp >> 1) ^ polynomial;
      }
      else {
        temp = (temp >> 1);
      }
    }
    crc32 = (crc32 >> 8) ^ temp;
  }

  return crc32 ^ 0xffffffff;
}


void sendJava (float* temp, float air, unsigned long canId) {
  /*
   String s = "";

    s += *temp; //temperature from sensor
    s += ",";
    s += air;   //airflow voltage from sensor (0 if sensor isn't connected)
    s += ",";
    s += canId; //node address/name


    const char * s2 = s.c_str();
    
    /*crc calculation, leave the needed method uncommented
    long crcCode = calculateCRC32((uint8_t const *)s2, s.length()); //CRC32
    //unsigned int crcCode = calculateCRC16((uint8_t const *)s2, s.length()); //CRC16
    //int crcCode = calculateCRC8((uint8_t const *)s2, s.length()); //CRC8

    String len = String (s.length());
    String crc1 = String(crcCode);

    s += ":";
    s += crc1; //c16, c32
    s += ":";
    s += len;
    s += ";";
    Serial.print(s);
    */
}

void ClearNodes(byte index){
       for(int i = 0; i < sizeof(Adr_Slave); i++ ){
          if (Adr_Slave[index] == Adr_Slave[i]){
                  switch(i){
                    case 0: Nodes.Adr_1 = OFF;
                    break;
                    case 1: Nodes.Adr_2 = OFF;
                    break;
                    case 2: Nodes.Adr_3 = OFF;
                    break;
                    case 3: Nodes.Adr_4 = OFF;
                    break;
                    case 4: Nodes.Adr_5 = OFF;
                    break;
                    case 5: Nodes.Adr_6 = OFF;
                    break;
                    case 6: Nodes.Adr_7= OFF;
                    break;   
                    case 7: Nodes.Adr_8 = OFF;
                    break;
                    case 8: Nodes.Adr_9 = OFF;
                    break;
                    case 9: Nodes.Adr_10 = OFF;
                    break;
                    case 10: Nodes.Adr_11 = OFF;
                    break;
                    case 11: Nodes.Adr_12 = OFF;
                    break;    
                    case 12: Nodes.Adr_13 = OFF;
                    break;
                    case 13: Nodes.Adr_14 = OFF;
                    break;
                    case 14: Nodes.Adr_15 = OFF;
                    break;
                    case 15: Nodes.Adr_16 = OFF;
                    break;   
                    case 16: Nodes.Adr_17 = OFF;
                    break;
                    case 17: Nodes.Adr_18 = OFF;
                    break;
                    deafult:
                    break;
                                                                                                                                                                                          
                }
         }
        /*
      Nodes.Adr_3 = OFF;Nodes.Adr_4 = OFF;Nodes.Adr_5 = OFF;
      Nodes.Adr_6 = OFF;Nodes.Adr_7 = OFF;Nodes.Adr_8 = OFF;Nodes.Adr_9 = OFF;Nodes.Adr_10 = OFF;
      Nodes.Adr_11 = OFF;Nodes.Adr_12 = OFF;Nodes.Adr_13 = OFF;Nodes.Adr_14 = OFF;Nodes.Adr_15 = OFF;
      Nodes.Adr_16 = OFF;Nodes.Adr_17 = OFF;Nodes.Adr_18 = OFF;
      */
    }
}
void PutArray_Air(uint16_t * Air, byte index){
       for(int i = 0; i < sizeof(Adr_Slave); i++ ){
          if (Adr_Slave[index] == Adr_Slave[i]){
                  switch(i){
                    case 0: 
                        AirFlow.Adr_1 = *Air;
                        AirFlow.Adr_2 = *++Air;                                                    
                    break;
                    case 1:
                        AirFlow.Adr_3 = *Air;
                        AirFlow.Adr_4 = *++Air;                 
                    break;
                     case 2:
                         AirFlow.Adr_5 = *Air;
                         AirFlow.Adr_6 = *++Air;                       
                    break;                   
                    case 3:
                         AirFlow.Adr_7 = *Air;
                         AirFlow.Adr_8 = *++Air;                                               
                    break;      
                    case 4:
                         AirFlow.Adr_9 = *Air;
                         AirFlow.Adr_10 = *++Air;                                               
                    break;
                     case 5:
                         AirFlow.Adr_11 = *Air;
                         AirFlow.Adr_12 = *++Air;                            
                    break;  
                     case 6:
                         AirFlow.Adr_13 = *Air;
                         AirFlow.Adr_14 = *++Air;                            
                    break;  
                     case 7:
                         AirFlow.Adr_15 = *Air;
                         AirFlow.Adr_16 = *++Air;                            
                    break;  
                     case 8:
                         AirFlow.Adr_17 = *Air;
                         AirFlow.Adr_18 = *++Air;                            
                    break;  
                     case 9:
                         AirFlow.Adr_19 = *Air;
                         AirFlow.Adr_20 = *++Air;                            
                    break; 
                     case 10:
                         AirFlow.Adr_21 = *Air;
                         AirFlow.Adr_22 = *++Air;                            
                    break; 
                     case 11:
                         AirFlow.Adr_23 = *Air;
                         AirFlow.Adr_24 = *++Air;                            
                    break; 
                     case 12:
                         AirFlow.Adr_25 = *Air;
                         AirFlow.Adr_26 = *++Air;                            
                    break; 
                     case 13:
                         AirFlow.Adr_27 = *Air;
                         AirFlow.Adr_28 = *++Air;                            
                    break; 
                     case 14:
                         AirFlow.Adr_29 = *Air;
                         AirFlow.Adr_30 = *++Air;                            
                    break; 
                     case 15:
                         AirFlow.Adr_31 = *Air;
                         AirFlow.Adr_32 = *++Air;                            
                    break; 
                     case 16:
                         AirFlow.Adr_33 = *Air;
                         AirFlow.Adr_34 = *++Air;                            
                    break; 
                      case 17:
                         AirFlow.Adr_35 = *Air;
                         AirFlow.Adr_36 = *++Air;                            
                    break;                                                    
                    default:
                    break;                                   
              }                   
         }            
    }    
}

void PutArray_Temp(float* Temp,byte index){     
      for(int i = 0; i < sizeof(Adr_Slave); i++ ){
          if (Adr_Slave[index] == Adr_Slave[i]){
                  switch(i){
                    case 0: 
                        Nodes.Adr_1 = ON;
                        ThermoCouple.Adr_1 = *Temp;
                        ThermoCouple.Adr_2 = *++Temp;                                   
                    break;
                    case 1:
                        Nodes.Adr_2 = ON;
                        ThermoCouple.Adr_3 = *Temp;
                        ThermoCouple.Adr_4 = *++Temp;                 
                    break;
                     case 2:
                      Nodes.Adr_3 = ON;               
                         ThermoCouple.Adr_5 = *Temp;
                         ThermoCouple.Adr_6 = *++Temp;                      
                    break;                   
                    case 3:
                        Nodes.Adr_4 = ON;                    
                        ThermoCouple.Adr_7 = *Temp;
                        ThermoCouple.Adr_8 = *++Temp;                          
                    break;      
                    case 4:
                          Nodes.Adr_5 = ON;                    
                          ThermoCouple.Adr_9 = *Temp;
                          ThermoCouple.Adr_10 = *++Temp;                           
                    break;
                     case 5:
                        Nodes.Adr_6 = ON;                     
                          ThermoCouple.Adr_11 = *Temp;
                          ThermoCouple.Adr_12 = *++Temp;                            
                    break;    
                     case 6:
                        Nodes.Adr_7 = ON;                     
                          ThermoCouple.Adr_13 = *Temp;
                          ThermoCouple.Adr_14 = *++Temp;                            
                    break;  
                    case 7: 
                        Nodes.Adr_8 = ON;
                        ThermoCouple.Adr_15 = *Temp;
                        ThermoCouple.Adr_16 = *++Temp;                                   
                    break;
                    case 8:
                        Nodes.Adr_9 = ON;
                        ThermoCouple.Adr_17 = *Temp;
                        ThermoCouple.Adr_18 = *++Temp;                 
                    break;
                     case 9:
                      Nodes.Adr_10 = ON;               
                         ThermoCouple.Adr_19 = *Temp;
                         ThermoCouple.Adr_20 = *++Temp;                      
                    break;                   
                    case 10:
                        Nodes.Adr_11 = ON;                    
                        ThermoCouple.Adr_21 = *Temp;
                        ThermoCouple.Adr_22 = *++Temp;                          
                    break;      
                    case 11:
                          Nodes.Adr_12 = ON;                    
                          ThermoCouple.Adr_23 = *Temp;
                          ThermoCouple.Adr_24 = *++Temp;                           
                    break;
                     case 12:
                        Nodes.Adr_13 = ON;                     
                          ThermoCouple.Adr_25 = *Temp;
                          ThermoCouple.Adr_26 = *++Temp;                            
                    break;    
                     case 13:
                        Nodes.Adr_14 = ON;                     
                          ThermoCouple.Adr_27 = *Temp;
                          ThermoCouple.Adr_28 = *++Temp;                            
                    break;  
                    case 14: 
                        Nodes.Adr_15 = ON;
                        ThermoCouple.Adr_29 = *Temp;
                        ThermoCouple.Adr_30 = *++Temp;                                   
                    break;
                    case 15:
                        Nodes.Adr_16 = ON;
                        ThermoCouple.Adr_31 = *Temp;
                        ThermoCouple.Adr_32 = *++Temp;                 
                    break;
                     case 16:
                      Nodes.Adr_17 = ON;               
                         ThermoCouple.Adr_33 = *Temp;
                         ThermoCouple.Adr_24 = *++Temp;                      
                    break;                   
                    case 17:
                        Nodes.Adr_18 = ON;                    
                        ThermoCouple.Adr_35 = *Temp;
                        ThermoCouple.Adr_36 = *++Temp;                          
                    break; 
                                   
                    default:
                    break;                                   
              }                   
         }            
    }              
}
             
void UI_Data(){
  //  Serial.println("UI");
    Serial.print("Th_1:  ");Serial.println(ThermoCouple.Adr_1);
    Serial.print("Th_2:  ");Serial.println(ThermoCouple.Adr_2);
    Serial.print("Th_3:  ");Serial.println(ThermoCouple.Adr_3);
    Serial.print("Th_4:  ");Serial.println(ThermoCouple.Adr_4);
    Serial.print("Th_5:  ");Serial.println(ThermoCouple.Adr_5);
    Serial.print("Th_6:  ");Serial.println(ThermoCouple.Adr_6);
    Serial.print("Th_7:  ");Serial.println(ThermoCouple.Adr_7);
    Serial.print("Th_8:  ");Serial.println(ThermoCouple.Adr_8);   
    Serial.print("Th_9:  ");Serial.println(ThermoCouple.Adr_9);
    Serial.print("Th_10: ");Serial.println(ThermoCouple.Adr_10);
    Serial.print("Th_11: ");Serial.println(ThermoCouple.Adr_11);
    Serial.print("Th_12: ");Serial.println(ThermoCouple.Adr_12);

    Serial.print("Th_13:  ");Serial.println(ThermoCouple.Adr_13);
    Serial.print("Th_14:  ");Serial.println(ThermoCouple.Adr_14);
    Serial.print("Th_15:  ");Serial.println(ThermoCouple.Adr_15);
    Serial.print("Th_16:  ");Serial.println(ThermoCouple.Adr_16);
    Serial.print("Th_17:  ");Serial.println(ThermoCouple.Adr_17);
    Serial.print("Th_18:  ");Serial.println(ThermoCouple.Adr_18);
    Serial.print("Th_19:  ");Serial.println(ThermoCouple.Adr_19);

    Serial.print("Th_20:  ");Serial.println(ThermoCouple.Adr_20);
    Serial.print("Th_21:  ");Serial.println(ThermoCouple.Adr_21);
    Serial.print("Th_22:  ");Serial.println(ThermoCouple.Adr_22);
    Serial.print("Th_23:  ");Serial.println(ThermoCouple.Adr_23);
    Serial.print("Th_24:  ");Serial.println(ThermoCouple.Adr_24);
    Serial.print("Th_25:  ");Serial.println(ThermoCouple.Adr_25);
    Serial.print("Th_26:  ");Serial.println(ThermoCouple.Adr_26);
    Serial.print("Th_27:  ");Serial.println(ThermoCouple.Adr_27);
    Serial.print("Th_28:  ");Serial.println(ThermoCouple.Adr_28);
    Serial.print("Th_29:  ");Serial.println(ThermoCouple.Adr_29);
    
    Serial.print("Th_30:  ");Serial.println(ThermoCouple.Adr_30);
    Serial.print("Th_31:  ");Serial.println(ThermoCouple.Adr_31); 
    Serial.print("Th_32:  ");Serial.println(ThermoCouple.Adr_32);
    Serial.print("Th_33:  ");Serial.println(ThermoCouple.Adr_33);
    Serial.print("Th_34:  ");Serial.println(ThermoCouple.Adr_34);
    Serial.print("Th_35:  ");Serial.println(ThermoCouple.Adr_35);   
    Serial.print("Th_36:  ");Serial.println(ThermoCouple.Adr_36);   

    Serial.print("Af_1:  ");Serial.println(AirFlow.Adr_1);
    Serial.print("Af_2:  ");Serial.println(AirFlow.Adr_2);
    Serial.print("Af_3:  ");Serial.println(AirFlow.Adr_3);
    Serial.print("Af_4:  ");Serial.println(AirFlow.Adr_4);
    Serial.print("Af_5:  ");Serial.println(AirFlow.Adr_5);
    Serial.print("Af_6:  ");Serial.println(AirFlow.Adr_6);
    Serial.print("Af_7:  ");Serial.println(AirFlow.Adr_7);
    Serial.print("Af_8:  ");Serial.println(AirFlow.Adr_8);   
    Serial.print("Af_9:  ");Serial.println(AirFlow.Adr_9);
    Serial.print("Af_10: ");Serial.println(AirFlow.Adr_10);
    Serial.print("Af_11: ");Serial.println(AirFlow.Adr_11);
    Serial.print("Af_12: ");Serial.println(AirFlow.Adr_12);
    Serial.print("Af_13: ");Serial.println(AirFlow.Adr_13);
    Serial.print("Af_14: ");Serial.println(AirFlow.Adr_14);
    Serial.print("Af_15: ");Serial.println(AirFlow.Adr_15);
    Serial.print("Af_16: ");Serial.println(AirFlow.Adr_16);
    Serial.print("Af_17: ");Serial.println(AirFlow.Adr_17);
    Serial.print("Af_18: ");Serial.println(AirFlow.Adr_18);
    Serial.print("Af_19: ");Serial.println(AirFlow.Adr_19);
    Serial.print("Af_20:  ");Serial.println(AirFlow.Adr_20);   
    Serial.print("Af_21:  ");Serial.println(AirFlow.Adr_21);
    Serial.print("Af_22:  ");Serial.println(AirFlow.Adr_22);     
    Serial.print("Af_23:  ");Serial.println(AirFlow.Adr_23);
    Serial.print("Af_24:  ");Serial.println(AirFlow.Adr_24);
    Serial.print("Af_25:  ");Serial.println(AirFlow.Adr_25);     
    Serial.print("Af_26:  ");Serial.println(AirFlow.Adr_26);
    Serial.print("Af_27:  ");Serial.println(AirFlow.Adr_27);
    Serial.print("Af_28:  ");Serial.println(AirFlow.Adr_28);     
    Serial.print("Af_29:  ");Serial.println(AirFlow.Adr_29);    
    Serial.print("Af_30:  ");Serial.println(AirFlow.Adr_30);
    Serial.print("Af_31:  ");Serial.println(AirFlow.Adr_31);
    Serial.print("Af_32:  ");Serial.println(AirFlow.Adr_32);
    Serial.print("Af_33:  ");Serial.println(AirFlow.Adr_33);
    Serial.print("Af_34:  ");Serial.println(AirFlow.Adr_34);
    Serial.print("Af_35:  ");Serial.println(AirFlow.Adr_35);    
    Serial.print("Af_36:  ");Serial.println(AirFlow.Adr_36);
  
}

void IO_Set(void){
  pinMode(MCP2515_SPI_CS, OUTPUT);   
  pinMode(TFCARD_SPI_CS, OUTPUT);  
  
  digitalWrite(MCP2515_SPI_CS, HIGH);      
  digitalWrite(TFCARD_SPI_CS, HIGH);  
  /*
  pinMode(M1_CS, OUTPUT);               
  pinMode(M1_SDI, INPUT);               
  pinMode(M1_SDO, OUTPUT);   
  pinMode(M1_SCK, OUTPUT);  

  pinMode(M2_CS, OUTPUT);               
  pinMode(M2_SDI, OUTPUT);               
  pinMode(M2_SDO, INPUT);   
  pinMode(M2_SCK, OUTPUT);  

    digitalWrite(M2_CS, HIGH);      
    digitalWrite(M2_SDI, HIGH);         
    digitalWrite(M2_SDO, HIGH);      
    digitalWrite(M2_SCK, HIGH);      
 */     
}

void IO_Settings() {

#ifdef ARDUINO_MKRZERO
  digitalWrite(OLED_GND, LOW);
  pinMode(OLED_GND, OUTPUT);  // 

  pinMode(A4, INPUT);  
  digitalWrite(OLED_CS, LOW);
  pinMode(OLED_CS, OUTPUT);  //
   digitalWrite(OLED_RESET, LOW);
  pinMode(OLED_RESET, OUTPUT);  // 

  digitalWrite(OLED_DC, LOW);
  pinMode(OLED_DC, OUTPUT);  // 
  digitalWrite(OLED_CLK, LOW);
  pinMode(OLED_CLK, OUTPUT);  // 
  digitalWrite(OLED_MOSI, LOW);
  pinMode(OLED_MOSI, OUTPUT);  // 

  digitalWrite(OLED_POWER, HIGH);
  pinMode(OLED_POWER, OUTPUT);  // 
  
#endif
}

// interrupt vector
   // #ifdef ARDUINO_MEGA
ISR(TIMER1_OVF_vect){        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
 //   TCNT1 = 34286;            // preload timer for 500mSec
       TCNT1 = 64286;            // preload timer for 20mSec
   // #endif
    
    Loop.IntTimer_250++;
    Loop.IntTimer_500 ++;
    Loop.IntTimer_1 ++;
    Loop.IntTimer_2 ++;
    Loop.IntTimer_5 ++;
    Loop.IntTimer_10 ++;
    Loop.IntTimer_20 ++;   
    Loop.IntTimer_60 ++;   

#define CAN_TIMEOUT 4 // 4*20ms = 80mS

   #ifdef CAN_MASTER
        CanTimeOut_Timer++;
        if(CanTimeOut_Timer >= CAN_TIMEOUT)CanTimeOut_Flag = 1;
  
      #endif 
    
   #ifdef CAN_SLAVE
   
    if(Thermo1.Mode == T_WAIT_1){
      if(Thermo1.DelayTimer != 0){
        Thermo1.DelayTimer--;
      }
      else Thermo1.Mode = T_CONV_1; 
    }
    if(Thermo1.Mode == T_WAIT_2){
      if(Thermo1.FreqTimer != 0){
        Thermo1.FreqTimer--;
      }
      else Thermo1.Mode = T_INIT_1; 
    }
    
    if(Thermo2.Mode == T_WAIT_1){
      if(Thermo2.DelayTimer != 0){
        Thermo2.DelayTimer--;
      }
      else Thermo2.Mode = T_CONV_1; 
    }
    if(Thermo2.Mode == T_WAIT_2){
      if(Thermo2.FreqTimer != 0){
        Thermo2.FreqTimer--;
      }
      else Thermo2.Mode = T_INIT_1; 
    }  

    #endif  

    if(Loop.IntTimer_250 >= 13){
      Loop.IntTimer_250 = 0;
      Loop.Task_250msec = ON;
    }
    if(Loop.IntTimer_500 >= 25){ // 500 msec
      Loop.IntTimer_500 = 0;
      Loop.Task_500msec = ON;  
    }
    if(Loop.IntTimer_1 >= 50){  // 1 sec
      Loop.IntTimer_1 = 0;
      Loop.Task_1Sec = ON;
      //digitalWrite(LED_GREEN, digitalRead(LED_GREEN) ^ 1);  
 
      if(Display.SleepEnable == ON){
        if(Display.OLED_Timer) Display.OLED_Timer--;   // sleep active
      }
      else Display.OLED_Timer = 32768; // no sleep    
      if(Display.InitDelay == OFF)Display.InitDelay = ON;           
    }
    if(Loop.IntTimer_2 >= 100){ // 2 sec
      Loop.IntTimer_2 = 0;
      Loop.Task_2Sec = ON;
      //PrintDisplayBuffer();
    }
    if(Loop.IntTimer_5 >= 250){  // 5 sec
      Loop.IntTimer_5 = 0;
      Loop.Task_5Sec = ON;
    }
    if(Loop.IntTimer_10 >= 500){  // 10 sec
      Loop.IntTimer_10 = 0;
      Loop.Task_10Sec = ON;
    }
    if(Loop.IntTimer_20 >= 1000){  // 20 sec
      Loop.IntTimer_20 = 0;
      Loop.Task_20Sec = ON;
    }
    if(Loop.IntTimer_60 >= 3000){  // 60 sec
      Loop.IntTimer_60 = 0;
      Loop.Task_60Sec = ON;
    }        
} // end of interrupt func
void Common_Loop(){
  if (Loop.Task_250msec) {
    Loop.Task_250msec = OFF;

    // One time after wake up form sleep
    if (Display.OLED_Init == ON) {
      Display_ReInit_Start(20);
      Display.OLED_Init = OFF;
    }
    if (Display.OLED_Timer) {
      displayValues();
    }
    else {
      Display_SwitchOff();
    }
    Display_ReInit_End();
  }
  if (Loop.Task_500msec) {
    Loop.Task_500msec = OFF;
  }
  if (Loop.Task_1Sec) {
    Loop.Task_1Sec = OFF;
    Counter++;
           //     digitalWrite(RELAY_OUT_2, digitalRead(RELAY_OUT_2) ^ 1);  
  }  
  if (Loop.Task_2Sec) {
    Loop.Task_2Sec = OFF;
  }
  if (Loop.Task_5Sec) {
    Loop.Task_5Sec = OFF; 
  //  Display.ValueTimer++;
  //  if (Display.ValueTimer > 4)Display.ValueTimer = 0;
  }
  if (Loop.Task_10Sec) {
    Loop.Task_10Sec = OFF;
  }
  if (Loop.Task_20Sec) {
    Loop.Task_20Sec = OFF;
  }
  if (Loop.Task_60Sec) {
    Loop.Task_60Sec = OFF;
  }
}
void MicroInit() {
 // Display_Line4[5] ='\0';
  Serial.begin(115200);



  
  IO_Settings();
  DisplaySetPowerIO();
 // Serial.print(F("    DisplaySleep: "));
 // Serial.println(Display.SleepEnable);

#ifdef ARDUINO_MEGA
 // wdt_reset();
 // wdt_enable(WDTO_8S);   //wdt_enable(WDT0_1S);
  //https://www.nongnu.org/avr-libc/user-manual/group__avr__watchdog.html
#endif

//  ADCSRA &= ~ (1 << ADEN);            // turn off ADC to save power ,, enable when needed and turn off again
    ADCSRA |= (1 << ADEN); // enable adc
   #ifdef DEBUG_MODE
  Serial.print(F("Compiled: "));
  Serial.println( __DATE__ ", " __TIME__ ", " __VERSION__); 
  #endif
 // Serial.println( F("Compiled: ") __DATE__ ", " __TIME__ ", " __VERSION__);
  //Compiled: Jul 21 2020 15:55:39 7.3.0
  //  ShowSerialCode();
  DisplayInit();   
 // #endif
  // initialize timer1
    noInterrupts();           // disable all interrupts
    TCCR1A = 0;
    TCCR1B = 0;
    //    TCNT1 = 34286;            // preload timer 65536-16MHz/256/2Hz 500mS
    TCNT1 = 64286;            // preload timer 65536-16MHz/256/50Hz 20 ms
    TCCR1B |= (1 << CS12);    // 256 prescaler
    TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
    interrupts();
}
// check if only one Slave Selected otherwise print problem and halt
void Slave_Def_Check(){ 
 
    unsigned int SlaveCount = 0;
  
    #if defined (SLAVE_01) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_02) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_03) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_04) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_05) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_06) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_07) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_08) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_09) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_10) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_11) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_12) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_13) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_14) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_15) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_16) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_17) 
      SlaveCount++;
    #endif
    #if defined (SLAVE_18) 
      SlaveCount++;
    #endif
 
  if(SlaveCount != 1){ // create run time error if only one not selected in Micro Init
    Serial.println("Select Only One Slave Address and recompile !!!");
    while(1);
  }
 
}
