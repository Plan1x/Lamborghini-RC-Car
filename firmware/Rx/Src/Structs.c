/*
 * Structs.c
 *
 *  Created on: Jun 22, 2024
 *      Author: irubt
 */
#include "Structs.h"

Car Lamborghini;

static void GPIO_SET(motor_hw *val);
static void GPIO_RESET(motor_hw *val);
static void Move_FWD(void);
static void Move_Back(void);
static void Move_Right(void);
static void Move_Left(void);
static void Move_Right_and_FWD(void);
static void Move_Right_and_Back(void);
static void Move_Left_and_FWD(void);
static void Move_Left_and_Back(void);
static void RST_all(void);

static void Move_FWD(void)
{

 HAL_GPIO_WritePin(Lamborghini.back.val_1.GPIO_Port, Lamborghini.back.val_1.GPIO_Pin, GPIO_PIN_SET);
 HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_RESET);

}
static void Move_Back(void)
{

	HAL_GPIO_WritePin(Lamborghini.back.val_2.GPIO_Port, Lamborghini.back.val_2.GPIO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_RESET);

}
static void Move_Right(void)
{
	HAL_GPIO_WritePin(Lamborghini.front.val_2.GPIO_Port, Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin, GPIO_PIN_RESET);
}
static void Move_Left(void)
{
	HAL_GPIO_WritePin(Lamborghini.front.val_1.GPIO_Port, Lamborghini.front.val_1.GPIO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_RESET);
}
static void Move_Right_and_FWD(void)
{
	HAL_GPIO_WritePin(Lamborghini.back.val_1.GPIO_Port, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,  Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin, GPIO_PIN_RESET);
}

static void Move_Right_and_Back(void)
{
	HAL_GPIO_WritePin(Lamborghini.back.val_2.GPIO_Port, Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin, GPIO_PIN_RESET);

}
static void Move_Left_and_FWD(void)
{
	 HAL_GPIO_WritePin(Lamborghini.back.val_1.GPIO_Port, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_RESET);
}
static void Move_Left_and_Back(void)
{
	HAL_GPIO_WritePin(Lamborghini.back.val_2.GPIO_Port, Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_1.GPIO_Pin  | Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_RESET);
}
static void RST_all(void)
{
	HAL_GPIO_WritePin(GPIOA, Lamborghini.back.val_1.GPIO_Pin | Lamborghini.back.val_2.GPIO_Pin | Lamborghini.front.val_1.GPIO_Pin |Lamborghini.front.val_2.GPIO_Pin, GPIO_PIN_RESET);
}
/*static void GPIO_SET(motor_hw *val)
{
	HAL_GPIO_WritePin(val->GPIO_Port, val->GPIO_Pin, GPIO_PIN_SET);
}

static void GPIO_RESET(motor_hw *val)
{
	HAL_GPIO_WritePin(val->GPIO_Port, val->GPIO_Pin, GPIO_PIN_RESET);
}*/

	/*FWD = 0x02,
	BACK = 0x03,
	LEFT = 0x04,
	RIGHT = 0x05,
	FWD_RIGHT = 0x06,
	BACK_RIGHT = 0x07,
	FWD_LEFT = 0x08,
	BACK_LEFT = 0x09,
	HOLD = 0x0A*/
void Driver(Car *machine)
{
	switch (machine->rx_buff[0])
	{
	case FWD:
		Move_FWD();
		/*GPIO_SET(&(machine -> back.val_1)); //move forward
		GPIO_RESET(&(machine -> back.val_2));
		GPIO_RESET(&(machine -> front.val_1));
		GPIO_RESET(&(machine -> front.val_2));*/
		break;

	case BACK:
		Move_Back();
		/*GPIO_SET(&(machine -> back.val_2)); // move back
		GPIO_RESET(&(machine -> back.val_1));
		GPIO_RESET(&(machine -> front.val_1));
		GPIO_RESET(&(machine -> front.val_2));*/
		break;

	case LEFT:
		Move_Left();
		/*GPIO_SET(&(machine -> back.val_1)); //move left
		GPIO_SET(&(machine -> front.val_1));
		GPIO_RESET(&(machine -> back.val_2));
		GPIO_RESET(&(machine -> front.val_2));*/
		break;

	case RIGHT:
		Move_Right();
		/*GPIO_SET(&(machine -> back.val_1)); //move right
		GPIO_SET(&(machine -> front.val_2));
		GPIO_RESET(&(machine -> back.val_2));
		GPIO_RESET(&(machine -> front.val_1));*/
		break;
	case FWD_RIGHT:
		Move_Right_and_FWD();

		break;

	case BACK_RIGHT:
		Move_Right_and_Back();
		break;

	case FWD_LEFT:
		Move_Left_and_FWD();
		break;

	case BACK_LEFT:
		Move_Left_and_Back();

		break;

	default:
		/*GPIO_RESET(&(machine -> back.val_1));
		GPIO_RESET(&(machine -> back.val_2));
		GPIO_RESET(&(machine -> front.val_1));
		GPIO_RESET(&(machine -> front.val_2));*/
		RST_all();
		break;

	}
}
