/*
 * NRF_send.c
 *
 * Created: 1/28/2015 4:34:24 PM
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
#include "NRF_transmission.h"
#include "NRF.h"


void NRF_init (void)
{
	Address[0] = 0x26 ;
	Address[1] = 0x22;
	Address[2] = 0x33;
	Address[3] = 0x44;
	Address[4] = 0x55;

	///////////////////////////////////////////////////////////////////////////////////////////////Begin NRF Initialize
	NRF24L01_L_CE_LOW;       //disable transceiver modes

	

	_delay_us(10);
	_delay_ms(100);      //power on reset delay needs 100ms
	NRF24L01_L_Clear_Interrupts();
	NRF24L01_L_Flush_TX();
	NRF24L01_L_Flush_RX();
	NRF24L01_L_CE_LOW;
	
	NRF24L01_L_Init(_TX_MODE, _CH_1, _250k, Address, _Address_Width, _Buffer_Size, RF_PWR_MAX);
	
	NRF24L01_L_CE_HIGH;
	_delay_us(130);
	///////////////////////////////////////////////////////////////////////////////////////////////END   NRF Initialize
	Nrf.counter=0;
	
}


void NRF_send (void)
{
	NRF24L01_L_WriteRegBuf(W_REGISTER | (RX_ADDR_P0 ), Address, _Address_Width);
	NRF24L01_L_Set_TX_Address(Address, _Address_Width);
	NRF24L01_L_Write_TX_Buf(Nrf.data, _Buffer_Size);
	NRF24L01_L_RF_TX();
}




void PTX_IRQ (void)
{
		uint8_t status_L = NRF24L01_L_WriteReg(W_REGISTER | STATUSe, _TX_DS|_MAX_RT|_RX_DR);
		if((status_L & _RX_DR) == _RX_DR)
		{
			//LED_White_PORT.OUTTGL = LED_White_PIN_bm;
		}
		if((status_L&_TX_DS) == _TX_DS)
		{
			LED_Blue_PORT.OUTTGL = LED_Blue_PIN_bm;
			//PORTE_OUTTGL=LED_Blue_PIN_bm;
			
		}
		if ((status_L&_MAX_RT) == _MAX_RT)
		{
			//LED_Green_PORT.OUTTGL = LED_Green_PIN_bm;
			NRF24L01_L_Flush_TX();
		}
		
}