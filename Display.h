
//https://github.com/adafruit/Adafruit_SSD1306
// https://upload.wikimedia.org/wikipedia/commons/f/f8/Codepage-437.png



#define OLED_GND 47// 13
#define OLED_POWER 45// 13
#define OLED_CS    41// 13
#define OLED_RESET 39
#define OLED_DC    37// 12  // common 50
#define OLED_CLK   35 //13 // common  52
#define OLED_MOSI  33// 11 //common 51


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

/*
  In Adafruit_SSD1306.h
  1. uncomment #define SSD1306_128_64
  2. comment #define SSD1306_128_32
  3. comment #define SSD1306_96_16
  In the example ssd1306_128x64_i2c
  4. add #define SSD1306_LCDHEIGHT 64

*/
/*
  #ifdef SSD1306_LCDHEIGHT
  #define SSD1306_LCDHEIGHT 64
  #endif
  #ifndef SSD1306_LCDHEIGHT
  #define SSD1306_LCDHEIGHT 64
  #endif

  #if (SSD1306_LCDHEIGHT != 64)
  #error("Height incorrect, please fix Adafruit_SSD1306.h!");
  #endif
*/

//#define DISPLAY_POWEROFF_STANDBYE
#define DISPLAY_SOFTOFF_STANDBYE

#if defined (DISPLAY_POWEROFF_STANDBYE)  & defined (DISPLAY_SOFTOFF_STANDBYE)
#error Select Only One Standbye Type
#endif
#if !(!defined (DISPLAY_POWEROFF_STANDBYE) ^ !defined (DISPLAY_SOFTOFF_STANDBYE))
#error Select At Least One Standbye Type
#endif

//Adafruit_SSD1306 display(OLED_RESET);
//DISPLAY INITIALIZER
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void Display_SwitchOff() {
  display.clearDisplay();
  display.display();
#ifdef DISPLAY_POWEROFF_STANDBYE
  digitalWrite(OLED_POWER, LOW);       // turn on pullup resistors
  digitalWrite(OLED_GND, LOW);       // keep GND Level
#endif

}
void DisplaySetPowerIO() {
  //-- DISPLAY INIT --//
  pinMode(OLED_GND, OUTPUT);
  digitalWrite(OLED_GND, LOW);       // keep GND Level
  pinMode(OLED_POWER, OUTPUT);
  digitalWrite(OLED_POWER, HIGH);       // turn on pullup resistors
}
void Display_ReInit_Start(uint8_t Timer) {
  DisplaySetPowerIO();
  Display.OLED_Timer = Timer; // 10 sec
  Display.ReInit_Enable = ON;
  Display.ReInit_Timer = 4;

}
void Display_ReInit_End() {
#ifdef DISPLAY_SOFTOFF_STANDBYE
  return;
#endif
#ifdef DISPLAY_POWEROFF_STANDBYE
  if (!Display.ReInit_Enable)return;
  if (Display.ReInit_Timer) {
    Display.ReInit_Timer--;
    return;
  }
  Display.ReInit_Enable = OFF;
  Display.ReInit_Timer = 4;


  // delay(300); // Pause for 2 seconds // critical
#if defined  ARDUINO_DUE | defined (ARDUINO_MKRZERO)
  delay(1300); // Pause for 2 seconds
  if (!display.begin(SSD1306_SWITCHCAPVCC)) { //    SSD1306_EXTERNALVCC
    Serial.println(F("SSD1306 allocation failed"));
    //for(;;); // Don’t proceed, loop forever
  }
#endif
#if defined (ARDUINO_MEGA)  | defined (CHIPKIT_MAX32)
  if (!display.begin(SSD1306_SWITCHCAPVCC)) { //    SSD1306_EXTERNALVCC
    Serial.println(F("SSD1306 allocation failed"));
    //for(;;); // Don’t proceed, loop forever
  }
#endif



  Serial.println(F("Display ReInitilized"));
  //   display.clearDisplay();
  //   display.setTextSize(3);
  //   display.setTextColor(WHITE);  //0  white on black
  //    display.setTextColor(0);  //1     Black on white
  display.dim(0); // lower brightness
  //   display.setCursor(0, 0);
  //   display.println();
  //    display.println("DATALOG");
  //   display.display();

#endif
}



