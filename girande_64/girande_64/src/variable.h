/*
 * variable.h
 *
 * Created: 1/28/2015 5:13:47 PM
 *  Author: Dell
 */ 


#ifndef VARIABLE_H_
#define VARIABLE_H_
#define	_Address_Width	5	// 3..5
#define _Buffer_Size 32 // 1..32

extern char Buf_Rx_L[_Buffer_Size];
extern char buf_receive[11];
extern int Buf_Print[9];
//extern char str[32];
extern char Address[_Address_Width];
extern uint8_t flag;
extern uint8_t copy_flag;
extern uint8_t decode_flag;

union _ch2int
{
	int real;
	char byte[2];
};

typedef union _ch2int  ch2int;

extern ch2int conv;

  typedef struct {
	  
	  uint8_t Num;
	  uint8_t Check_Sum;
	  
  }NRF_BOARD;
  
 extern NRF_BOARD Nrf;
 //#define Len 0x09

#endif /* VARIABLE_H_ */