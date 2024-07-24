 /*
 * Hardware.h
 *
 *  Created on: Jul 8, 2024
 *      Author: irubt
 */

#ifndef INC_HARDWARE_H_
#define INC_HARDWARE_H_

#include "main.h"
#include "LoRa.h"
#include "stdbool.h"

typedef enum
{
	FWD_BACK_POTENZIOMETER = 0x00,
	RIGHT_LEFT_POTENZIOMETER = 0x01,

	FWD = 0x02,
	BACK = 0x03,
	LEFT = 0x04,
	RIGHT = 0x05,
	FWD_RIGHT = 0x06,
	BACK_RIGHT = 0x07,
	FWD_LEFT = 0x08,
	BACK_LEFT = 0x09,
	HOLD = 0x0A

}Constants;

typedef struct
{
	volatile U16 buffer_for_adc[2];
	U8 transmit_buff[1];
	LoRa tx_Lora;
	U8 tx_success;
}Tx;

#endif /* INC_HARDWARE_H_ */
