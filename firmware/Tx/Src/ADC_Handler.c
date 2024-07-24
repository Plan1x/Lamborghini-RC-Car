/*
 * ADC_Handler.c
 *
 *  Created on: Jul 8, 2024
 *      Author: irubt
 */
#include "ADC_Handler.h"

static U8 filter(Tx * transmitter);

static U8 filter(Tx * transmitter)
{
	U8 val;

	if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= LOGIC_HIGH_ONE && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= LOGIC_HIGH_TWO && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= (LOGIC_LOW_TWO + 700) && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= (LOGIC_HIGH_ONE - 950))//forward
	{
		val = FWD;
	}else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= LOGIC_LOW_ONE && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= LOGIC_LOW_TWO && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= (LOGIC_LOW_TWO + 700) && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= (LOGIC_HIGH_ONE - 950))//back
	{
		val = BACK;
	}
	else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= (LOGIC_LOW_TWO + 700) && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= (LOGIC_HIGH_ONE - 950) && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= LOGIC_HIGH_ONE && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= LOGIC_HIGH_TWO)//left
	{
		val = LEFT;
	}else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= (LOGIC_LOW_TWO + 700) && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= (LOGIC_HIGH_ONE - 950) && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= LOGIC_LOW_ONE && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= LOGIC_LOW_TWO)//Right
	{
		val = RIGHT;
	}else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= LOGIC_HIGH_ONE && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= LOGIC_HIGH_TWO && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= LOGIC_LOW_ONE && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= LOGIC_LOW_TWO)//right and fwd
	{
        val = FWD_RIGHT;
	}else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= LOGIC_LOW_ONE && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= LOGIC_LOW_TWO && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= LOGIC_LOW_ONE && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= LOGIC_LOW_TWO)// Back and right
	{
		val = BACK_RIGHT;
	}else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= LOGIC_HIGH_ONE && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= LOGIC_HIGH_TWO && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= LOGIC_HIGH_ONE && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= LOGIC_HIGH_TWO)//Fwd and Left
	{
		val = FWD_LEFT;
	}else if(transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] >= LOGIC_LOW_ONE && transmitter -> buffer_for_adc[FWD_BACK_POTENZIOMETER] <= LOGIC_LOW_TWO && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] >= LOGIC_HIGH_ONE && transmitter -> buffer_for_adc[RIGHT_LEFT_POTENZIOMETER] <= LOGIC_HIGH_TWO)// Back and Left
	{
		val = BACK_LEFT;
	}else
	{
		val = HOLD;
	}

		return val;
}
void ADC_Filter_and_Transmit(Tx * transmitter, LoRa * _Lora)
{

	transmitter -> transmit_buff[0] = filter(transmitter);
	transmitter -> tx_success = LoRa_transmit(_Lora, transmitter -> transmit_buff, BYTE, TIMEOUT);
	LoRa_gotoMode(_Lora, STNBY_MODE);

}
