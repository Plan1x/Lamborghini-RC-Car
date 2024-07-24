/*
 * Structs.h
 *
 *  Created on: Jun 22, 2024
 *      Author: irubt
 */

#ifndef INC_STRUCTS_H_
#define INC_STRUCTS_H_

#include "main.h"
#include "LoRa.h"
#include "gpio.h"

/*
  	BTN_UP = 0x01,
	BTN_DOWN = 0x02,
	BTN_RIGHT = 0x04,
	BTN_LEFT = 0x03
*/

typedef enum
{
	FWD = 0x02,
	BACK = 0x03,
	LEFT = 0x04,
	RIGHT = 0x05,
	FWD_RIGHT = 0x06,
	BACK_RIGHT = 0x07,
	FWD_LEFT = 0x08,
	BACK_LEFT = 0x09,
	HOLD = 0x0A

}Driving;
typedef struct
{
	U16 GPIO_Pin;
	GPIO_TypeDef* GPIO_Port;

}motor_hw;
typedef struct
{
	motor_hw val_1;
	motor_hw val_2;

}motor;
typedef struct
{
	motor front;
	motor back;
	LoRa Lora_rx;
	U8 rx_buff[1];
}Car;


void Driver(Car * machine);


#endif /* INC_STRUCTS_H_ */
