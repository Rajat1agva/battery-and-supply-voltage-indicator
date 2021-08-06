/*
 * battery_supply_test.c
 *
 * Created: 8/5/2021 10:42:12 AM
 * 
 *  Author : RAJAT 
 */ 
#define  F_CPU	4000000UL
#include <avr/io.h>
#include "ADC_AVR128DA64 (1).h"
#include "UART_1_AVR128DA64.h"
void battery_Read(void);
void supply_Read(void);
void AVG(void);
int main(void)
{   ADC0_init();  //Initialize ADC
	ADC0_start(); //Start ADC
	USART1_init(9600);
    /* Replace with your application code */
    while (1) 
    {battery_Read();
	// supply_Read();	
	 
    }
}

void battery_Read(void)
{
uint16_t adc_value=ADC0_read(1);
float voltage_value=adc_value/1241.2121; //
USART1_sendFloat(voltage_value*3.636,2);
//USART1_sendInt(adc_value);
}
void supply_Read(void)
{
	uint16_t adc_value=ADC0_read(0);
	float voltage_value=adc_value/1241.2121;
	//USART1_sendInt(adc_value);
	USART1_sendFloat(voltage_value*3.636,2);
}
