/*
 * API_debounce.c
 *
 *  Created on: Mar 27, 2025
 *  Author:     Alejo GM
 */

#include "stm32f4xx_hal.h"
#include "API_debounce.h"
#include "API_delay.h"

typedef enum debounceState_t
{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static debounceState_t currentState = BUTTON_UP;
static delay_t debounceDelay;
static bool keyPressed = false;
static const uint32_t debounceWait = 40;

bool readKey(){
	if(keyPressed){
		keyPressed = false;
		return true;
	}
	return false;
}

static bool isKeyPressed(){
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET;
}

void debounceFSM_init(){
	currentState = BUTTON_UP;
	delayInit(&debounceDelay, debounceWait);
}

void debounceFSM_update(){
	switch(currentState)
	{
	case BUTTON_UP:
		if(isKeyPressed()){
			currentState=BUTTON_FALLING;
			(void)delayRead(&debounceDelay); // inicio timer, debería devolver falso
		}
		break;
	case BUTTON_FALLING:
		if(delayRead(&debounceDelay)){
			//se cumplió el tiempo
			if(isKeyPressed()){
				currentState = BUTTON_DOWN;
				keyPressed = true;
			}else{
				currentState = BUTTON_UP;
			}
		}
		break;
	case BUTTON_DOWN:
		if(!isKeyPressed()){
			currentState = BUTTON_RAISING;
			(void)delayRead(&debounceDelay); // inicio timer, debería devolver falso
		}
		break;
	case BUTTON_RAISING:
		if(delayRead(&debounceDelay)){
			//se cumplió el tiempo
			if(!isKeyPressed()){
				currentState = BUTTON_UP;
			}else{
				currentState = BUTTON_DOWN;
			}
		}
		break;
	default:
		break;
	}
}