void DisplayInit(void) {
  DisplaySetPowerIO();
  //-- DISPLAY INIT --//
  Display.OLED_Timer = 40; // 20-> 10 sec

  delay(300); // Pause for 2 seconds // critic !!


  //   #ifdef ARDUINO_MEGA
  if (!display.begin(SSD1306_SWITCHCAPVCC)) { //  SSD1306_EXTERNALVCC
    Serial.println(F("SSD1306 allocation failed"));
    // for(;;); // Don’t proceed, loop forever
  }

  //#endif
  display.dim(0); // lower brightness
  // display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);  //0  white on black
  //    display.setTextColor(0);  //1     Black on white
  display.setCursor(0, 0);
  display.println();
  display.println(F("DATALOG"));
  display.display();

  // Adafruit_SSD1306::dim  ( 1 ) //1 == lower brightness // 0 == full brightness
  //display.dim
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for (int16_t i = 0; i < 256; i++) {
    if (i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  // delay(2000);
}



void displayValues(void){
  
  if (Display.InitDelay == OFF)return;
  //testdrawchar();
  //return;

  display.clearDisplay();
  display.setTextSize(1);

  display.setCursor(0, 0);

    char buffer[21];
    #ifdef CAN_MASTER
     display.print("       CAN MASTER");   //10

    
      #endif
    #ifdef CAN_SLAVE
      
  display.print("1: ");
  if(Thermo1.Fault == 0){
    display.print(Thermo1.Temp);   //10
    display.write(247); // 5th character  '°';
    display.print("C");
    display.print(" ");   //10
    display.print(Thermo1.J_Temp);
    display.write(247); // 5th character  '°';
    display.print("C");     
  }
  else{
    //display.print("----- -----");


   //   for (int i = 0; i < 8; i++) {
  //int i = FaultNo;
      strcpy_P(buffer, (char *)pgm_read_word(&(TH_ERR_TABLE[Thermo1.Fault])));  // Necessary casts and dereferencing, just copy.
      display.print(buffer);
    //  Serial.println(buffer);
    
  }
  #endif
  

  display.setCursor(0, 8);
    #ifdef CAN_MASTER
  
    
      #endif
  
  #ifdef CAN_SLAVE
  display.print("2: ");
  if(Thermo2.Fault == 0){
    display.print(Thermo2.Temp);   //10
    display.write(247); // 5th character  '°';
    display.print("C ");
    display.print(Thermo2.J_Temp);
    display.write(247); // 5th character  '°';
    display.print("C"); 
    
  }
  else {
      strcpy_P(buffer, (char *)pgm_read_word(&(TH_ERR_TABLE[Thermo2.Fault])));  // Necessary casts and dereferencing, just copy.
      display.print(buffer);
  }
  #endif

  

  //   Display_Line2 =  String(KeyAdc);

  display.setCursor(0, 16);
    #ifdef CAN_MASTER
    if(Nodes.Adr_1 == ON)display.print("1 ");
    else display.print("  ");  
    if(Nodes.Adr_2 == ON)display.print("3 ");
    else display.print("  ");  
    if(Nodes.Adr_3 == ON)display.print("5 ");
    else display.print("  ");
    if(Nodes.Adr_4 == ON)display.print("7 ");
    else display.print("  ");
    if(Nodes.Adr_5 == ON)display.print("9 ");
    else display.print("  ");
    if(Nodes.Adr_6 == ON)display.print("11 ");//13
    else display.print("   ");
    if(Nodes.Adr_7 == ON)display.print("13 ");//16
    else display.print("   ");
    if(Nodes.Adr_8 == ON)display.print("15 ");//19
    else display.print("   ");  
    
      #endif

  


  #ifdef CAN_SLAVE
      display.print("3 ");   //10
      display.print("Air1: ");  display.print(AirFlow1);  

  #endif


  display.setCursor(0, 24);
        #ifdef CAN_MASTER
    if(Nodes.Adr_9 == ON)display.print("17 ");
    else display.print("  ");
    if(Nodes.Adr_10 == ON)display.print("19 ");
    else display.print("  ");   
    if(Nodes.Adr_11 == ON)display.print("21 ");
    else display.print("  ");
    if(Nodes.Adr_12 == ON)display.print("23 ");
    else display.print("  ");
    if(Nodes.Adr_13 == ON)display.print("25 ");//15
    else display.print("  ");
    if(Nodes.Adr_14 == ON)display.print("27 ");//18
    else display.print("   ");
    if(Nodes.Adr_15 == ON)display.print("29 ");//21
    else display.print("   "); 
          #endif
    #ifdef CAN_SLAVE
  display.print("4 ");   //10
  display.print("Air2: ");  display.print(AirFlow2);  




      #endif

 
  display.setCursor(0, 32);
        #ifdef CAN_MASTER
    if(Nodes.Adr_16 == ON)display.print("31 ");//
    else display.print("   ");    
    if(Nodes.Adr_17 == ON)display.print("33 ");//
    else display.print("   ");   
    if(Nodes.Adr_18 == ON)display.print("35 ");//
    else display.print("   ");  
        #endif

      #ifdef CAN_SLAVE
  display.print("5");   //10
            #endif
  display.setCursor(0, 40);

      #ifdef CAN_SLAVE
  display.print("6");   //10
            #endif
  display.setCursor(0, 48);

      #ifdef CAN_SLAVE
  display.print("7 ");   //10
            #endif


  display.setCursor(0, 56); // 8th line
      #ifdef CAN_SLAVE
  display.print("8");   //10
      display.print(" Slave Adr:");   //10
    display.print(SlaveAdr);   //10
            #endif
  display.display();
}
