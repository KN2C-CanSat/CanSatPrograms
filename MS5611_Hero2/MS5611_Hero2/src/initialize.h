/*
 * initialize.h
 *
 * Created: /8/1392
 *  Author: Mina
 */ 

#ifndef INITIALIZE_H_
#define INITIALIZE_H_
#include <asf.h>

#define F_CPU 32000000UL

#define RobotID ((((PORTA_IN & PIN6_bm) >> PIN6_bp) << 0) |\
				 (((PORTA_IN & PIN4_bm) >> PIN4_bp) << 1) |\
				 (((PORTA_IN & PIN7_bm) >> PIN7_bp) << 2) |\
				 (((PORTA_IN & PIN5_bm) >> PIN5_bp) << 3))

#define KCK_Sens1_PORT PORTD
#define KCK_Sens2_PORT PORTD
#define KCK_Sens1_PIN_bm		PIN6_bm
#define KCK_Sens1_PIN_bp		PIN6_bp
#define KCK_Sens2_PIN_bm		PIN7_bm
#define KCK_Sens2_PIN_bp		PIN7_bp
#define KCK_Sens1 (((KCK_Sens1_PORT.IN &KCK_Sens1_PIN_bm) >> KCK_Sens1_PIN_bp)?0x00:0xFF)
#define KCK_Sens2 (((KCK_Sens1_PORT.IN &KCK_Sens2_PIN_bm) >> KCK_Sens2_PIN_bp)?0x00:0xFF)

#define KCK_DSH_SW_PORT PORTA
#define KCK_DSH_SW_PIN_bm	PIN2_bm
#define KCK_DSH_SW_PIN_bp	PIN2_bp
#define KCK_DSH_SW (((KCK_DSH_SW_PORT.IN & KCK_DSH_SW_PIN_bm) >> KCK_DSH_SW_PIN_bp)?0xFF:0x00)
#define KCK_Charge_PORT PORTB
#define KCK_Charge_PIN_bm		PIN6_bm
#define KCK_Charge_PIN_bp		PIN6_bp

#define KCK_Charge(_A_) KCK_Charge_PORT.OUT = (KCK_Charge_PORT.OUT & (~KCK_Charge_PIN_bm)) | (_A_<<KCK_Charge_PIN_bp)
#define KCK_CHARGE_OFF 1
#define KCK_CHARGE_ON  0

#define KCK_SPEED_OFF 0x00
#define KCK_SPEED_LOW 0x64
#define KCK_SPEED_HI  0xFF
#define KCK_SPEED_RX Robot_D[RobotID].KCK
#define KCK_Speed_CHIP(_A_)    TCC0_CCA=_A_; // PORTC_OUT =(PORTC_OUT & (~KCK_DIR_PIN_bm)) | (_A_<<KCK_DIR_PIN_bp) // _delay_ms(100); TCC0_CCA=0; //KCK_Charge( KCK_CHARGE_ON) KCK_Charge( KCK_CHARGE_OFF)   //PORTC_OUT =TCC0_CNT=_A_; ;
#define KCK_Speed_DIR(_A_)    TCC0_CCB=_A_;

#define KCK_CAP_VFB_PIN_bm	PIN6_bm
#define KCK_CAP_VFB_PIN_bp	PIN6_bp

#define KCK_Chip_PIN_bm		PIN1_bm
#define KCK_Chip_PIN_bp		PIN1_bp
#define KCK_DIR_PIN_bm		PIN0_bm
#define KCK_DIR_PIN_bp		PIN0_bp

//Gyroscope
#define Gyro_SDA_PIN_bm			PIN0_bm	
#define Gyro_SCL_PIN_bm			PIN1_bm 

#define ON 1
//#define OFF 0
	
//LED & BUZZER
#define Buzzer_PIN_bm		PIN6_bm
#define Buzzer_PIN_bp		PIN6_bp

