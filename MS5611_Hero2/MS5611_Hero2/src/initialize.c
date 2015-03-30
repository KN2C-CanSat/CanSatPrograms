/*
 * initialize.c
 *
 * Created: 3/22/2013 1:12:24 PM
 *  Author: Milad
 */


#include "initialize.h"
#include "twi_master_driver.h"
//Motor_Param M0,M1,M2,M3;

// void TWI_INIT(void)
// {
// 	
// }

void En_RC32M(void)
{
    // Start RC32M OSC
    OSC_CTRL |= OSC_RC32MEN_bm;
    while(!(OSC_STATUS & OSC_RC32MRDY_bm));

    // Select the system clock source: 32 MHz Internal RC Osc.
    CCP = CCP_IOREG_gc;
    CLK_CTRL = CLK_SCLKSEL_RC32M_gc;

    // Disable the unused oscillators: 2 MHz, internal 32 kHz, external clock/crystal oscillator, PLL
    OSC_CTRL &= ~(OSC_RC2MEN_bm | OSC_RC32KEN_bm | OSC_XOSCEN_bm | OSC_PLLEN_bm);
};

void PORT_init(void)
{
	//LED
	PORTE_DIRSET = PIN3_bm;  
	PORTE_OUTCLR = PIN3_bm;  
	
	//TX
	PORTD_DIRSET = PIN3_bm; 
	PORTD_OUTSET = PIN3_bm;
 
    //Measuring pressure button interrupt (INT1)///
 	PORTE_OUTSET=PIN2_bm;  ////ama kilid be vcc vasle! bepors bebin 0 esh koni mipoke ya na
 	PORTE_DIRCLR=PIN2_bm;
 	PORTE_PIN2CTRL |= PORT_ISC_RISING_gc;
 	PORTE_INTCTRL |= PORT_INT1LVL_HI_gc;
 	PORTE_INT1MASK |= PIN2_bm;
};
//
//void TimerC0_init(void)
//{
	//tc_write_clock_source(&TCC0,TC_CLKSEL_DIV256_gc);
	//tc_set_wgm(&TCC0,TC_WG_SS);
	//tc_write_period(&TCC0,0x00FF);
	//tc_set_direction(&TCC0,TC_UP);
	//tc_enable_cc_channels(&TCC0,TC_CCAEN);
	//tc_enable_cc_channels(&TCC0,TC_CCBEN);
	//tc_enable(&TCC0);
//};

//
//#define TIMERD0_PER 0x7D
//void TimerD0_init(void)
//{
	//tc_write_clock_source(&TCD0,TC_CLKSEL_DIV256_gc);
	//tc_set_wgm(&TCD0,TC_WG_NORMAL);
	//tc_set_overflow_interrupt_level(&TCD0,TC_INT_LVL_MED);
	//tc_write_period(&TCD0,TIMERD0_PER);
	//tc_set_direction(&TCD0,TC_UP);
	//tc_enable(&TCD0);
//};
//
//void SPI_Init(void)
//{
	 //spi_xmega_set_baud_div(&NRF24L01_L_SPI,8000000UL,F_CPU);
	 //spi_enable_master_mode(&NRF24L01_L_SPI);
	 //spi_enable(&NRF24L01_L_SPI);
//}
//
#define USARTD0_conf USARTD0
#define USARTD0_BUADRATE 115200
void USARTD0_init(void)
{
	usart_set_mode(&USARTD0_conf,USART_CMODE_ASYNCHRONOUS_gc);
	usart_format_set(&USARTD0_conf,USART_CHSIZE_8BIT_gc,USART_PMODE_DISABLED_gc,false);
	//usart_set_rx_interrupt_level(&USARTE0_conf,USART_INT_LVL_MED);
	//usart_set_dre_interrupt_level(&USARTE0_conf,USART_INT_LVL_LO);
	usart_set_baudrate(&USARTD0_conf,USARTD0_BUADRATE,F_CPU);
	usart_tx_enable(&USARTD0_conf);
	usart_rx_enable(&USARTD0_conf);
}

