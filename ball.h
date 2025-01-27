#pragma once

#ifndef BALL_H
#define BALL_H

#include "gameobj.h"

typedef struct GAMEOBJ_BALL
{
	GAMEOBJ obj;
	int spd;
	bool isActive;
};

void BALL_Init(void);
void BALL_Movement(void);
void BALL_Draw(void);

#endif // !BALL_H
