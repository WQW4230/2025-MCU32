#ifndef _GUESSMINE_H
#define _GUESSMINE_H

#include "stm32f10x.h"           


//雷数量
#define MINE_COUNT 10

//旗子数量
#define MINE_FLAG_COUNT 10;

//光标尺寸
#define WIDTH  6
#define HEIGHT 8

//雷区长度
#define ROW 8
#define COL 21

//棋盘长度
#define ROWS 23
#define COLS 10


extern uint8_t GuessMine_Flag;

void GuessMine_Proc(void);
void MineBoard_Init(void);//布置雷初始化函数

#endif
