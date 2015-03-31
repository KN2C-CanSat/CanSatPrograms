/*
 * initialize.h
 *
 * Created: 3/22/2012 12:50:44 AM
 *  Author: Milad
 */ 


#ifndef INITIALIZE_H_
#define INITIALIZE_H_
#include <asf.h>

#define F_CPU 32000000UL


#define ON 1
#define OFF 0

#define Out_Set(_PORT_,_PIN_bp_,_STATUS_ ) _PORT_.OUT = (_PORT_.OUT & ~(1<<_PIN_bp_)) | (_STATUS_<<_PIN_bp_)
//LED & BUZZER
#define LED_White_R_PORT		PORTD
#define LED_Green_R_PORT		PORTD
#define LED_White_L_PORT		PORTD
#define LED_Green_L_PORT		PORTD
#define LED_White_R_PIN_bp		PIN0_bp
#define LED_White_R_PIN_bm		PIN0_bm
#define LED_Green_R_PIN_bp		PIN1_bp
#define LED_Green_R_PIN_bm		PIN1_bm
#define LED_White_L_PIN_bp		PIN6_bp
#define LED_White_L_PIN_bm		PIN6_bm
#define LED_Green_L_PIN_bp		PIN5_bp
#define LED_Green_L_PIN_bm		PIN5_bm
#define LED_White_R(_STATUS_)	Out_Set(LED_White_R_PORT,LED_White_R_PIN_bp,_STATUS_ ) 
#define LED_Green_R(_STATUS_)	Out_Set(LED_Green_R_PORT,LED_Green_R_PIN_bp,_STATUS_ ) 
#define LED_White_L(_STATUS_)	Out_Set(LED_White_L_PORT,LED_White_L_PIN_bp,_STATUS_ ) 
#define LED_Green_L(_STATUS_)   Out_Set(LED_Green_L_PORT,LED_Green_L_PIN_bp,_STATUS_ ) 
#define LED_Red(_STATUS_)		Out_Set(LED_Red_PORT,LED_Red_PIN_bp,_STATUS_ )
#define LED_White(_STATUS_)    Out_Set(LED_White_PORT,LED_White_PIN_bp,_STATUS_ ) 
#define LED_Orange(_STATUS_)	    Out_Set(LED_Orange_PORT,LED_Orange_PIN_bp,_STATUS_ ) 

#define LED_Red_PORT		PORTD
#define LED_Red_PIN_bm		PIN4_bm
#define LED_Red_PIN_bp		PIN4_bp
#define LED_White_PORT		PORTA
#define LED_White_PIN_bm	PIN0_bm
#define LED_White_PIN_bp	PIN0_bp
#define LED_Orange_PORT		PORTR
#define LED_Orange_PIN_bm		PIN1_bm
#define LED_Orange_PIN_bp		PIN1_bp


#define Buzzer_PORT				PORTD
#define Buzzer_PIN_bp			PIN7_bp
#define Buzzer_PIN_bm			PIN7_bm
#define Buzzer(_STATUS_)		Out_Set(Buzzer_PORT,Buzzer_PIN_bp,_STATUS_ )

//Wireless & usarts
#define Wireless_R_PORT PORTC
#define Wireless_L_PORT PORTE
#define Wireless_R_USART USARTC0
#define Wireless_L_USART USARTE0
#define USART_M			 USARTD0
#define Wireless_TX_R_PIN_bm PIN3_bm
#define Wireless_RX_R_PIN_bm PIN2_bm
#define Wireless_TX_L_PIN_bm PIN3_bm
#define Wireless_RX_L_PIN_bm PIN2_bm
#define USART_M_TX_PIN_bm    PIN3_bm
#define USART_M_RX_PIN_bm    PIN2_bm
#define USART_R_RXC_vect USARTC0_RXC_vect
#define USART_R_DRE_vect USARTC0_DRE_vect
#define USART_L_RXC_vect USARTE0_RXC_vect
#define USART_L_DRE_vect USARTE0_DRE_vect
#define USART_M_RXC_vect USARTD0_RXC_vect
#define USART_M_DRE_vect USARTD0_DRE_vect

#define NRF24L01_R_SPI			SPIC
#define NRF24L01_R_PORT			PORTC

#define NRF24L01_R_CE_LINE		PIN1_bm
#define NRF24L01_R_CS_LINE		PIN4_bm
#define NRF24L01_R_MOSI_LINE	PIN5_bm
#define NRF24L01_R_MISO_LINE	PIN6_bm
#define NRF24L01_R_SCK_LINE		PIN7_bm
#define NRF24L01_R_IRQ_LINE		PIN0_bm

#define NRF24L01_L_SPI			SPIE
#define NRF24L01_L_PORT			PORTE

#define NRF24L01_L_CE_LINE		PIN1_bm
#define NRF24L01_L_CS_LINE		PIN4_bm
#define NRF24L01_L_MOSI_LINE	PIN5_bm
#define NRF24L01_L_MISO_LINE	PIN6_bm
#define NRF24L01_L_SCK_LINE		PIN7_bm
#define NRF24L01_L_IRQ_LINE		PIN0_bm

#define PRX_R PORTC_INT0_vect
#define PRX_L PORTE_INT0_vect
//Menu
#define Menu_PIN3_bm PIN1_bm
#define Menu_PIN3_bp PIN1_bp
#define Menu_PIN2_bm PIN4_bm
#define Menu_PIN2_bp PIN4_bp
#define Menu_PIN1_bm PIN3_bm
#define Menu_PIN1_bp PIN3_bp
#define Menu_PIN0_bm PIN2_bm
#define Menu_PIN0_bp PIN2_bp
#define Menu_Set_PIN_bm PIN7_bm
#define Menu_Set_PIN_bp PIN7_bp
//#define Menu_Cancel_PIN_bm PIN0_bm
//#define Menu_Cancel_PIN_bp PIN0_bp
#define Menu_Side_Switch_PIN_bm PIN6_bm
#define Menu_Side_Switch_PIN_bp PIN6_bp
#define Menu_Side_Select_PIN_bm PIN5_bm
#define Menu_Side_Select_PIN_bp PIN5_bp
#define Menu_PORT PORTA
//7seg
#define Segment_A_bm PIN0_bm
#define Segment_B_bm PIN5_bm
#define Segment_C_bm PIN6_bm
#define Segment_D_bm PIN4_bm
#define Segment_E_bm PIN3_bm
#define Segment_F_bm PIN1_bm
#define Segment_G_bm PIN2_bm
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

#define Disp_L_PORT PORTF
#define Disp_R_PORT PORTB

void En_RC32M(void);
void PORT_init(void);

#define TIMERD0_PER 0x7D
void TimerD0_init(void);

void TimerE0_init(void);

void TimerE1_init(void);


#define USART_BUADRATE 115200
void USART_R_init(void);
void USART_L_init(void);
void USARTD0_init(void);

void OUT_Bling(PORT_t *OUT_PORT,uint8_t OUT_PIN_bp,uint8_t Speed,uint32_t *Time_ON,uint32_t time_ms);

#endif /* INITIALIZE_H_ */