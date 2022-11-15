/*
 * fsm_system.c
 *
 *  Created on: 15 thg 11, 2022
 *      Author: USER
 */


#include "fsm_system.h"
#include "fsm_automatic.h"
#include "global.h"
#include "button.h"

void RunSystem(){
	switch (status) {
		case INIT:
			//init parameters (time for traffic light, 7SEG led) for fsm of system
			init_traffic_light();
			status = NORMAL_MODE;
			setTimer2(500);
			setTimer3(500);
			break;
		// NORMAL_MODE : The traffic light application is running normally
		case NORMAL_MODE:
			if(timer2_flag){
				auto_run_traffic_light();
				setTimer2(1000);
			}
			display_7SEG(counter);
			if(timer3_flag){
				counter++;
				if(counter > 1){
					counter = 0;
				}
				setTimer3(500);
			}
			if(Button1IsPressed()){ // If button1 is pressed, turn to MODIFY RED MODE status
				status = MODIFY_RED_MODE;
				setTimer1(500); // timer for scan 7SEG led
				setTimer3(500); // timer for blinky red led
				turnOffAllLed();
			}
			break;
		case MODIFY_RED_MODE:
			if(Button2IsPressed()){
				//increase time for red light (both sides)
				time_red[1]++;
				if(time_red[1] > 9){
					time_red[0]++;
					time_red[1] = 0;
					if(time_red[0] > 9 )
						time_red[0] = 0;
				}
			}
			if(timer1_flag){
				// update value for 4 7SEG led
				led_buffer[0] = 0;
				led_buffer[1] = 2;
				led_buffer[2] = time_red[0];
				led_buffer[3] = time_red[1];
				display_7SEG(count);
				count++;
				if(count > 1){
					count = 0;
				}
				setTimer1(500);
			}
			if(timer3_flag){ // blinky red led every 0.5s (2Hz)
				HAL_GPIO_TogglePin(GPIOB, REDA_Pin|REDB_Pin);
				setTimer3(500);
			}
			if(Button1IsPressed()){
				status = MODIFY_YELLOW_MODE;// if button1 is pressed, turn to MODIFY YELLOW MODE
				setTimer1(500);// timer for scan 7SEG led
				setTimer3(500); // timer for blinky yellow led
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				// if button3 is pressed, turn to NORMAL MODE
				count_red_row[0] = time_red[0];
				count_red_row[1] = time_red[1];
				count_red_column[0] = time_red[0];
				count_red_column[1] = time_red[1];
				status = NORMAL_MODE;
			}
			break;
		case MODIFY_YELLOW_MODE:
			if(Button2IsPressed()){
				//increase time for yellow light (both sides)
				time_yellow[1]++;
				if(time_yellow[1] > 9){
					time_yellow[0]++;
					time_yellow[1] = 0;
					if(time_yellow[0] > 9 )
					time_yellow[0] = 0;
				}
			}
			if(timer1_flag){
				// update value of 4 7SEG led
				led_buffer[0] = 0;
				led_buffer[1] = 3;
				led_buffer[2] = time_yellow[0];
				led_buffer[3] = time_yellow[1];
				display_7SEG(count);
				count++;
				if(count > 1){
					count = 0;
				}
				setTimer1(500);
			}
			if(timer3_flag){ // blinky all yellow led
				HAL_GPIO_TogglePin(GPIOB, YELLOWA_Pin|YELLOWB_Pin);
				setTimer3(500);
			}
			if(Button1IsPressed()){
				status = MODIFY_GREEN_MODE; // if button1 is pressed, turn to MODIFY GREEN MODE status
				setTimer1(500); // timer for scan 7SEG led
				setTimer3(500); // timer for blinky green led
				turnOffAllLed();
			}
			if(Button3IsPressed()){
				// if button3 is pressed, turn to NORMAL MODE status
				count_yellow_row[0] = time_yellow[0];
				count_yellow_row[1] = time_yellow[1];
				count_yellow_column[0] = time_yellow[0];
				count_yellow_column[1] = time_yellow[1];
				status = NORMAL_MODE;
			}
			break;
		case MODIFY_GREEN_MODE:
			if(Button2IsPressed()){
				//increase time for green light (both sides)
				time_green[1]++;
				if(time_green[1] > 9){
					time_green[0]++;
					time_green[1] = 0;
					if(time_green[0] > 9 )
					time_green[0] = 0;
				}
			}
			if(timer1_flag){
				// update value of 4 7SEG led
				led_buffer[0] = 0;
				led_buffer[1] = 4;
				led_buffer[2] = time_green[0];
				led_buffer[3] = time_green[1];
				display_7SEG(count);
				count++;
				if(count > 1){
					count = 0;
				}
				setTimer1(500);
			}
			if(timer3_flag){ // blinky all green led every 0.5s (2Hz)
				HAL_GPIO_TogglePin(GPIOB, GREENA_Pin|GREENB_Pin);
				setTimer3(500);
			}
			if(Button1IsPressed()){
				// if button1 is pressed, turn to NORMAL MODE status
				status = NORMAL_MODE;
				setTimer2(500);
				setTimer1(500);
			}
			if(Button3IsPressed()){
				// if button3 is pressed, turn to NORMAL MODE status
				count_green_row[0] = time_green[0];
				count_green_row[1] = time_green[1];
				count_green_column[0] = time_green[0];
				count_green_column[1] = time_green[1];
				status = NORMAL_MODE;
			}
			break;
		default:
			break;
	}
}
