
    #ifdef CAN_SLAVE

void Thermo1_Loop(void){
     switch(Thermo1.Mode){
    case T_INIT_1: 
           AirFlow1 = analogRead(2);              
           Serial.print("AirFlow1 : ");Serial.print(AirFlow1);      
          maxthermo_1.triggerOneShot(); 
          Thermo1.Mode++;
    break;
    case T_INIT_2:
            Thermo1.DelayTimer = 55;
            Thermo1.Mode++;
    break;    
    case T_WAIT_1:
            /// wait
    break; 
    case T_CONV_1:
           Thermo1_Conversion();
           Thermo1.Mode++;
    break;
    case T_CONV_2:

           Thermo1.FreqTimer = 25;
           Thermo1.Mode++;
    break;
    case T_WAIT_2: // wait
          //Thermo1.Mode = 0;
    break; 
    default:
    break;    
   }
}

void Thermo2_Loop(void){
     switch(Thermo2.Mode){
    case T_INIT_1: 
            AirFlow2 = analogRead(4);              
           Serial.print("  AirFlow2 : ");Serial.println(AirFlow2);   
          maxthermo_2.triggerOneShot(); 
          Thermo2.Mode++;
    break;
    case T_INIT_2:
            Thermo2.DelayTimer = 55;
            Thermo2.Mode++;
    break;    
    case T_WAIT_1:
            /// wait
    break; 
    case T_CONV_1:
           Thermo2_Conversion();
           Thermo2.Mode++;
    break;
    case T_CONV_2:
           Thermo2.FreqTimer = 25;
           Thermo2.Mode++;
    break;
    case T_WAIT_2: // wait

          //Thermo1.Mode = 0;
    break;
    default:
    break;    
   } 
}


void Thermo1_Init(void){
  if (!maxthermo_1.begin()) {
    Serial.println("Could not initialize thermocouple.");
    while (1) delay(10);
  }
  Thermo1.Mode = T_INIT_1;
  maxthermo_1.setThermocoupleType(MAX31856_TCTYPE_K);
  delay(10);
  Serial.print("Thermocouple type_1: ");
  switch (maxthermo_1.getThermocoupleType() ) {
    case MAX31856_TCTYPE_B: Serial.println("B Type"); break;
    case MAX31856_TCTYPE_E: Serial.println("E Type"); break;
    case MAX31856_TCTYPE_J: Serial.println("J Type"); break;
    case MAX31856_TCTYPE_K: Serial.println("K Type"); break;
    case MAX31856_TCTYPE_N: Serial.println("N Type"); break;
    case MAX31856_TCTYPE_R: Serial.println("R Type"); break;
    case MAX31856_TCTYPE_S: Serial.println("S Type"); break;
    case MAX31856_TCTYPE_T: Serial.println("T Type"); break;
    case MAX31856_VMODE_G8: Serial.println("Voltage x8 Gain mode"); break;
    case MAX31856_VMODE_G32: Serial.println("Voltage x8 Gain mode"); break;
    default: Serial.println("Unknown"); break;
  }
  maxthermo_1.setConversionMode(MAX31856_ONESHOT_NOWAIT);
  
}