#define LED_Red_PIN_bm		PIN5_bm
#define LED_Red_PIN_bp		PIN5_bp
#define LED_White_PIN_bp	PIN3_bp
#define LED_White_PIN_bm	PIN3_bm
#define LED_Green_PIN_bp	PIN2_bp
#define LED_Green_PIN_bm	PIN2_bm

#define LED_White(_STATUS_) PORTD_OUT = (PORTD_OUT & ~PIN3_bm) | (_STATUS_<<PIN3_bp)
#define LED_Green(_STATUS_) PORTD_OUT = (PORTD_OUT & ~PIN5_bm) | (_STATUS_<<PIN5_bp)
#define LED_Red(_STATUS_)   PORTD_OUT = (PORTD_OUT & ~PIN2_bm) | (_STATUS_<<PIN2_bp)
#define Buzzer(_STATUS_)    PORTF_OUT = (PORTF_OUT & ~PIN6_bm) | (_STATUS_<<PIN6_bp)
#define LED_White_PORT      PORTD
#define LED_Red_PORT		PORTD
#define LED_Green_PORT		PORTD
#define Buzzer_PORT			PORTC

//USART
#define TX_Data_PIN_bm		PIN3_bm
#define RX_Data_PIN_bm		PIN2_bm

//TWI
#define TWI_DATA_PIN_bm		PIN0_bm
#define TWI_CLK_PIN_bm		PIN1_bm

//SWITCH
#define SW_TEST_PIN_bm		PIN7_bm
#define SW_TEST_PIN_bp		PIN7_bp
#define SW_TEST (((PORTC_IN &SW_TEST_PIN_bm) >>SW_TEST_PIN_bp )?0xFF:0x00)

//MENU
#define Menu_PIN3_bm		PIN0_bm
#define Menu_PIN3_bp		PIN0_bp
#define Menu_PIN1_bm		PIN1_bm
#define Menu_PIN1_bp		PIN1_bp
#define Menu_PIN2_bm		PIN2_bm
#define Menu_PIN2_bp		PIN2_bp
#define Menu_PIN0_bm		PIN3_bm
#define Menu_PIN0_bp		PIN3_bp

#define Menu_Set_PIN_bm		PIN7_bm
#define Menu_Set_PIN_bp		PIN7_bp
#define Menu_Cancel_PIN_bm	PIN4_bm
#define Menu_Cancel_PIN_bp	PIN4_bp
#define Menu_PORT			PORTH




//LCD
#define LCD_D4_DIR	PORTB_DIR
#define LCD_D4_DATA	PORTB_OUT
#define LCD_D4_BIT	PIN2_bp
#define LCD_D5_DIR	PORTB_DIR
#define LCD_D5_DATA	PORTB_OUT
#define LCD_D5_BIT	PIN5_bp
#define LCD_D6_DIR	PORTB_DIR
#define LCD_D6_DATA	PORTB_OUT
#define LCD_D6_BIT	PIN4_bp
#define LCD_D7_DIR	PORTC_DIR
#define LCD_D7_DATA	PORTC_OUT
#define LCD_D7_IN	PORTC_IN
#define LCD_D7_BIT	PIN5_bp
#define LCD_E_DIR	PORTB_DIR
#define LCD_E_PORT  PORTB_OUT
#define LCD_E_BIT 	PIN3_bp
#define LCD_RW_DIR	PORTB_DIR
#define LCD_RW_PORT PORTB_OUT
#define LCD_RW_BIT 	PIN0_bp
#define LCD_RS_DIR	PORTB_DIR
#define LCD_RS_PORT PORTB_OUT
#define LCD_RS_BIT 	PIN1_bp

#define POWER_VFB_PIN_bm			PIN3_bm  // VFB=Vss * R28/(R28+R27)

#define Disp_L_PORT PORTJ
#define Disp_R_PORT PORTK

