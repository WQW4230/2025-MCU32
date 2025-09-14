#ifndef _ARM_CONTROL_H
#define	_ARM_CONTROL_H

#include "stm32f10x.h"  


#define ARM_STEP 10 //按键按下时角度变化值

#define FAN_MAX 100
#define FAN_MIN -100

typedef struct 
{
    float base;
    float shoulder;
    float elbow;
    int16_t FanSpeed;
}ServoAngles_t;

void Arm_Init(void);

void Arm_Proc(void);

extern uint8_t Arm_Flag;
#endif
