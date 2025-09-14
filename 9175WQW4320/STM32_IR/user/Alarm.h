#ifndef _ALARM_H
#define	_ALARM_H

#include "stm32f10x.h"   

typedef struct Alarm_Time
{
	uint8_t day;
	uint8_t hour;
	uint8_t min;
}Alarm_Time;

extern uint8_t Alarm_Flag;


void Alarm_Init(void);

void Alarm_Proc(void);

//蜂鸣器Delay_us：间隔时间，单位ms
void Alarm_Delay(uint16_t Delay_us);

#endif
