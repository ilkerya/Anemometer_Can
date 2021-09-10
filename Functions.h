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

  Serial.print(F("Compiled: "));
  Serial.println( __DATE__ ", " __TIME__ ", " __VERSION__); 
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
