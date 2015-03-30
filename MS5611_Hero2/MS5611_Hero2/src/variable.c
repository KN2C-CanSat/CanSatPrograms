/*
 * variable.c
 *
 * Created: 1/26/2015 4:49:56 PM
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


unsigned char c[2];
unsigned char d[3];
unsigned char ms_reset=0x1E;
unsigned char PROM_read=0xA2;
unsigned char read_d=0x48;
unsigned char ADC_read=0x00;
unsigned int n[6];
unsigned long int m[2];
//int z=0;
float pres[3];
int flag=1;
//TWI_Master_t twiMaster;    /*!< TWI master module. */
int ff;
TWI_Master_t twiMaster;    /*!< TWI master module. */