/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
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
#define F_CPU 32000000UL

int main (void)
{
 	   set_micro();
       reset();
     

 while (1)
 {
   	    PORTE_OUTSET = PIN3_bm;  //LED 
    	read_PROM();
    	D_read();
    	calculate(n[0],n[1],n[2],n[3],n[4],n[5],m[0],m[1]);
    		  
   	     
 }

	
	
}


ISR(TWIC_TWIM_vect)
{
	TWI_MasterInterruptHandler(&twiMaster);
}


 ISR(PORTE_INT1_vect)
 {
 	//PORTE_OUTCLR = PIN3_bm;  //LED
	//while ((PORTE.IN&0x04)==0)  chera kar nakard??
	
	PORTE_OUTCLR = PIN3_bm;  //LED
	
	 	
 }