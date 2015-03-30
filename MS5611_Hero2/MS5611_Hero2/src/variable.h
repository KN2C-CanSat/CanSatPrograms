/*
 * variable.h
 *
 * Created: 1/26/2015 4:50:15 PM
 *  Author: Dell
 */ 



#ifndef VARIABLE_H_
#define VARIABLE_H_

extern unsigned char c[2];
extern unsigned char d[3];
extern unsigned char ms_reset;
extern unsigned char PROM_read;
extern unsigned char read_d;
extern unsigned char ADC_read;
extern unsigned int n[6];
extern unsigned long int m[2];
// extern int z;
extern float pres[3];
extern int flag;
//extern TWI_Master_t twiMaster;    /*!< TWI master module. */
extern int ff;
extern TWI_Master_t twiMaster;    /*!< TWI master module. */


#endif /* VARIABLE_H_ */