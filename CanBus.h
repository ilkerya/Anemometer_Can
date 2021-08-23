
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin

void Can_Init(){
    while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
    Serial.println("CAN init ok!");
      #ifdef  CAN_MASTER
          Serial.println("Master");
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
           resp_buf[7]++;
          SlaveAdr = resp_buf[7] ;
           
          Serial.println("Slave");
          Serial.print("Adr:");
          Serial.println(resp_buf[7]);       
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
    Serial.print("Slave Req Adr From Master : ");
    Serial.println(Adr_Slave[Adr_index]);
    
    CAN.sendMsgBuf(Adr_Slave[Adr_index], 0, 8, stmp);// adr 0X00
    Adr_index++;
    if(Adr_index > (sizeof(Adr_Slave)-1))Adr_index=0;
    delay(30);                       // send data per 100ms

    if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
          CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

          unsigned long canId = CAN.getCanId();

          Serial.println("-----------------------------");
          Serial.print("Received Adr From Slave :");
          Serial.println(canId, HEX);   

           float* Th1_New =(float*) &buf[0];

              Serial.print("Th1 :");
              Serial.print(*Th1_New);

              Th1_New =(float*) &buf[4];
              Serial.print("   Th2 :");
              Serial.println(*Th1_New);
              Serial.println();
    }
   
    delay(100);                       // send data per 100ms
    //SERIAL_PORT_MONITOR.println("CAN BUS sendMsgBuf ok!");
    if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
          CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

          unsigned long canId = CAN.getCanId();

          Serial.println("-----------------------------");
          Serial.print("Received Adr From Slave :");
          Serial.println(canId, HEX);   

           float* AirFlow =(float*) &buf[0];

              Serial.print("AirFlow1 :");
              Serial.print(*AirFlow);

              AirFlow =(float*) &buf[4];
              Serial.print("   AirFlow2 :");
              Serial.println(*AirFlow);
              Serial.println();
    }
        delay(100);
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
              AdrTemp =  Adr_Slave[SLAVE_01];
          #endif 
          #ifdef SLAVE_02
              AdrTemp = Adr_Slave[SLAVE_02];
          #endif 
          #ifdef SLAVE_03
              AdrTemp = Adr_Slave[SLAVE_03];
          #endif 
          #ifdef SLAVE_04
              AdrTemp =  Adr_Slave[SLAVE_04];
          #endif 
          #ifdef SLAVE_05
              AdrTemp = Adr_Slave[SLAVE_05];
          #endif 
          #ifdef SLAVE_06
              AdrTemp = Adr_Slave[SLAVE_06];
          #endif 

        /*
          if (canId == AdrTemp){
            char temp = resp_buf[0];        
            for(int i =0; i<7; i++){
              resp_buf[i] = resp_buf[i+1];            
            }
            resp_buf[7] = temp;       
                   
           CAN.sendMsgBuf(canId, 0, 8, resp_buf);// adr 0X00
           Serial.print("Responce Send with Adr : ");
           Serial.println(canId);
        }
        */

        
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

            delay(100);
             
            CAN.sendMsgBuf(canId, 0, 8, resp_buf);// adr 0X00          
    
          
           Serial.print("Responce Send with Adr : ");
           Serial.println(canId);
        }
  }
}
