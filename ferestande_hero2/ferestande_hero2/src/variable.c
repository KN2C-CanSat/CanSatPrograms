/*
 * variable.c
 *
 * Created: 1/28/2015 4:17:50 PM
 *  Author: Dell
 */ 

#include "initialize.h"
#include "nrf24l01_L.h"
#include "variable.h"

int test1=1;
char test2='\r';
int test3=3;
char test4='b';
int test5=7;
int test6=6;

char str[4];
//********buffer size ro taghir dadam baraye test
char Buf_Tx[_Buffer_Size]; //{'a','b','c','d','e'}; //{'a','b','c','d','e','f','g','a','b','c','d','e','f','g','a','b','c','d','e','f','g','a','b','c','d','a','b','c','d','e','f','g'}; //= "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
char Address[_Address_Width];//pipe0 {0xE7,0xE7,0xE7,0xE7,0xE7};////

	


