
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin

void Can_Init(){
    while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k CAN_500KBPS
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
      #ifdef DEBUG_MODE
    Serial.println("CAN init ok!");
      #endif

      #ifdef  CAN_MASTER
            #ifdef DEBUG_MODE
          Serial.println("Master");
           #endif
      #endif
   
      #ifdef CAN_SLAVE
          #ifdef SLAVE_01
          resp_buf[7]  = SLAVE_01;
          #endif 
          #ifdef SLAVE_02
          resp_buf[7]  = SLAVE_02;
          #endif 
          #ifdef SLAVE_03
          resp_buf[7]  = SLAVE_03;
          #endif 
          #ifdef SLAVE_04
          resp_buf[7]  = SLAVE_04;
          #endif 
          #ifdef SLAVE_05
          resp_buf[7]  = SLAVE_05;
          #endif 
          #ifdef SLAVE_06
          resp_buf[7]  = SLAVE_06;
          #endif 

          #ifdef SLAVE_07
          resp_buf[7]  = SLAVE_07;
          #endif 
          #ifdef SLAVE_08
          resp_buf[7]  = SLAVE_08;
          #endif 
          #ifdef SLAVE_09
          resp_buf[7]  = SLAVE_09;
          #endif 
          #ifdef SLAVE_10
          resp_buf[7]  = SLAVE_10;
          #endif 
          #ifdef SLAVE_11
          resp_buf[7]  = SLAVE_11;
          #endif 
          #ifdef SLAVE_12
          resp_buf[7]  = SLAVE_12;
          #endif 

          #ifdef SLAVE_13
          resp_buf[7]  = SLAVE_13;
          #endif 
          #ifdef SLAVE_14
          resp_buf[7]  = SLAVE_14;
          #endif 
          #ifdef SLAVE_15
          resp_buf[7]  = SLAVE_15;
          #endif 
          #ifdef SLAVE_16
          resp_buf[7]  = SLAVE_16;
          #endif 
          #ifdef SLAVE_17
          resp_buf[7]  = SLAVE_17;
          #endif 
          #ifdef SLAVE_18
          resp_buf[7]  = SLAVE_18;
          #endif 
          
      //     resp_buf[7]++;
          SlaveAdr = resp_buf[7] ;
           
          Serial.println("Slave");
          Serial.print("Adr:");
          Serial.println(resp_buf[7]);   
          Serial.println(SlaveAdr);               
      #endif  
}

void Can_Master(){
  /*
    // send data:  id = 0x00, standrad frame, data len = 8, stmp: data buf
    stmp[7] = stmp[7] + 1;
    if (stmp[7] == 100) {
        stmp[7] = 0;
        stmp[6] = stmp[6] + 1;

        if (stmp[6] == 100) {
            stmp[6] = 0;
            stmp[5] = stmp[5] + 1;
        }
    }
         */

    stmp[0] = 'S'; //53
    stmp[1] = 'e'; //65
    stmp[2] = 'n'; //6E
    stmp[3] = 'd'; //64
    stmp[4] = 'S'; //53
    stmp[5] = 'e'; //65
    stmp[6] = 'n'; //6E
    stmp[7] = 'd'; //64
          #ifdef DEBUG_MODE
      Serial.print("Slave Req Adr From Master : ");
      Serial.println(Adr_Slave[Adr_index]);
          #endif 
    CAN.sendMsgBuf(Adr_Slave[Adr_index], 0, 8, stmp);// adr 0X00
            //  delay(100);  // send data per 100ms 30ms sorunlu 
   CanTimeOut_Timer = 0;
   CanTimeOut_Flag = 0;   
   while (CAN_MSGAVAIL != CAN.checkReceive() && !CanTimeOut_Flag) {} // needs timeout!!!!
           #ifdef DEBUG_MODE
            Serial.print("Can Timeout 1.Frame:  ");Serial.println(CanTimeOut_Timer);
           #endif 
  ClearNodes(Adr_index); 
  if(CanTimeOut_Flag){ // if  timeout
          #ifdef DEBUG_MODE
          Serial.print("No Resp From Adr: ");Serial.println(Adr_Slave[Adr_index]);
         #endif 
  }   
  else { // if no timeout
   // if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
          CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
          unsigned long canId = CAN.getCanId();
              #ifdef DEBUG_MODE
          Serial.print("Adr:");
          Serial.print(canId, DEC);   
            #endif 
          if(canId != Adr_Slave[Adr_index]){
                #ifdef DEBUG_MODE
               Serial.println("-----------------------------");
                Serial.println("Adr Error"); 
                #endif 
                
          }
          else {
            float* Th1_New =(float*) &buf[0];
                #ifdef DEBUG_MODE
              Serial.print(" Th1 :");
              Serial.print(*Th1_New);          
                 #endif 

              Th1_New =(float*) &buf[4];
                  #ifdef DEBUG_MODE
              Serial.print("   Th2 :");
              Serial.println(*Th1_New);
                  #endif                   
              PutArray_Temp((float*) &buf[0], Adr_index );                             
        }
    }
    //SERIAL_PORT_MONITOR.println("CAN BUS sendMsgBuf ok!");
          #ifdef DEBUG_MODE
      Serial.print("Slave Req Adr From Master : ");
      Serial.println(Adr_Slave[Adr_index]+1);
          #endif 
    // Req from next address   
   CAN.sendMsgBuf(Adr_Slave[Adr_index]+1, 0, 8, stmp);// adr 0X00
            // delay(100);
   CanTimeOut_Timer = 0;
   CanTimeOut_Flag = 0;   
   while (CAN_MSGAVAIL != CAN.checkReceive() && !CanTimeOut_Flag) {}
        #ifdef DEBUG_MODE
      Serial.print("Can Timeout 2.Frame:  ");Serial.println(CanTimeOut_Timer);
           #endif   
   if(CanTimeOut_Flag){ // if  timeout
        #ifdef DEBUG_MODE
            Serial.print("No Resp From Adr: ");Serial.println(Adr_Slave[Adr_index]+1);  
          #endif 
  }   
  else{
          CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
          unsigned long canId = CAN.getCanId();
              #ifdef DEBUG_MODE
          Serial.print("Adr:");
          Serial.print(canId, DEC);
            #endif             
          if(canId != Adr_Slave[Adr_index]+1){
                #ifdef DEBUG_MODE
               Serial.println("-----------------------------");
                Serial.println("Adr Error"); 
                #endif 
          }
          else {
           uint16_t* AirFlow =(uint16_t* ) &buf[0];
                  #ifdef DEBUG_MODE
              Serial.print(" AirFlow1 :");
              Serial.print(*AirFlow);
                #endif 
              AirFlow =(uint16_t*) &buf[2];
                  #ifdef DEBUG_MODE
              Serial.print("   AirFlow2 :");
              Serial.println(*AirFlow);
                #endif 
              PutArray_Air((uint16_t*) &buf[0], Adr_index );    
        }
    }
     Adr_index++;
    if(Adr_index > (sizeof(Adr_Slave)-1))Adr_index=0;
}

