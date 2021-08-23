#define ON 1
#define OFF 0



#define T_INIT_1 0
#define T_INIT_2 1
#define T_WAIT_1 2
#define T_CONV_1 3
#define T_CONV_2 4
#define T_WAIT_2 5

//#define SLAVE_01  0x00
//#define SLAVE_02  0x01
//#define SLAVE_03  0x02
//#define SLAVE_04  0x03
//#define SLAVE_05  0x04
#define SLAVE_06  0x05

//#define ADR_SLAVE_01  0x00
//#define ADR_SLAVE_02  0x01
//#define ADR_SLAVE_03  0x02


void Can_Init(void);
void Can_Master(void);
void Can_Slave(void);
void Thermo1_Loop(void );
void Thermo2_Loop(void);
void Thermo1_Init(void);
void Thermo2_Init(void);
void Thermo1_Conversion(void);
void Thermo2_Conversion(void);
