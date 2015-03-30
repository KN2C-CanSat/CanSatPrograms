/*
 * setting.c
 *
 * Created: 1/26/2015 6:29:02 PM
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


void set_micro(void)
{

En_RC32M();
PMIC_CTRL |= PMIC_HILVLEN_bm | PMIC_LOLVLEN_bm |PMIC_MEDLVLEN_bm;
PORT_init();
USARTD0_init();

sei();

TWI_MasterInit(&twiMaster,&TWIC,TWI_MASTER_INTLVL_LO_gc,TWI_BAUDSETTING);	
TWIC.SLAVE.CTRLA=0;  //slave disabled


}