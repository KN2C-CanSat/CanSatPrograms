/*
 * setting.c
 *
 * Created: 1/28/2015 4:27:13 PM
 *  Author: Dell
 */ 

#include <asf.h>
#define F_CPU 32000000UL
#include <util/delay.h>
#include "initialize.h"
#include "nrf24l01_L.h"
#include <stdlib.h>
#include <stdio.h>
#include "variable.h"
#include "setting.h"

void set_micro(void)
{
	En_RC32M();

	//Enable LowLevel & HighLevel Interrupts
	PMIC_CTRL |= PMIC_HILVLEN_bm | PMIC_LOLVLEN_bm |PMIC_MEDLVLEN_bm;

	PORT_init();
	USARTD0_init();
	
	
	// Globally enable interrupts
	sei();
	SPI_Init();
}