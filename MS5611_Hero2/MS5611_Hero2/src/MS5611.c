/*
 * MS5611.c
 *
 * Created: 1/26/2015 6:17:02 PM
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


 void reset(void)
 {

	 TWI_MasterWriteRead(&twiMaster,MS5607_ADD,&ms_reset,1,0);
 	 while (twiMaster.status != TWIM_STATUS_READY) {
      /* Wait until transaction is complete. */
      }
	 _delay_ms(3);
	 PORTD_OUTSET=LED_White_PIN_bm;
	
	  
 }


 
   void read_PROM(void)
   {
   	 int i;
   	 PROM_read=0xA2;
   	 
   	 for(i=0;i<6;i++)
   	 {
   		  TWI_MasterWriteRead(&twiMaster,MS5607_ADD,&PROM_read,1,2);
    		  while (twiMaster.status != TWIM_STATUS_READY) {
    			  /* Wait until transaction is complete. */
    		  }
   		 PROM_read=PROM_read+2;
		 c[0]=twiMaster.readData[0];
		 c[1]=twiMaster.readData[1];	
   		 n[i]=(unsigned int)c[0]*256+(unsigned int)c[1];   //avali MSB
			
   	 }

  	 
   }
   
   
   void D_read(void)
   {
  	 
   	 int j=0,i;
   	 read_d=0x48;
   	 
   	 for(i=0;i<2;i++)
   	 {
   		  TWI_MasterWriteRead(&twiMaster,MS5607_ADD,&read_d,1,0);
    		  while (twiMaster.status != TWIM_STATUS_READY) {    //ino mizaram gir mikone
    			  /* Wait until transaction is complete. */
    		  }
   		 _delay_ms(10);
   		 TWI_MasterWriteRead(&twiMaster,MS5607_ADD,&ADC_read,1,3);
    		 while (twiMaster.status != TWIM_STATUS_READY) {    //ino mizaram gir mikone
    			 /* Wait until transaction is complete. */
    		 }
   		 read_d=read_d+16;
		 d[0]=twiMaster.readData[0];
		 d[1]=twiMaster.readData[1];
		 d[2]=twiMaster.readData[2];
		 	
   		 m[i]=(unsigned long int)d[2]+(unsigned long int)d[1]*256+(unsigned long int)d[0]*65536;   
   	 }
  
  	 
  
   }