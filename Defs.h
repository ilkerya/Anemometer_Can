

#include <SPI.h>
#include "mcp2515_can.h"
#include <Adafruit_MAX31856.h>
#include <Adafruit_SSD1306.h>

#define TFCARD_SPI_CS  4 //ACTIVE LOW
#define MCP2515_SPI_CS  9 //ACTIVE LOW

const int SPI_CS_PIN = 9;
const int CAN_INT_PIN = 2;

#define ON 1
#define OFF 0

#define T_INIT_1 0
#define T_INIT_2 1
#define T_WAIT_1 2
#define T_CONV_1 3
#define T_CONV_2 4
#define T_WAIT_2 5

//#define SLAVE_01  1
//#define SLAVE_02  3
//#define SLAVE_03  5
#define SLAVE_04  7
//#define SLAVE_05  9
//#define SLAVE_06  11
//#define SLAVE_07 13
//#define SLAVE_08 15
//#define SLAVE_09 17
//#define SLAVE_10 19
//#define SLAVE_11 21
//#define SLAVE_12 23
//#define SLAVE_13 25
//#define SLAVE_14 27
//#define SLAVE_15 29
//#define SLAVE_16 31
//#define SLAVE_17 33
//#define SLAVE_18 35



void Can_Init(void);
void Can_Master(void);
void Can_Slave(void);
void Thermo1_Loop(void );
void Thermo2_Loop(void);
void Thermo1_Init(void);
void Thermo2_Init(void);
void Thermo1_Conversion(void);
void Thermo2_Conversion(void);
void UI_Data(void);
#define THERMOCOUPLE 1
#define AIRFLOW 0
void PutArray_Temp(float* Temp,byte index);
void PutArray_Air(uint16_t* Air,byte index);
void ClearNodes(byte index);
