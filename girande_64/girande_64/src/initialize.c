/*
 * initialize.c
 *
 * Created: 3/22/2013 1:12:24 PM
 *  Author: Milad
 */


#include "initialize.h"


void En_RC32M(void)
{
    // Start RC32M OSC
    OSC_CTRL |= OSC_RC32MEN_bm;
    while(!(OSC_STATUS & OSC_RC32MRDY_bm));

    // Select the system clock source: 32 MHz Internal RC Osc.
    CCP = CCP_IOREG_gc;
    CLK_CTRL = CLK_SCLKSEL_RC32M_gc;

    // Disable the unused oscillators: 2 MHz, internal 32 kHz, external clock/crystal oscillator, PLL
    OSC_CTRL &= ~(OSC_RC2MEN_bm | OSC_RC32KEN_bm | OSC_XOSCEN_bm | OSC_PLLEN_bm);
};

void PORT_init(void)
{
	PORTA_DIR = LED_White_PIN_bm;
	PORTB_DIR = 0XFF;//Segment_R 
	PORTC_DIR = NRF24L01_R_CE_LINE | NRF24L01_R_CS_LINE | NRF24L01_R_MOSI_LINE | NRF24L01_R_SCK_LINE | Wireless_TX_R_PIN_bm;
			PORTC_PIN0CTRL |= PORT_ISC_LEVEL_gc;
			PORTC_INTCTRL  |= PORT_INT0LVL_LO_gc;
			PORTC_INT0MASK |= PIN0_bm;
	PORTD_DIR = LED_Green_L_PIN_bm | LED_White_L_PIN_bm | LED_Green_R_PIN_bm | LED_White_R_PIN_bm | Buzzer_PIN_bm | LED_Red_PIN_bm | USART_M_TX_PIN_bm ;
	PORTE_DIR = NRF24L01_L_CE_LINE | NRF24L01_L_CS_LINE | NRF24L01_L_MOSI_LINE | NRF24L01_L_SCK_LINE | Wireless_TX_L_PIN_bm;
			PORTE_PIN0CTRL |= PORT_ISC_LEVEL_gc;
			PORTE_INTCTRL  |= PORT_INT0LVL_LO_gc;
			PORTE_INT0MASK |= PIN0_bm;
	PORTF_DIR = 0xFF;//Segment_L
	Wireless_R_PORT.OUTSET=Wireless_TX_R_PIN_bm;//CHERA BARAYE L NIST?
	Wireless_L_PORT.OUTSET=Wireless_TX_L_PIN_bm;
	PORTD.OUTSET = USART_M_TX_PIN_bm;
	
	PORTR_DIR = LED_Orange_PIN_bm;
};

// #define TIMERD0_PER 0x7D
// void TimerD0_init(void)
// {
// 	tc_write_clock_source(&TCD0,TC_CLKSEL_DIV256_gc);
// 	tc_set_wgm(&TCD0,TC_WG_NORMAL);
// 	tc_set_overflow_interrupt_level(&TCD0,TC_INT_LVL_LO);
// 	tc_write_period(&TCD0,TIMERD0_PER);
// 	tc_set_direction(&TCD0,TC_UP);
// 	tc_enable(&TCD0);
// };
// 
// void TimerE0_init(void)
// {
//     tc_write_clock_source(&TCE0,TC_CLKSEL_DIV256_gc);
//     tc_set_wgm(&TCE0,TC_WG_SS);
//     tc_write_period(&TCE0,0x00FF);
//     tc_set_direction(&TCE0,TC_UP);
//     tc_enable_cc_channels(&TCE0,TC_CCAEN);
//     tc_enable_cc_channels(&TCE0,TC_CCBEN);
//     tc_enable(&TCE0);
// };
// 
// void TimerE1_init(void)
// {
//     tc_write_clock_source(&TCE1,TC_CLKSEL_DIV256_gc);
//     tc_set_wgm(&TCE1,TC_WG_SS);
//     tc_write_period(&TCE1,0x00FF);
//     tc_set_direction(&TCE1,TC_UP);
//     tc_enable_cc_channels(&TCE1,TC_CCAEN);
//     tc_enable(&TCE1);
// };


void USART_R_init(void)
{
	usart_set_mode(&Wireless_R_USART,USART_CMODE_ASYNCHRONOUS_gc);
	usart_format_set(&Wireless_R_USART,USART_CHSIZE_8BIT_gc,USART_PMODE_DISABLED_gc,false);
	usart_set_rx_interrupt_level(&Wireless_R_USART,USART_INT_LVL_MED);
	//usart_set_tx_interrupt_level(&Wireless_R_USART,USART_INT_LVL_MED);
	usart_set_baudrate(&Wireless_R_USART,USART_BUADRATE,F_CPU);
	usart_tx_enable(&Wireless_R_USART);
	usart_rx_enable(&Wireless_R_USART);
}


void USART_L_init(void)
{
	usart_set_mode(&Wireless_L_USART,USART_CMODE_ASYNCHRONOUS_gc);
	usart_format_set(&Wireless_L_USART,USART_CHSIZE_8BIT_gc,USART_PMODE_DISABLED_gc,false);
	usart_set_rx_interrupt_level(&Wireless_L_USART,USART_INT_LVL_MED);
	//usart_set_tx_interrupt_level(&Wireless_L_USART,USART_INT_LVL_MED);
	usart_set_baudrate(&Wireless_L_USART,USART_BUADRATE,F_CPU);
	//usart_tx_enable(&Wireless_L_USART);
	//usart_rx_enable(&Wireless_L_USART);
}

#define USARTD0_conf USARTD0
#define USARTD0_BUADRATE 115200
void USARTD0_init(void)
{
		usart_set_mode(&USARTD0_conf,USART_CMODE_ASYNCHRONOUS_gc);
		usart_format_set(&USARTD0_conf,USART_CHSIZE_8BIT_gc,USART_PMODE_DISABLED_gc,false);
		usart_set_rx_interrupt_level(&USARTD0_conf,USART_INT_LVL_MED);
		//usart_set_dre_interrupt_level(&USARTD0_conf,USART_INT_LVL_LO);
		usart_set_baudrate(&USARTD0_conf,USARTD0_BUADRATE,F_CPU);
		//usart_tx_enable(&USARTD0_conf);
		//usart_rx_enable(&USARTD0_conf);
	}
	
void OUT_Bling(PORT_t *OUT_PORT,uint8_t OUT_PIN_bp,uint8_t Speed,uint32_t *Time_ON,uint32_t time_ms)
{
    if((*Time_ON) >0)
        (*Time_ON)--;
    if((Speed) != 0 && (*Time_ON) > 1)
        OUT_PORT->OUT = (OUT_PORT->OUT & ~(1<<OUT_PIN_bp)) | (((time_ms / (Speed)) & 0x00001) << OUT_PIN_bp);
    //if((Speed) == 0 && (*Time_ON) >  1)		///////Set OUT
        //OUT_PORT->OUTSET = 1<<OUT_PIN_bp;
    if((*Time_ON) == 1)						///////Clr OUT
        OUT_PORT->OUTCLR = 1<<OUT_PIN_bp;
}


