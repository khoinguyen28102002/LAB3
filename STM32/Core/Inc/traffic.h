/*
 * display_led.h
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

// time buffer for each led
int time_red[2];
int time_yellow[2];
int time_green[2];

// counter array for each led in row
int count_red_row[2];
int count_yellow_row[2];
int count_green_row[2];
// counter array for each led in column
int count_red_column[2];
int count_yellow_column[2];
int count_green_column[2];

int status_row; // status of traffic light in row
int status_column; // status of traffic light in column
int led_buffer[4]; // buffer for 4 7SEG led

void display_7SEG(int index);
void display_traffic_light();
void display7SEGA(int num);
void display7SEGB(int num);
void turnOffAllLed();
void init_traffic_light();
void setRedLightInRow();
void setYellowLightInRow();
void setGreenLightInRow();
void setRedLightInColumn();
void setYellowLightInColumn();
void setGreenLightInColumn();
#endif /* INC_TRAFFIC_H_ */
