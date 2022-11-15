/*
 * fsm_automatic.c
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */

#include "fsm_automatic.h"
#include "traffic.h"
#include "global.h"
#include "main.h"

void auto_run_traffic_light(){
	// check the status of traffic lights in row
	switch (status_row) {
		case RED_ROW:
			setRedLightInRow();
			//countdown time for red light in row
			count_red_row[1]--;
			if(count_red_row[1] < 0){
				count_red_row[0]--;
				count_red_row[1] = 9;
			}
			// update value for 2 first 7SEG led
			led_buffer[0] = count_red_row[0];
			led_buffer[1] = count_red_row[1];
			// if time for the red light in row expired, turn to GREEN status
			if(count_red_row[0] <= 0 && count_red_row[1] <= 0){
				count_red_row[0] = time_red[0];
				count_red_row[1] = time_red[1];
				status_row = GREEN_ROW;
			}
			break;
		case YELLOW_ROW:
			setYellowLightInRow();
			// Countdown time for yellow light in row
			count_yellow_row[1]--;
			if(count_yellow_row[1] < 0){
				count_yellow_row[0]--;
				count_yellow_row[1] = 9;
			}
			// Update value for 2 first 7SEG led
			led_buffer[0] = count_yellow_row[0];
			led_buffer[1] = count_yellow_row[1];
			// if time for the yellow light in row expired, turn to RED status
			if(count_yellow_row[0] <= 0 && count_yellow_row[1] <= 0){
				count_yellow_row[0] = time_yellow[0];
				count_yellow_row[1] = time_yellow[1];
				status_row = RED_ROW;
			}
			break;
		case GREEN_ROW:
			setGreenLightInRow();
			// Countdown time for green light in row
			count_green_row[1]--;
			if(count_green_row[1] < 0){
				count_green_row[0]--;
				count_green_row[1] = 9;
			}
			// Update value for 2 first 7SEG led
			led_buffer[0] = count_green_row[0];
			led_buffer[1] = count_green_row[1];
			// if time for the green light in row expired, turn to YELLOW status
			if(count_green_row[0] <= 0 && count_green_row[1] <= 0){
				count_green_row[0] = time_green[0];
				count_green_row[1] = time_green[1];
				status_row = YELLOW_ROW;
			}
		default:
			break;
	}
	// Check the status of traffic lights in column
	switch (status_column) {
		case RED_COLUMN:
			setRedLightInColumn();
			// Countdown time for red light in column
			count_red_column[1]--;
			if(count_red_column[1] < 0){
				count_red_column[0]--;
				count_red_column[1] = 9;
			}
			// Update value for 2 second 7SEG led
			led_buffer[2] = count_red_column[0];
			led_buffer[3] = count_red_column[1];
			// if time for the red light in column expired, turn to GREEN status
			if(count_red_column[0] <= 0 && count_red_column[1] <= 0){
				count_red_column[0] = time_red[0];
				count_red_column[1] = time_red[1];
				status_column = GREEN_COLUMN;
			}
			break;
		case YELLOW_COLUMN:
			setYellowLightInColumn();
			// Countdown time for yellow light in column
			count_yellow_column[1]--;
			if(count_yellow_column[1] < 0){
				count_yellow_column[0]--;
				count_yellow_column[1] = 9;
			}
			// Update value for 2 second 7SEG led
			led_buffer[2] = count_yellow_column[0];
			led_buffer[3] = count_yellow_column[1];
			// if time for the yellow light in column expired, turn to RED status
			if(count_yellow_column[0] <= 0 && count_yellow_column[1] <= 0){
				count_yellow_column[0] = time_yellow[0];
				count_yellow_column[1] = time_yellow[1];
				status_column = RED_COLUMN;
			}
			break;
		case GREEN_COLUMN:
			setGreenLightInColumn();
			// Countdown time for yellow light in column
			count_green_column[1]--;
			if(count_green_column[1] < 0){
				count_green_column[0]--;
				count_green_column[1] = 9;
			}
			// Update value for 2 second 7SEG led
			led_buffer[2] = count_green_column[0];
			led_buffer[3] = count_green_column[1];
			// if time for the green light in column expired, turn to YELLOW status
			if(count_green_column[0] <= 0 && count_green_column[1] <= 0){
				count_green_column[0] = time_green[0];
				count_green_column[1] = time_green[1];
				status_column = YELLOW_COLUMN;
			}
			break;
		default:
			break;
	}
}
