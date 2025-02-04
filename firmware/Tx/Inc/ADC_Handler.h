/*
 * ADC_Handler.h
 *
 *  Created on: Jul 8, 2024
 *      Author: irubt
 */

#ifndef INC_ADC_HANDLER_H_
#define INC_ADC_HANDLER_H_

#include "Hardware.h"

#define BYTE 1
#define TIMEOUT 100

typedef enum
{
	LOGIC_LOW_ONE = 0,
	LOGIC_LOW_TWO = 200,

	LOGIC_HIGH_ONE = 3950,
	LOGIC_HIGH_TWO = 4095

}ADC_States;

void ADC_Filter_and_Transmit(Tx * transmitter, LoRa * _Lora);

#endif /* INC_ADC_HANDLER_H_ */