void Can_Slave(){
    if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
          CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

          unsigned long canId = CAN.getCanId();

          Serial.println("-----------------------------");
          Serial.print("Get data from ID: 0x");
          Serial.println(canId, HEX);

          for (int i = 0; i < len; i++) { // print the data
              Serial.print(buf[i], HEX);
              Serial.print("\t");
          }
          Serial.println();
          byte AdrTemp = 0;
          #ifdef SLAVE_01
              AdrTemp =  SLAVE_01;
          #endif 
          #ifdef SLAVE_02
              AdrTemp = SLAVE_02;
          #endif 
          #ifdef SLAVE_03
              AdrTemp = SLAVE_03;
          #endif 
          #ifdef SLAVE_04
              AdrTemp =  SLAVE_04;
          #endif 
          #ifdef SLAVE_05
              AdrTemp = SLAVE_05;
          #endif 
          #ifdef SLAVE_06
              AdrTemp = SLAVE_06;
          #endif 
          #ifdef SLAVE_07
              AdrTemp =  SLAVE_07;
          #endif 
          #ifdef SLAVE_08
              AdrTemp = SLAVE_08;
          #endif 
          #ifdef SLAVE_09
              AdrTemp = SLAVE_09;
          #endif 
          #ifdef SLAVE_10
              AdrTemp =  SLAVE_10;
          #endif 
          #ifdef SLAVE_11
              AdrTemp = SLAVE_11;
          #endif 
          #ifdef SLAVE_12
              AdrTemp = SLAVE_12;
          #endif 
          #ifdef SLAVE_13
              AdrTemp =  SLAVE_13;
          #endif 
          #ifdef SLAVE_14
              AdrTemp = SLAVE_14;
          #endif 
          #ifdef SLAVE_15
              AdrTemp = SLAVE_15;
          #endif 
          #ifdef SLAVE_16
              AdrTemp =  SLAVE_16;
          #endif 
          #ifdef SLAVE_17
              AdrTemp = SLAVE_17;
          #endif 
          #ifdef SLAVE_18
              AdrTemp = SLAVE_18;
          #endif 

        if (canId == AdrTemp){
            unsigned  char *p =(unsigned  char*) &Thermo1.Temp;
            resp_buf[0]= *p;
            resp_buf[1]= *(p+1);
            resp_buf[2]= *(p+2);
            resp_buf[3]= *(p+3);   

             p =(unsigned  char*) &Thermo2.Temp;
            resp_buf[4]= *p;
            resp_buf[5]= *(p+1);
            resp_buf[6]= *(p+2);
            resp_buf[7]= *(p+3);
                           
           CAN.sendMsgBuf(canId, 0, 8, resp_buf);// adr 0X00
           
           Serial.print("Responce Send with Adr : ");
           Serial.println(canId);           
        }
        if (canId == (AdrTemp+1)){
          //AirFlow1
            unsigned  char *p =(unsigned  char*) &AirFlow1;
            resp_buf[0]= *p;
            resp_buf[1]= *(p+1);
       //     resp_buf[2]= *(p+2);
       //     resp_buf[3]= *(p+3);   

             p =(unsigned  char*) &AirFlow2;
            resp_buf[2]= *p;
            resp_buf[3]= *(p+1);
        //    resp_buf[6]= *(p+2);
       //     resp_buf[7]= *(p+3);
                           
           CAN.sendMsgBuf(canId, 0, 8, resp_buf);// adr 

           Serial.print("Responce Send with Adr : ");
           Serial.println(canId);
        }
 
       //     delay(100);
       //     delay((CAN_TIMEOUT*20)/2); // take half of the timeout                                   
  }
}
