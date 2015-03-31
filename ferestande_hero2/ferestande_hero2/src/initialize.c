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
	
	
	PORTE_DIRSET = PIN3_bm;  //LED
	//PORTE_OUTSET = PIN3_bm;  //LED
	
	PORTD_DIRSET = PIN3_bm; //tx
	PORTD_OUTSET = PIN3_bm;
	
	PORTD_DIRSET = NRF24L01_L_CS_LINE | NRF24L01_L_MOSI_LINE | NRF24L01_L_SCK_LINE; // wireless module & programmer data
	PORTE_DIRSET = NRF24L01_L_CE_LINE;
	
	PORTE_PIN0CTRL |= PORT_ISC_FALLING_gc; //IRQ interrupt (INT0)
	PORTE_INTCTRL |= PORT_INT0LVL_LO_gc;
	PORTE_INT0MASK |= PIN0_bm;
   
};


void SPI_Init(void)
{
	 spi_xmega_set_baud_div(&NRF24L01_L_SPI,8000000UL,F_CPU);
	 spi_enable_master_mode(&NRF24L01_L_SPI);
	 spi_enable(&NRF24L01_L_SPI);
}


#define USARTD0_conf USARTD0
#define USARTD0_BUADRATE 115200
void USARTD0_init(void)
{
	usart_set_mode(&USARTD0_conf,USART_CMODE_ASYNCHRONOUS_gc);
	usart_format_set(&USARTD0_conf,USART_CHSIZE_8BIT_gc,USART_PMODE_DISABLED_gc,false);
	//usart_set_rx_interrupt_level(&USARTE0_conf,USART_INT_LVL_MED);
	//usart_set_dre_interrupt_level(&USARTE0_conf,USART_INT_LVL_LO);
	usart_set_baudrate(&USARTD0_conf,USARTD0_BUADRATE,F_CPU);
	usart_tx_enable(&USARTD0_conf);
	usart_rx_enable(&USARTD0_conf);
}


