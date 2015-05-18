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
#include "MPC.h"


int main (void)
{
	set_micro();
	NRF_init();

	
	
	while (1)
	{

 
 			if (copy_flag==2)
 			{
 				//do copy	
 				for (int j=0;j<_Buffer_Size;j++)
 					buf_receive[j]=Buf_Rx_L[j];
 				
 				copy_flag=0; 		
 				decode_flag=1;
 			}
 			
 			if (decode_flag==1)
 			{
 				
 				//do decode
 				//NRF_decode();
 				for (uint8_t i=0;i<_Buffer_Size;i++)
						Mpc_decode(&MPC,buf_receive[i]);
				 
 				decode_flag=0;
 				copy_flag=1;

 			}

   		_delay_us(3);

 	}
}


ISR(TCD0_OVF_vect)
{
	
}

ISR(PRX_L)
{
	//flag=1;
	if (copy_flag==1)
	copy_flag=2;
	
	NRF_receive();
}

ISR(PRX_R)
{
	
}

ISR(USART_R_RXC_vect)
{

}

ISR(USART_R_DRE_vect) //Wireless_R_USART
{

}

//ISR(USART_L_RXC_vect)
//{
//
//
//}
//ISR(USART_L_DRE_vect) //Wireless_R_USART
//{
//
//}
//ISR(USART_M_DRE_vect)
//{
//
//}
//ISR(USART_M_RXC_vect)//usart test
//{
//
//}