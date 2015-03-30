/*
 * calculation.c
 *
 * Created: 1/26/2015 6:06:02 PM
 *  Author: Dell
 */ 

#include <asf.h>
#include "initialize.h"
#include "twi_master_driver.h"
#include <util/delay.h>
#include <avr/io.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculation.h"
#include "variable.h"
#include "define.h"
#include "setting.h"
#include "calculation.h"
#include "MS5611.h"

#define printf2pcs(T)      UART_SEND(sprintf(buffer,T));
#define printf2pc(T,...)   UART_SEND(sprintf(buffer,T,__VA_ARGS__));
void UART_SEND(int l);
char buffer[100];
void UART_SEND(int l)
{
	int i;
	for(i=0;i<l;i++)
	usart_putchar(&USARTD0,buffer[i]);
	
}

void calculate(unsigned int C1,unsigned int C2,unsigned int C3,unsigned int C4,unsigned int C5,unsigned int C6,long int D1,long int D2)
{


	
	float q;
	long int SENS;
	long int SENS2=0;
	long int OFF;
	long int OFF2=0;
	long int dT;
	float TEMP;
	float T2=0;
	
	long int pressure; //baraye chaap
	long int temperature;
	
	dT=(long int)D2-(long int)(C5*pow(2,8));
	TEMP=(2000+(C6/(float)pow(2,23))*dT)/100;
	OFF=pow(2,16)/16*C2+dT/pow(2,7)/16*C4;
	SENS=pow(2,15)/8*C1+dT/pow(2,8)/8*C3;

    	if (TEMP<20)
    	{
    		//T2=(dT/(float)pow(2,31))*dT;
    		OFF2=(pow((TEMP-2000),2)/(float)2)*5;
    		SENS2=(pow((TEMP-2000),2)/(float)4)*5;
    		
    		if (TEMP<-15)
    		{
    			OFF2=OFF2+7*pow((TEMP+1500),2);
    			SENS2=SENS2+(pow((TEMP+1500),2)/(float)2)*11;
    		}
    		
    		//TEMP=TEMP-T2;
    		OFF=OFF-OFF2;
    		SENS=SENS-SENS2;
    	}
 	
	
	pres[1]=SENS/(float)pow(2,21)/(float)pow(2,15)*8*D1;
	q=OFF/(float)pow(2,15)*16;
	pres[1]=(pres[1]-q)/(float)100;
	
	pres[1]=pres[1]*100;
	pressure=(long int)pres[1];
	
  	if (flag==1)  //bare aval last_data ba data barabare
  	{
  		pres[0]=pres[1];
  		flag=0;
  	}
  	
   	pres[1]=pres[0]+(0.025/(float)(0.025+1/(float)(2*(float)(3.14)*6)))*(pres[1]-pres[0]);    //filter
   	pres[0]=pres[1];

	 printf2pc("Pressure: %ld\r",pressure);
	 TEMP=TEMP*100;
	 temperature=(long int)TEMP;
	 //temperature=(long int)T2;
	 printf2pc("Temperature: %ld\r",temperature);

//test!

	
}
