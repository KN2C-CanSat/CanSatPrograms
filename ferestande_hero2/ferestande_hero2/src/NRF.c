#include "NRF.h"


NRF_BOARD Nrf;


void NrF_Fill_Data(uint8_t num , ... ) //num: tedade dade
{
	va_list arguments; 	
	ch2int conv;
	va_start( arguments, num ); 
	
	for(int i=0;i < num;i++)
		{
			conv.real=va_arg( arguments, int ); //int por mishe
			Nrf.Check_Sum = Nrf.Check_Sum + (uint8_t)conv.byte[0] + (uint8_t)conv.byte[1]; 
			Nrf.data[Nrf.Len + 2] = conv.byte[0];
			Nrf.data[Nrf.Len + 2 + 1] = conv.byte[1];
			Nrf.Len = Nrf.Len + 2;
		}
	Nrf.data[2]=Nrf.Len+1;
	Nrf.data[Nrf.Len+2] = ~Nrf.Check_Sum + 1 ; //
	va_end ( arguments );
}





void Nrf_Empty_Data(void)
{
	for(uint8_t i=0;i<11;i++)
	Nrf.data[i]=0;
	
	Nrf.counter++;
	Nrf.Num = Nrf.counter;
	
	Nrf.Check_Sum = 0;
	Nrf.Len = 2;
	Nrf.data[0] = 0xff;
	Nrf.data[1] = 0xff;
	Nrf.data[2] = Nrf.Len;
	Nrf.data[3] = Nrf.Num;
	
}










