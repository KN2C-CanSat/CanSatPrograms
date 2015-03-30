#ifndef H_NRF_H
#define H_NRF_H
#include <asf.h>
#include "stdarg.h"


union _ch2int
{
	int real;
	char byte[2];
};

typedef union _ch2int  ch2int;




 typedef struct {
	 
	uint8_t Add;	 
	char    data[10];// age bekhad beshkane do bodish kon :p
	uint8_t State;
	uint8_t Num;
	uint8_t Check_Sum;
	uint8_t Len;
	uint8_t g_data;
	int counter;
	 
}NRF_BOARD;
 
extern NRF_BOARD Nrf;

void Nrf_Empty_Data(void);
void NrF_Fill_Data( uint8_t num , ... );

#endif 

