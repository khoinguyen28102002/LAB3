/*
 * software_timer.c
 *
 *  Created on: 2 thg 11, 2022
 *      Author: USER
 */


/*
 * software_timer.c
 *
 *  Created on: Oct 3, 2022
 *      Author: USER
 */


#include"software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;
int timer3_counter = 0;
int timer3_flag = 0;
int TIME_CYCLE = 10;
void setTimer1(int duration){
	timer1_counter = duration/TIME_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_counter = duration/TIME_CYCLE;
	timer2_flag = 0;
}
void setTimer3(int duration){
	timer3_counter = duration/TIME_CYCLE;
	timer3_flag = 0;
}
void timerRun(){
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
	if(timer2_counter > 0){
		timer2_counter--;
		if(timer2_counter <= 0){
			timer2_flag = 1;
		}
	}
	if(timer3_counter > 0){
		timer3_counter--;
		if(timer3_counter <= 0){
			timer3_flag = 1;
		}
	}
}
