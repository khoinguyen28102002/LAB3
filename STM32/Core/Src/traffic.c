/*
 * display_led.c
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */

#include "traffic.h"
#include "global.h"
#include "main.h"

// initialize random time value for each traffic light
int time_red[2] = {0,5};
int time_yellow[2] = {0,2};
int time_green[2] = {0,3};

//initialize countdown value for each traffic light
int count_red_row[2] = {0,0};
int count_yellow_row[2] = {0,0};
int count_green_row[2]= {0,0};
int count_red_column[2] = {0,0};
int count_yellow_column[2] = {0,0};
int count_green_column[2] = {0,0};

void display_7SEG(int index){
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN3_Pin ,1) ;
			display7SEGA(led_buffer[0]);
			display7SEGB(led_buffer[2]);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin ,1);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN3_Pin ,0) ;
			display7SEGA(led_buffer[1]);
			display7SEGB(led_buffer[3]);
			break;
		default:
			break;
	}
}
void init_traffic_light(){
	turnOffAllLed();
	status_row = RED_ROW;
	status_column = GREEN_COLUMN;
	count_red_row[0] = count_red_column[0] = time_red[0];
	count_red_row[1] = count_red_column[1] = time_red[1];
	count_yellow_row[0] = count_yellow_column[0] = time_yellow[0];
	count_yellow_row[1] = count_yellow_column[1] = time_yellow[1];
	count_green_row[0] = count_green_column[0] = time_green[0];
	count_green_row[1] = count_green_column[1] = time_green[1];
	counter = 0;
}

void setRedLightInRow(){
	HAL_GPIO_WritePin(GPIOB, REDA_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, YELLOWA_Pin|GREENA_Pin, 1);
}
void setYellowLightInRow(){
	HAL_GPIO_WritePin(GPIOB, YELLOWA_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, REDA_Pin|GREENA_Pin, 1);
}
void setGreenLightInRow(){
	HAL_GPIO_WritePin(GPIOB, GREENA_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, REDA_Pin|YELLOWA_Pin, 1);
}
void setRedLightInColumn(){
	HAL_GPIO_WritePin(GPIOB, REDB_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, YELLOWB_Pin|GREENB_Pin, 1);
}
void setYellowLightInColumn(){
	HAL_GPIO_WritePin(GPIOB, YELLOWB_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, REDB_Pin|GREENB_Pin, 1);
}
void setGreenLightInColumn(){
	HAL_GPIO_WritePin(GPIOB, GREENB_Pin, 0);
	HAL_GPIO_WritePin(GPIOB, REDB_Pin|YELLOWB_Pin, 1);
}

void turnOffAllLed(){
	HAL_GPIO_WritePin(GPIOB, REDA_Pin|REDB_Pin|YELLOWA_Pin|YELLOWB_Pin|GREENA_Pin|GREENB_Pin, 1);
}
void display7SEGA(int num){
	if(num == 0){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA2_Pin|SEGA3_Pin|SEGA4_Pin|SEGA5_Pin|SEGA6_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA7_Pin, 1);
	}
	else if(num == 1){
		HAL_GPIO_WritePin(GPIOA, SEGA2_Pin|SEGA3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA5_Pin|SEGA6_Pin, 1);
	}
	else if(num == 2){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA5_Pin|SEGA2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA6_Pin|SEGA3_Pin, 1);
	}
	else if(num == 3){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA2_Pin|SEGA3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA5_Pin|SEGA6_Pin, 1);
	}
	else if(num == 4){
		HAL_GPIO_WritePin(GPIOA, SEGA6_Pin|SEGA2_Pin|SEGA3_Pin|SEGA7_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA4_Pin|SEGA5_Pin, 1);
	}
	else if(num == 5){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA6_Pin|SEGA3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA5_Pin|SEGA2_Pin, 1);
	}
	else if(num == 6){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA5_Pin|SEGA6_Pin|SEGA3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA2_Pin, 1);
	}
	else if(num == 7){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA2_Pin|SEGA3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA7_Pin|SEGA4_Pin|SEGA5_Pin|SEGA6_Pin, 1);
	}
	else if(num == 8){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA5_Pin|SEGA6_Pin|SEGA2_Pin|SEGA3_Pin, 0);
	}
	else if(num == 9){
		HAL_GPIO_WritePin(GPIOA, SEGA1_Pin|SEGA7_Pin|SEGA4_Pin|SEGA2_Pin|SEGA3_Pin|SEGA6_Pin|SEGA2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, SEGA5_Pin, 1);
	}
}
void display7SEGB(int num){
	if(num == 0){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB2_Pin|SEGB3_Pin|SEGB4_Pin|SEGB5_Pin|SEGB6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB7_Pin, 1);
	}
	else if(num == 1){
		HAL_GPIO_WritePin(GPIOB, SEGB2_Pin|SEGB3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB5_Pin|SEGB6_Pin, 1);
	}
	else if(num == 2){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB5_Pin|SEGB2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB6_Pin|SEGB3_Pin, 1);
	}
	else if(num == 3){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB2_Pin|SEGB3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB5_Pin|SEGB6_Pin, 1);
	}
	else if(num == 4){
		HAL_GPIO_WritePin(GPIOB, SEGB6_Pin|SEGB2_Pin|SEGB3_Pin|SEGB7_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB4_Pin|SEGB5_Pin, 1);
	}
	else if(num == 5){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB6_Pin|SEGB3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB5_Pin|SEGB2_Pin, 1);
	}
	else if(num == 6){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB5_Pin|SEGB6_Pin|SEGB3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB2_Pin, 1);
	}
	else if(num == 7){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB2_Pin|SEGB3_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB7_Pin|SEGB4_Pin|SEGB5_Pin|SEGB6_Pin, 1);
	}
	else if(num == 8){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB5_Pin|SEGB6_Pin|SEGB2_Pin|SEGB3_Pin, 0);
	}
	else if(num == 9){
		HAL_GPIO_WritePin(GPIOB, SEGB1_Pin|SEGB7_Pin|SEGB4_Pin|SEGB2_Pin|SEGB3_Pin|SEGB6_Pin|SEGB2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEGB5_Pin, 1);
	}
}
