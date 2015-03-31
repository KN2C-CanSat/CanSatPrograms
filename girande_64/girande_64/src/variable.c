/*
 * variable.c
 *
 * Created: 1/28/2015 5:14:00 PM
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

char Buf_Rx_L[_Buffer_Size];
char buf_receive[11];
int Buf_Print[9];
//char str[32];
char Address[_Address_Width] = { 0x26, 0x22, 0x33, 0x44, 0x55};
uint8_t flag;
uint8_t copy_flag=1;
uint8_t decode_flag=0;


ch2int conv;
NRF_BOARD Nrf;