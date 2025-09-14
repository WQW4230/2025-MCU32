#include "stm32f10x.h"
#include "stm32f10x_pal.h"
#include "OLED.h"
#include "remote_nec_driver.h"
#include "menu.h"
#include "GuessNum.h"
#include "GuessMine.h"
#include "Contact.h"
#include "GreedySnake.h"
#include "App_Timer.h"
#include "LED_Blink.h"
#include "arm_control.h"
#include "ps2_ADC_DMA.h"
#include "rtc_driver.h"
#include "Alarm.h"
#include "Ps2_key.h"

uint64_t Now = 0;
uint64_t Last = 0;
uint64_t Time = 0;

int main(void)
{
	OLED_Init();
	PAL_Init();
	
	App_Timer_Init();
	Capture_Config();
	MineBoard_Init();
	Contact_Init();
	Led_BlinkInit();
	ps2_ADCInit();
	Arm_Init();
	Rtc_Init();
	Alarm_Init();
  Ps2_KeyInit();
	
	while(1)
	{
		Last =  App_Timer_GetTick();

		Menu_Proc();	     		//1ms
		GuessNum_Proc();   		//1ms
		GuessMine_Proc(); 	  //1ms
		Contact_Proc();    	  //2ms
		GreedySnake_Proc(); 	//3ms
		Arm_Proc(); 					//1ms
		Alarm_Proc(); 				//2ms
		Led_Blink_Proc();     //2ms	
		
		
		Now = App_Timer_GetTick();
		if((Now - Last) > Time) 
		{
			Time = Now - Last;
		}
	}	
}

//最快需要14ms
//OLED_Clear();
//OLED_Printf()
//OLED_Update();

