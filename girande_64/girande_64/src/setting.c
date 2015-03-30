/*
 * setting.c
 *
 * Created: 1/28/2015 5:17:54 PM
 *  Author: Dell
 */ 
#include <asf.h>
#include <stdio.h>
#include <string.h>
#define F_CPU 32000000UL
#include <util/delay.h>
#include "initialize.h"
#include "nrf24l01_L.h"
#include "nrf24l01_R.h"
#include "variable.h"
#include "setting.h"

void set_micro (void)
{
	En_RC32M();
	PORT_init();

	PMIC_CTRL |=PMIC_LOLVLEN_bm|PMIC_MEDLVLEN_bm;


	USART_R_init();
	
	///////////////////////////////////////////////////////////////////////////////////////////spi se

	spi_xmega_set_baud_div(&NRF24L01_L_SPI,8000000UL,F_CPU);
	spi_enable_master_mode(&NRF24L01_L_SPI);
	spi_enable(&NRF24L01_L_SPI);

		
	sei();
}