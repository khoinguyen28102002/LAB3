/*
 * global.h
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "software_timer.h"
#include "button.h"
#include "traffic.h"
#include "main.h"


#define INIT				1
#define NORMAL_MODE 		2
#define MODIFY_RED_MODE 	3
#define MODIFY_YELLOW_MODE 	4
#define MODIFY_GREEN_MODE 	5

#define RED_ROW			12
#define GREEN_ROW		13
#define YELLOW_ROW		14
#define RED_COLUMN		15
#define GREEN_COLUMN	16
#define YELLOW_COLUMN	17

int status; // status of all system
int count;  // count is used for scan led in MODIFY MODE
int counter;// counter is used for scan led in NORMAL MODE
#endif /* INC_GLOBAL_H_ */
