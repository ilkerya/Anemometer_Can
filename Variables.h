// https://en.cppreference.com/w/cpp/types/integer

static const char TH_ERR_0[] PROGMEM = " Measurement Ok !  "; 
static const char TH_ERR_1[] PROGMEM = "Cold Junc Rng Fault"; 
static const char TH_ERR_2[] PROGMEM = "Thermocop Range Flt"; 
static const char TH_ERR_3[] PROGMEM = "Cold Junc High Falt";
static const char TH_ERR_4[] PROGMEM = "Cold Junc Low Fault"; 
static const char TH_ERR_5[] PROGMEM = "Thermocp High Fault"; 
static const char TH_ERR_6[] PROGMEM = "Thermocop Low Fault"; 
static const char TH_ERR_7[] PROGMEM = "Over/UnderVolta Flt"; 
static const char TH_ERR_8[] PROGMEM = "Thermocple Open Flt"; 
const char *const TH_ERR_TABLE[] PROGMEM = {TH_ERR_0, TH_ERR_1, TH_ERR_2, TH_ERR_3, TH_ERR_4, TH_ERR_5, TH_ERR_6, TH_ERR_7, TH_ERR_8};

// CAN BUS VARIABLES
byte Adr_Slave[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06}; //send BUF
unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //send BUF
unsigned char resp_buf[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //send BUF

unsigned char Th1_arr[4] = {0, 0, 0, 0}; //send 
float* Th1_New;

    unsigned char SlaveAdr;
   
    unsigned char len = 0;
    unsigned char buf[8];
    byte Adr_Master=0;
    byte Adr_index = 0;
//  CAN BUS VARIABLES
    

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

  
