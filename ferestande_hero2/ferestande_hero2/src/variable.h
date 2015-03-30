/*
 * variable.h
 *
 * Created: 1/28/2015 4:20:43 PM
 *  Author: Dell
 */ 


#ifndef VARIABLE_H_
#define VARIABLE_H_

extern int test1;
extern char test2;
extern int test3;
extern char test4;
extern int test5;
extern int test6;

extern char str[4];
//********buffer size ro taghir dadam baraye test
extern char Buf_Tx[_Buffer_Size]; //{'a','b','c','d','e'}; //{'a','b','c','d','e','f','g','a','b','c','d','e','f','g','a','b','c','d','e','f','g','a','b','c','d','a','b','c','d','e','f','g'}; //= "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
extern char Address[_Address_Width];//pipe0 {0xE7,0xE7,0xE7,0xE7,0xE7};////
	





#endif /* VARIABLE_H_ */