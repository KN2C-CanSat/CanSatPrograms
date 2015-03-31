/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
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
#include "NRF_transmission.h"
#include "NRF.h"

#define printf2pcs(T)      UART_SEND(sprintf(buffer,T));
#define printf2pc(T,...)   UART_SEND(sprintf(buffer,T,__VA_ARGS__));
void UART_SEND(int l);
char buffer[100];
void UART_SEND(int l)
{
	int i;
	for(i=0;i<l;i++)
	usart_putchar(&USARTD0,buffer[i]);
	
}

int main (void)
{

 	set_micro();
 	NRF_init();
	

	while(1)
    {
			
  			Nrf_Empty_Data();
  			NrF_Fill_Data(3,257,258,259); //biar to while
 			NRF_send();
 	     	_delay_ms(500); // ***baraye test 30 gozashtam, badan kamesh kon ya asan baresh dar
 
    }

	}


 ISR(PORTE_INT0_vect)////////////////////////////////////////PTX   IRQ Interrupt Pin
{ 
	PTX_IRQ();
	
}

