#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "gameobj.h"

typedef struct GAMEOBJ_PLAYER
{
	GAMEOBJ obj;
	int hp;
	int spd;
};

void PLAYER_Init(void);
void PLAYER_Controls(void);
void PLAYER_Draw(void);
int PLAYER_GetProperty(wchar_t c);

#endif // !PLAYER_H
