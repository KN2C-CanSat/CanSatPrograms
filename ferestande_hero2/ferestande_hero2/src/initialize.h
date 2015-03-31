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

//USART
#define TX_Data_PIN_bm		PIN3_bm
#define RX_Data_PIN_bm		PIN2_bm

//TWI
#define TWI_DATA_PIN_bm		PIN0_bm
#define TWI_CLK_PIN_bm		PIN1_bm

//LED
#define LED_Blue_PORT       PORTE
#define LED_Blue_PIN_bm		PIN3_bm
#define LED_Blue_PIN_bp		PIN3_bp

//Wireless
#define NRF24L01_L_SPI			SPID  //doroste?
#define NRF24L01_L_PORT_CE		PORTE
#define NRF24L01_L_PORT_CS		PORTD

#define NRF24L01_L_CE_LINE		PIN1_bm
#define NRF24L01_L_CS_LINE		PIN4_bm
#define NRF24L01_L_MOSI_LINE	PIN5_bm
#define NRF24L01_L_MISO_LINE	PIN6_bm
#define NRF24L01_L_SCK_LINE		PIN7_bm
#define NRF24L01_L_IRQ_LINE		PIN0_bm
// #define _FILTER_FREQ 1.0
// #define _FILTER_CONST .11 //(0.02/((1.0/(2.0*3.14*_FILTER_FREQ))+0.02))
// 
// #define LOWByte(_A_) ((_A_) & 0xff)
// #define HIGHByte(_A_) (((_A_)>>8) & 0xff)

void En_RC32M(void);
void PORT_init(void);
void TimerC0_init(void);

#define TIMERD0_PER 0x7D  //?!

void TimerD0_init(void);

void SPI_Init(void);

void USARTD0_init(void);


#endif /* INITIALIZE_H_ */