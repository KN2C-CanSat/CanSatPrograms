/*
 * NRF_transmission.c
 *
 * Created: 1/28/2015 5:21:20 PM
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
#include "NRF_transmission.h"

  #define printf2pcs(T)      UART_SEND(sprintf(buffer,T));
  #define printf2pc(T,...)   UART_SEND(sprintf(buffer,T,__VA_ARGS__));
  void UART_SEND(int l);
  char buffer[100];
 
  void UART_SEND(int l)
  {
  	int i;
  	for(i=0;i<l;i++)
  	usart_putchar(&USARTC0,buffer[i]);
 
  }

void NRF_init (void)
{
	NRF24L01_L_CE_LOW;       //disable transceiver modes
	

	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	_delay_us(10);
	_delay_ms(100);      //power on reset delay needs 100ms
	NRF24L01_L_Clear_Interrupts();
	
	NRF24L01_L_Flush_TX();
	
	NRF24L01_L_Flush_RX();
	

	NRF24L01_L_CE_LOW;
	NRF24L01_L_Init(_RX_MODE, _CH_L,_250k, Address, _Address_Width, _Buffer_Size, RF_PWR_MAX);

	NRF24L01_L_CE_HIGH;

	

	_delay_us(130);
}



void NRF_receive (void)
{
	uint8_t status_L = NRF24L01_L_WriteReg( W_REGISTER|STATUSe,_TX_DS|_MAX_RT);
	if((status_L & _RX_DR) == _RX_DR)
	{
		LED_White_L_PORT.OUTTGL = LED_White_L_PIN_bm; //
		
		do
		{
			NRF24L01_L_Read_RX_Buf(Buf_Rx_L , _Buffer_Size);

			//buf_receive[0]=Buf_Rx_L[1];

			//2) clear RX_DR IRQ,
			status_L=NRF24L01_L_WriteReg(W_REGISTER | STATUSe, _RX_DR );
			//3) read FIFO_STATUS to check if there are more payloads available in RX FIFO,
			//4) if there are more data in RX FIFO, repeat from step 1).
		} while((NRF24L01_L_ReadReg(FIFO_STATUS)&RX_EMPTY) == 0x00);
		flag=1;
		
	}
	

	if((status_L&_TX_DS) == _TX_DS)
	{
		LED_Green_L_PORT.OUTTGL = LED_Green_L_PIN_bm;
	}
	if ((status_L&_MAX_RT) == _MAX_RT)
	{
		NRF24L01_L_Flush_TX();
	}	
}

void NRF_decode (void)
{
// 	printf2pc("%c",buf_receive[0]);
// 	printf2pc("%c",buf_receive[1]);
// 	printf2pc("%c",buf_receive[2]);
	//for(uint8_t i=0;i<12;i++)
	//{	
		//uint8_t i=0;
		if ( (uint8_t)buf_receive[0] == 0xFF && (uint8_t)buf_receive[1] == 0xFF  && (uint8_t)buf_receive[2]== Len )
		{
			Nrf.Check_Sum=0;
			for (uint8_t k=4;k<=9;k++)
			Nrf.Check_Sum=Nrf.Check_Sum + buf_receive[k];
			
			if (Nrf.Check_Sum + buf_receive[10]==0)
			{
				Nrf.Num=(uint8_t)buf_receive[3];
 			 
				conv.byte[0]=buf_receive[4];
 				conv.byte[1]=buf_receive[5];
 				Buf_Print[0]=conv.real;
				printf2pc("num: %d\r",Nrf.Num);
				printf2pc("257: %d\r",Buf_Print[0]);
			
				conv.byte[0]=buf_receive[6];
				conv.byte[1]=buf_receive[7];
				Buf_Print[1]=conv.real;
 				printf2pc("258: %d\r",Buf_Print[1]);
			
				conv.byte[0]=buf_receive[8];
				conv.byte[1]=buf_receive[9];
				Buf_Print[2]=conv.real;
				printf2pc("259: %d\r",Buf_Print[2]); 
			
			}
			
			

		}
	//}
	
}