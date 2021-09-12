

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


void PutArray(float* Temp,byte index, bool Type){     

     
      for(int i = 0; i < sizeof(Adr_Slave); i++ ){
          if (Adr_Slave[index] == Adr_Slave[i]){
                  switch(i){
                    case 0: 
                        Nodes.Adr_1 = ON;
                      if(Type == THERMOCOUPLE){
                        ThermoCouple.Adr_1 = *Temp;
                        ThermoCouple.Adr_2 = *++Temp;
                      } 
                      if(Type == AIRFLOW){
                        AirFlow.Adr_1 = *Temp;
                        AirFlow.Adr_2 = *++Temp;
                      }                                      
                    break;
                    case 1:
                        Nodes.Adr_2 = ON;
                       if(Type == THERMOCOUPLE){
                        ThermoCouple.Adr_3 = *Temp;
                        ThermoCouple.Adr_4 = *++Temp;
                       }
                       if(Type == AIRFLOW){
                        AirFlow.Adr_3 = *Temp;
                        AirFlow.Adr_4 = *++Temp;
                      }                   
                    break;
                     case 2:
                      Nodes.Adr_3 = ON;
                       if(Type == THERMOCOUPLE){                   
                         ThermoCouple.Adr_5 = *Temp;
                         ThermoCouple.Adr_6 = *++Temp;
                       }
                       if(Type == AIRFLOW){
                         AirFlow.Adr_5 = *Temp;
                         AirFlow.Adr_6 = *++Temp;
                      }                         
                    break;                   
                    case 3:
                        Nodes.Adr_4 = ON;
                       if(Type == THERMOCOUPLE){                      
                        ThermoCouple.Adr_7 = *Temp;
                        ThermoCouple.Adr_8 = *++Temp;
                       }
                       if(Type == AIRFLOW){
                         AirFlow.Adr_7 = *Temp;
                         AirFlow.Adr_8 = *++Temp;
                      }                           
                    break;      
                    case 4:
                          Nodes.Adr_5 = ON;
                        if(Type == THERMOCOUPLE){                      
                          ThermoCouple.Adr_9 = *Temp;
                          ThermoCouple.Adr_10 = *++Temp;
                       }
                       if(Type == AIRFLOW){
                         AirFlow.Adr_9 = *Temp;
                         AirFlow.Adr_10 = *++Temp;
                      }                           
                    break;
                     case 5:
                        Nodes.Adr_6 = ON;
                       if(Type == THERMOCOUPLE){                      
                          ThermoCouple.Adr_11 = *Temp;
                          ThermoCouple.Adr_12 = *++Temp;
                       }
                       if(Type == AIRFLOW){
                         AirFlow.Adr_11 = *Temp;
                         AirFlow.Adr_12 = *++Temp;
                      }                             
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