#define Segment_A_bm PIN0_bm 
#define Segment_F_bm PIN1_bm
#define Segment_G_bm PIN2_bm
#define Segment_E_bm PIN3_bm
#define Segment_D_bm PIN4_bm
#define Segment_B_bm PIN5_bm 
#define Segment_C_bm PIN6_bm 
#define Segment_DP_bm PIN7_bm 
#define Segment_DP_bp PIN7_bp 


#define Segment_0  Segment_A_bm | Segment_B_bm | Segment_C_bm | Segment_D_bm | Segment_E_bm | Segment_F_bm
#define Segment_1  Segment_B_bm | Segment_C_bm
#define Segment_2  Segment_A_bm | Segment_B_bm | Segment_G_bm | Segment_E_bm | Segment_D_bm
#define Segment_3  Segment_A_bm | Segment_B_bm | Segment_C_bm | Segment_D_bm | Segment_G_bm
#define Segment_4  Segment_F_bm | Segment_G_bm | Segment_B_bm | Segment_C_bm
#define Segment_5  Segment_A_bm | Segment_F_bm | Segment_G_bm | Segment_C_bm | Segment_D_bm
#define Segment_6  Segment_A_bm | Segment_F_bm | Segment_G_bm | Segment_C_bm | Segment_D_bm | Segment_E_bm
#define Segment_7  Segment_F_bm | Segment_A_bm | Segment_B_bm | Segment_C_bm
#define Segment_8  Segment_A_bm | Segment_B_bm | Segment_C_bm | Segment_D_bm | Segment_E_bm | Segment_F_bm | Segment_G_bm
#define Segment_9  Segment_G_bm | Segment_F_bm | Segment_A_bm | Segment_B_bm | Segment_C_bm | Segment_D_bm
#define Segment_10 Segment_E_bm | Segment_F_bm | Segment_A_bm | Segment_B_bm | Segment_E_bm | Segment_G_bm
#define Segment_11 Segment_F_bm | Segment_G_bm | Segment_C_bm | Segment_D_bm | Segment_E_bm
#define Segment_12 Segment_A_bm | Segment_F_bm | Segment_E_bm | Segment_D_bm
#define Segment_13 Segment_G_bm | Segment_E_bm | Segment_D_bm | Segment_C_bm | Segment_B_bm
#define Segment_14 Segment_A_bm | Segment_F_bm | Segment_E_bm | Segment_D_bm | Segment_G_bm
#define Segment_15 Segment_A_bm | Segment_F_bm | Segment_G_bm | Segment_E_bm
#define Segment_Dash Segment_G_bm



//Wireless
#define NRF24L01_L_SPI			SPIE
#define NRF24L01_L_PORT			PORTE

#define NRF24L01_L_CE_LINE		PIN1_bm
#define NRF24L01_L_CS_LINE		PIN4_bm
#define NRF24L01_L_MOSI_LINE	PIN5_bm
#define NRF24L01_L_MISO_LINE	PIN6_bm
#define NRF24L01_L_SCK_LINE		PIN7_bm
#define NRF24L01_L_IRQ_LINE		PIN0_bm
#define _FILTER_FREQ 1.0
#define _FILTER_CONST .11 //(0.02/((1.0/(2.0*3.14*_FILTER_FREQ))+0.02))

#define LOWByte(_A_) ((_A_) & 0xff)
#define HIGHByte(_A_) (((_A_)>>8) & 0xff)

void En_RC32M(void);
void PORT_init(void);
void TimerC0_init(void);

#define TIMERD0_PER 0x7D  //?!

void TimerD0_init(void);

void SPI_Init(void);

void USARTD0_init(void);

void ADCA_init(void);
void OUT_Bling(PORT_t *OUT_PORT,uint8_t OUT_PIN_bp,uint8_t Speed,uint32_t *Time_ON,uint32_t time_ms);

#endif /* INITIALIZE_H_ */

//**************************************************************MS5611

