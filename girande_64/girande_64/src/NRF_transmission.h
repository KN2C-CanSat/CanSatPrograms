/*
 * NRF_transmission.h
 *
 * Created: 1/28/2015 5:21:02 PM
 *  Author: Dell
 */ 


#ifndef NRF_TRANSMISSION_H_
#define NRF_TRANSMISSION_H_

// #define MPC_BUFF_AMOUNT  11
// typedef struct {
// 	
// 	int data[32];
// 	char pack_started;
// 	char sum;
// 	char Len;
// 	char ready;
// 	ch2int conv;
// 	int j;
// 	int data_num;
// 	uint8_t data_send[32];// age bekhad beshkane do bodish kon :p
// 	uint8_t State;
// 	uint8_t Num;
// 	uint8_t Check_Sum;
// 	uint8_t Len_send;
// 	int UART_IRQ_FLAG;
// 	uint8_t MPC_UART_BUFF[MPC_BUFF_AMOUNT];
// 	
// }_MPC;
// 
// extern _MPC MPC;


void NRF_init (void);
void NRF_receive (void);
void NRF_decode (void);


#endif /* NRF_TRANSMISSION_H_ */