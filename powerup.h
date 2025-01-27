#pragma once

#ifndef POWERUP_H
#define POWERUP_H

#include "gameobj.h"

typedef enum PTYPE
{
	LENGTH = 0,
	SPEED
};
#define PTYPES 2

typedef struct GAMEOBJ_POWERUP 
{
	GAMEOBJ obj;
	PTYPE ptype;
	int spd;
	int freezeTimer;
	bool isActive;
};

void POWERUP_Generate(void);
void POWERUP_Movement(void);
void POWERUP_Draw(void);

#endif