// https://en.cppreference.com/w/cpp/types/integer

static const char TH_ERR_0[] PROGMEM = " Measurement Ok ! "; 
static const char TH_ERR_1[] PROGMEM = "Cold Junc Rng Flt"; 
static const char TH_ERR_2[] PROGMEM = "Thermocp Range Flt"; 
static const char TH_ERR_3[] PROGMEM = "Cold Junc High Flt";
static const char TH_ERR_4[] PROGMEM = "Cold Junc Low Flt"; 
static const char TH_ERR_5[] PROGMEM = "Thermocp High Flt"; 
static const char TH_ERR_6[] PROGMEM = "Thermocp Low Fault"; 
static const char TH_ERR_7[] PROGMEM = "Over/UnderVolt Flt"; 
static const char TH_ERR_8[] PROGMEM = "Thermcple Open Flt"; 
const char *const TH_ERR_TABLE[] PROGMEM = {TH_ERR_0, TH_ERR_1, TH_ERR_2, TH_ERR_3, TH_ERR_4, TH_ERR_5, TH_ERR_6, TH_ERR_7, TH_ERR_8};

// CAN BUS VARIABLES
//byte Adr_Slave[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06}; //send BUF
//byte Adr_Slave[6] = {1, 3, 5, 7, 9, 11}; //send BUF
byte Adr_Slave[18] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35 }; //send BUF
unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //send BUF
unsigned char resp_buf[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //send BUF

unsigned char Th1_arr[4] = {0, 0, 0, 0}; //send 
float* Th1_New;

    unsigned char SlaveAdr;
    unsigned char CanTimeOut_Timer; 
    volatile bool CanTimeOut_Flag;
    unsigned char len = 0;
    unsigned char buf[8];
    byte Adr_Master=0;
    byte Adr_index = 0;
//  CAN BUS VARIABLES

struct  Sensors
{
  float Adr_1;
  float Adr_2;
  float Adr_3;
  float Adr_4;  
  float Adr_5;
  float Adr_6;
  float Adr_7; 
  float Adr_8;
  float Adr_9;
  float Adr_10; 
  float Adr_11;
  float Adr_12;
  float Adr_13; 
  float Adr_14;
  float Adr_15;
  float Adr_16; 
  float Adr_17;
  float Adr_18;
  float Adr_19; 
  float Adr_20;
  float Adr_21;
  float Adr_22; 
  float Adr_23;
  float Adr_24;
  float Adr_25; 
  float Adr_26;
  float Adr_27;
  float Adr_28; 
  float Adr_29;
  float Adr_30;
  float Adr_31; 
  float Adr_32;
  float Adr_33;
  float Adr_34; 
  float Adr_35;
  float Adr_36;                   
} ;

Sensors ThermoCouple;

struct  AirSensors
{
  uint16_t Adr_1;
  uint16_t Adr_2;
  uint16_t Adr_3;
  uint16_t Adr_4;  
  uint16_t Adr_5;
  uint16_t Adr_6;
  uint16_t Adr_7; 
  uint16_t Adr_8;
  uint16_t Adr_9;
  uint16_t Adr_10; 
  uint16_t Adr_11;
  uint16_t Adr_12;
  uint16_t Adr_13; 
  uint16_t Adr_14;
  uint16_t Adr_15;
  uint16_t Adr_16; 
  uint16_t Adr_17;
  uint16_t Adr_18;
  uint16_t Adr_19; 
  uint16_t Adr_20;
  uint16_t Adr_21;
  uint16_t Adr_22; 
  uint16_t Adr_23;
  uint16_t Adr_24;
  uint16_t Adr_25; 
  uint16_t Adr_26;
  uint16_t Adr_27;
  uint16_t Adr_28; 
  uint16_t Adr_29;
  uint16_t Adr_30;
  uint16_t Adr_31; 
  uint16_t Adr_32;
  uint16_t Adr_33;
  uint16_t Adr_34; 
  uint16_t Adr_35;
  uint16_t Adr_36;                   
} ;

AirSensors AirFlow;


static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
//char Disp_MENU1[] =    {'L','O','G',' ','S','T','A','R','T',' ','&',' ','S','T','O','P',' ','M','E','N','U','\0'};
static const char Disp_MENU_NULL[]  PROGMEM = "ENTER             ESC";
static const char Disp_MENU_ERROR[] PROGMEM = " KEY ERROR !         ";



// so variables
 /*                    
String Display_Line1 ="Display.........Line1"; 
String Display_Line2 ="Display........Line2."; 
String Display_Line3 ="Display.......Line3.."; 
String Display_Line4 ="Display......Line4..."; 
String Display_Line5 ="Display.....Line5....";
String Display_Line6 ="Display....Line6.....";
String Display_Line7 ="Display...Line7......";
String Display_Line8 ="Display..Line8.......";

*/

struct CanNode
{
  bool Adr_1;
  bool Adr_2;
  bool Adr_3;
  bool Adr_4;  
  bool Adr_5;
  bool Adr_6;
  bool Adr_7; 
  bool Adr_8;
  bool Adr_9;
  bool Adr_10; 
  bool Adr_11;
  bool Adr_12;
  bool Adr_13; 
  bool Adr_14;
  bool Adr_15;
  bool Adr_16; 
  bool Adr_17;
  bool Adr_18;
};

CanNode Nodes;

float ReShape;

struct ThermoLoop
{
  uint8_t  DelayTimer = 0;
  uint8_t  FreqTimer = 0;  
  uint8_t Fault;
  uint8_t FaulNo;
  uint8_t Mode;
  float Temp;
  float J_Temp; 
  bool Enable;
};

ThermoLoop Thermo1 ;
ThermoLoop Thermo2; 

uint16_t AirFlow1;
uint16_t AirFlow2;

struct TaskOrg
{
  uint16_t  IntTimer_250 = 0;
  uint16_t  IntTimer_500 = 0;
  uint16_t  IntTimer_1 = 0;
  uint16_t  IntTimer_2 = 0;
  uint16_t  IntTimer_5 = 0;
  uint16_t  IntTimer_10 = 0;
  uint16_t  IntTimer_20 = 0;
  uint16_t  IntTimer_60 = 0;  
  bool Task_250msec =0;
  bool Task_500msec =0;
  bool Task_1Sec =0;
  bool Task_2Sec =0;
  bool Task_5Sec =0;
  bool Task_10Sec =0;
  bool Task_20Sec =0;
  bool Task_60Sec =0;
};

 TaskOrg Loop;

#define TASK_500MSEC  1
#define TASK_1SEC 2
#define TASK_2SEC 4
#define TASK_5SEC 8
#define TASK_10SEC 16
#define TASK_20SEC 32
#define TASK_60SEC 64  

uint8_t SampleTime = TASK_2SEC; // 250msec 1 // 500 2 // 1Sec 4 // 2sec 8 // 5sec 16 // 10sec 32 // 20sec 64  


struct
{
  bool RTC_Update=0; 
  bool OLED_Init = 0 ; 
  uint8_t MenuTimeout=0; 
  uint8_t Flash=0; 
  uint16_t OLED_Timer = 0; 
  bool InitDelay = 0;
  bool SleepEnable = 0;
  uint8_t ValueTimer = 0; 
  bool ExpSensOnb =0;  
  bool ExpSens1 =0;
  bool ExpSens2 =0;
  bool ExpSens3 =0;
  uint8_t SensorRollTimer = 0;
  uint8_t ReInit_Timer = 2;
  bool ReInit_Enable = OFF;
}Display;

uint8_t Counter;

  