////KCK_CAP_VFB   -----> B7
//#define CONFIG_ADC_INTLVL ADC_CH_INTLVL_LO_gc
//void ADCA_init(void)
//{
    //struct adc_config adca_conf;
    //struct adc_channel_config adca_ch_conf;
    ////
    ////// Initialize configuration structures.
    ////adc_read_configuration(&ADCB, &adcb_conf);
    ////
    /////* Configure the ADC module:
    ////* - unsigned, 12-bit results
    ////* - AREFA voltage reference
    ////* - 8000 kHz clock rate
    ////* - FreeRun Mode
    ////*/
    //adc_get_calibration_data(ADC_CAL_ADCA);
    //adc_set_conversion_parameters(&adca_conf,ADC_SIGN_OFF,ADC_RES_12,ADC_REF_AREFA);
    //adc_set_clock_rate(&adca_conf,125000UL);
    //adc_set_conversion_trigger(&adca_conf,ADC_TRIG_FREERUN_SWEEP,1,0);
   //// adc_set_config_compare_value(adcb_conf,KCK_MAX_CHARGE_AMP);
    //adc_write_configuration(&ADCA,&adca_conf);
    ////
    /////* Configure ADC channel 0:
    ////* - Input: ADCB4
    ////* - interrupts disable
    ////*/
    //adcch_read_configuration(&ADCA,1, &adca_ch_conf);
    //adcch_set_input(&adca_ch_conf,ADCCH_POS_PIN3,ADCCH_NEG_NONE,ADC_CH_GAIN_1X_gc);
    //adcch_write_configuration(&ADCA,1,&adca_ch_conf);
    //
    /////* Configure ADC channel 1: darim az channel 0 estefade mikonim ehtemalan!
    ////* - Input: ADCB5
    ////* - Set Interrupt Mode: Below the threshold
    ////* - interrupts disable
    //////*/
    ////adcch_read_configuration(&ADCA,1, &adca_ch_conf);
    ////adcch_set_input(&adcb_ch_conf,ADCCH_POS_PIN5,ADCCH_NEG_NONE,ADC_CH_GAIN_1X_gc);
	//////adcch_set_interrupt_mode(&adcb_ch_conf,ADCCH_MODE_ABOVE);
	//////adcch_enable_interrupt(&adcb_ch_conf);
    ////adcch_write_configuration(&ADCA,1,&adca_ch_conf);
  //
	////
    /////* Configure ADC channel 2:
    ////* - Input: ADCB6
    ////* - interrupts disable
    ////*/
    ////adcch_read_configuration(&ADCB,2, &adcb_ch_conf);
    ////adcch_set_input(&adcb_ch_conf,ADCCH_POS_PIN6,ADCCH_NEG_NONE,ADC_CH_GAIN_1X_gc);
    //////adcch_disable_interrupt(&adcb_ch_conf);
    ////adcch_write_configuration(&ADCB,2,&adcb_ch_conf);
    //////
    /////* Configure ADC channel 3:
    ////* - Input: ADCB7
    ////* - interrupts disable
    ////*/
    ////adcch_read_configuration(&ADCB,3, &adcb_ch_conf);
    ////adcch_set_input(&adcb_ch_conf,ADCCH_POS_PIN7,ADCCH_NEG_NONE,ADC_CH_GAIN_1X_gc);
    ////adcch_set_interrupt_mode(&adcb_ch_conf,ADCCH_MODE_ABOVE);
    ////adcch_enable_interrupt(&adcb_ch_conf);
    ////adcch_write_configuration(&ADCB,3,&adcb_ch_conf);
    ////
    //adc_enable(&ADCA);
    //adc_start_conversion(&ADCA,ADC_CH0);
    ////adc_start_conversion(&ADCB,ADC_CH1);
    ////adc_start_conversion(&ADCB,ADC_CH2);
    //////adc_start_conversion(&ADCB,ADC_CH3);
//}
//
//void OUT_Bling(PORT_t *OUT_PORT,uint8_t OUT_PIN_bp,uint8_t Speed,uint32_t *Time_ON,uint32_t time_ms)
//{
	//if((*Time_ON) >0)
	//(*Time_ON)--;
	//if((Speed) != 0 && (*Time_ON) > 1)
	//OUT_PORT->OUT = (OUT_PORT->OUT & ~(1<<OUT_PIN_bp)) | (((time_ms / (Speed)) & 0x00001) << OUT_PIN_bp);
	////if((Speed) == 0 && (*Time_ON) >  1)		///////Set OUT
	////OUT_PORT->OUTSET = 1<<OUT_PIN_bp;
	//if((*Time_ON) == 1)						///////Clr OUT
	//OUT_PORT->OUTCLR = 1<<OUT_PIN_bp;
//}
//
