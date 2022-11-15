/*
 * button.c
 *
 *  Created on: 4 thg 11, 2022
 *      Author: USER
 */


#include "button.h"
#include "main.h"
int KeyReg0[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int button_flag[NUM_OF_BUTTON] = {0,0,0};
int buttonBuffer[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

void getKeyInput(){
	for(int i = 0; i < NUM_OF_BUTTON; i++){
		  KeyReg2[i] = KeyReg1[i];
		  KeyReg1[i] = KeyReg0[i];
		  switch (i) {
			case 0:
				  KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, BUT1_Pin);
				break;
			case 1:
				  KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, BUT2_Pin);
				break;
			case 2:
				  KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, BUT3_Pin);
				break;
			default:
				break;
		  }
		  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			  if(buttonBuffer[i] != KeyReg2[i]){
				  buttonBuffer[i] = KeyReg2[i];
				  if(buttonBuffer[i] == PRESSED_STATE){
					  button_flag[i] = 1;
					  TimeOutForButtonPress[i] = 300;
				  }
			  }
			  else{
				  TimeOutForButtonPress[i]--;
				  if(TimeOutForButtonPress[i] <= 0){
					  buttonBuffer[i] = NORMAL_STATE;
				  }
			  }
		  }
	}
}


int isButtonPress(int index){
	if(index >= NUM_OF_BUTTON) return 0;
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
int Button1IsPressed(){
	return isButtonPress(0);
}
int Button2IsPressed(){
	return isButtonPress(1);
}
int Button3IsPressed(){
	return isButtonPress(2);
}