void Thermo2_Init(void){
    if (!maxthermo_2.begin()) {
    Serial.println("Could not initialize thermocouple.");
    while (1) delay(10);
  }
 Thermo2.Mode = T_INIT_1;
  maxthermo_2.setThermocoupleType(MAX31856_TCTYPE_K);
  delay(10);
  Serial.print("Thermocouple type_2: ");
  switch (maxthermo_2.getThermocoupleType() ) {
    case MAX31856_TCTYPE_B: Serial.println("B Type"); break;
    case MAX31856_TCTYPE_E: Serial.println("E Type"); break;
    case MAX31856_TCTYPE_J: Serial.println("J Type"); break;
    case MAX31856_TCTYPE_K: Serial.println("K Type"); break;
    case MAX31856_TCTYPE_N: Serial.println("N Type"); break;
    case MAX31856_TCTYPE_R: Serial.println("R Type"); break;
    case MAX31856_TCTYPE_S: Serial.println("S Type"); break;
    case MAX31856_TCTYPE_T: Serial.println("T Type"); break;
    case MAX31856_VMODE_G8: Serial.println("Voltage x8 Gain mode"); break;
    case MAX31856_VMODE_G32: Serial.println("Voltage x8 Gain mode"); break;
    default: Serial.println("Unknown"); break;
  }
  maxthermo_2.setConversionMode(MAX31856_ONESHOT_NOWAIT);
}
uint8_t Fault_Detect(uint8_t fault){
  uint8_t FaultNo;
  if (fault){
    if (fault & MAX31856_FAULT_CJRANGE) FaultNo = 1;
    if (fault & MAX31856_FAULT_TCRANGE) FaultNo = 2;
    if (fault & MAX31856_FAULT_CJHIGH)  FaultNo = 3;
    if (fault & MAX31856_FAULT_CJLOW)   FaultNo = 4;
    if (fault & MAX31856_FAULT_TCHIGH)  FaultNo = 5;
    if (fault & MAX31856_FAULT_TCLOW)   FaultNo = 6;
    if (fault & MAX31856_FAULT_OVUV)    FaultNo = 7;
    if (fault & MAX31856_FAULT_OPEN)    FaultNo = 8;
  }
  else FaultNo = 0;
  char buffer[21];
  strcpy_P(buffer, (char *)pgm_read_word(&(TH_ERR_TABLE[FaultNo])));  // Necessary casts and dereferencing, just copy.
  Serial.println(buffer);
  return FaultNo;
}
void Thermo1_Conversion(void){
    // check for conversion complete and read temperature
  if (maxthermo_1.conversionComplete()) {
     Thermo1.Temp = maxthermo_1.readThermocoupleTemperature();
     Serial.print(Thermo1.Temp);    
    
    //Serial.print(maxthermo_1.readThermocoupleTemperature());
    Serial.print(" 'C for 1.");
      Serial.print("/   Cold_1: ");
       Thermo1.J_Temp = maxthermo_1.readCJTemperature();
     Serial.println(Thermo1.J_Temp);    
     // Serial.println(maxthermo_1.readCJTemperature());
  }
  else {
    Serial.println("Conversion not complete Reinit Th1!");
    Thermo1_Init();
    //delay(100);
  }
   Thermo1.Fault =  Fault_Detect(maxthermo_1.readFault());
        /*
            unsigned  char *p =(unsigned  char*) &Thermo1.Temp;
            Th1_arr[0]= *p;
            Th1_arr[1]= *(p+1);
            Th1_arr[2]= *(p+2);
            Th1_arr[3]= *(p+3);    

           Th1_New =(float*) &Th1_arr;

          Serial.print("Th1_New  : "); Serial.println(*Th1_New); 
          */
}

void Thermo2_Conversion(void){
  // check for conversion complete and read temperature
  if (maxthermo_2.conversionComplete()) {
   //    Serial.print(maxthermo_2.readThermocoupleTemperature());   
     Thermo2.Temp = maxthermo_2.readThermocoupleTemperature();
     Serial.print(Thermo2.Temp); 
    
  //  Serial.print(maxthermo_2.readThermocoupleTemperature());
    Serial.print(" 'C for 2.");
    Serial.print("/   Cold_2: ");
    Thermo2.J_Temp = maxthermo_2.readCJTemperature();
     Serial.print(Thermo2.J_Temp);   
    //Serial.println(maxthermo_2.readCJTemperature());

      Serial.print("  Slave Adr:");
      Serial.println(SlaveAdr);   //10
  } 
  else {
    Serial.println("Conversion not complete Reinit Th2!");
    Thermo2_Init();
    //delay(100);
  }
  Thermo2.Fault =  Fault_Detect(maxthermo_2.readFault());
}

    #endif 

    
