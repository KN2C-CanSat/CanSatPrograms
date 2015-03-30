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



int main (void)
{
	set_micro();
	NRF_init();

	
	while (1)
	{

   	//	if (flag==1)
   	//	{
 //        			for (int k=0;k<_Buffer_Size;k++) //nemidunam cheshe ke age ferestande andazeye buffersize data befreste ertebat nadaran! ama age ye dune kamtar bashe daran!! pas man yedune ro azafe mikonam ke null mishe va namayesh nemidam. ( _Buffer_Size-1 albate baresh dashtam )
 //        				usart_putchar(&USARTC0,buf_receive[k]);
  			
 //  			conv.byte[0]=buf_receive[0];
 // 			printf2pc("1:\r%d\r",conv.real);
 
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
 				NRF_decode();
 				
 				decode_flag=0;
 				copy_flag=1;
 				
 // 				for (int j=0;j<Len;j++)
 // 				printf2pc("data: %d\r",Buf_Print[j]);	
 			}
     				
   		//	flag =0;
 	
   	//	}
   		_delay_us(3);
			//printf2pc("257: %d\r",3);	  
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