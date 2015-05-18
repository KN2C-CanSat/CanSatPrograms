#include "MPC.h"

_MPC MPC;
lngint2int finalpres;

  #define printf2pcs(T)      UART_SEND(sprintf(buffer,T));
  #define printf2pc(T,...)   UART_SEND(sprintf(buffer,T,__VA_ARGS__));
  void UART_SEND(int l);
  char buffer[100];
  
  void UART_SEND(int l)
  {
	  int i;
	  for(i=0;i<l;i++)
	  usart_putchar(&USARTC0,buffer[i]);
	  
  }
  

void Mpc_decode(_MPC* Mpc,uint8_t data)
{
	switch(Mpc->pack_started)
				{
					
					case 0:
						if(data == 0xff)
							Mpc->pack_started = 1;
						else
							Mpc->pack_started = 0;
						break;
						
					case 1:
						if(data == 0xff)
							Mpc->pack_started = 2;
						else
							Mpc->pack_started = 0;
						break;
						
					case 2:
						Mpc->Len =data - 3;
						//printf2pc("len:%c")
						Mpc->pack_started = 3;
						break;
						
					case 3:
				//if(data == 0)  man inja num (shomarepack) ro migiram. aghaye didari 0 migiran
						Mpc->Num=(uint8_t)data;
						printf2pc("num: %d\r",Mpc->Num);
						Mpc->pack_started = 4;
			//	else
			//		Mpc->pack_started = 0;
						break;
					case 4:
						
						if(Mpc->Len == 0)
						{
							
							Mpc->sum = Mpc->sum + (uint8_t)data;
							
							if(Mpc->sum == 0)
							{
								for (uint8_t k=0; k<(Mpc->j);k++)  //-2 baraye neshun nadadne bytehaye feshar
								printf2pc("%d\r",Mpc->data[k]); //vaghti az dorostie dadeha motmaen shodi ba checksum
								printf2pc("%ld\r",finalpres.lngint); //chape feshar
								Mpc->sum=0;
								Mpc->pack_started =0;
								Mpc->ready =1;		
								Mpc->data_num = Mpc->j;
								Mpc->j=0;
							}
							else
							{
								Mpc->j=0;
								Mpc->sum=0;
								Mpc->pack_started =0;
							}
							
						}
						else
						{
							Mpc->sum = Mpc->sum + (uint8_t)data;
							Mpc->pack_started =5;
							
 							if(Mpc->Len == 4)
 							{
	 							// 								finalpres.integer[0]=Mpc->conv.real;
	 							// 								printf2pc("pres: %ld\r",finalpres.lngint);
	 							//printf2pc("1 :%d\r",data);
								finalpres.charr[0]=data;
 							}
							 
							else if(Mpc->Len == 2)
 							{
// 								finalpres.integer[0]=Mpc->conv.real;
// 								printf2pc("pres: %ld\r",finalpres.lngint);
								//printf2pc("2 :%d\r",data);
								finalpres.charr[2]=data;
 							}
							
							
							else
							{
								Mpc->conv.byte[0] = data;
								
							}
							
						}
						break;
					case 5:
							
							Mpc->sum = Mpc->sum + (uint8_t)data;
							//Mpc->conv.byte[1] = data;
							Mpc->pack_started =4;
							//Mpc->data[Mpc->j] = Mpc->conv.real;	
							
							Mpc->Len = Mpc->Len - 2;
							//Mpc->j++;
							
							if(Mpc->Len == 2)
							{
								// 								finalpres.integer[0]=Mpc->conv.real;
								// 								printf2pc("pres: %ld\r",finalpres.lngint);
								//printf2pc("3 :%d\r",data);
								finalpres.charr[1]=data;
							}	
							
							else if(Mpc->Len == 0)
							{
								// 								finalpres.integer[0]=Mpc->conv.real;
								// 								printf2pc("pres: %ld\r",finalpres.lngint);
								//printf2pc("4 :%d\r",data);
								finalpres.charr[3]=data;								
								//printf2pc("pres:%ld\r",finalpres.lngint);
							}	
							
							else
							{
								
								Mpc->conv.byte[1] = data;
								//Mpc->pack_started =4;
								Mpc->data[Mpc->j] = Mpc->conv.real;	
								Mpc->j++;
							}		
						
						break;
						
				}
}

// void Mpc_Empty_Data(_MPC* Mpc)
// {
// 	for(int i=0;i<32;i++)
// 		Mpc->data_send[i]=0;
// 	Mpc->Num = 0;
// 	Mpc->Check_Sum = 0;
// 	Mpc->Len_send = 2;
// 	Mpc->data_send[0] = 0xff;
// 	Mpc->data_send[1] = 0xff;
// 	Mpc->data_send[2] = Mpc->Len_send;
// 	Mpc->data_send[3] = 0x00;//Mpc->Num;
// }
// 
// void Mpc_Fill_Data(_MPC* Mpc , uint8_t num , ... )
// {
// 	va_list arguments; 	
// 	ch2int conv;
// 	va_start( arguments, num ); 
// 	
// 	for(int i=0;i < num;i++)
// 		{
// 			conv.real=(uint16_t)va_arg( arguments, int );
// 			Mpc->Check_Sum = Mpc->Check_Sum + (uint8_t)conv.byte[0] + (uint8_t)conv.byte[1]; 
// 			Mpc->data_send[Mpc->Len_send + 2] = conv.byte[0];
// 			Mpc->data_send[Mpc->Len_send + 2 + 1] = conv.byte[1];
// 			Mpc->Len_send = Mpc->Len_send + 2;
// 		}
// 		
// 	va_end ( arguments );
// }
// 
// void Mpc_Send_Data(_MPC* Mpc)
// {
// 	Mpc->data_send[2] = Mpc->Len_send + 1;
// 	Mpc->data_send[Mpc->Len_send + 2] = ~(Mpc->Check_Sum) + 1;
// 	HAL_UART_Transmit(&huart4,(uint8_t*)Mpc->data_send, Mpc->Len_send + 3 , 1);
// 	Mpc_Empty_Data(Mpc);	
// }
// 
// 
// 
// 
// void Check_MPC_IRQ(_MPC* Mpc)
// {
// 	if(Mpc->UART_IRQ_FLAG)
// 		{
// 			if(!Mpc->ready)
// 			{
// 				int co = 0;
// 				for(co=0;co<MPC_BUFF_AMOUNT;co++)
// 				{
// 					Mpc_decode(Mpc,Mpc->MPC_UART_BUFF[co]);
// 				}
// 				
// 			}
// 			Mpc->UART_IRQ_FLAG = 0;
// 		}
// }
// 
