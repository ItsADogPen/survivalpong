#pragma once

#ifndef GAMESTATE_H
#define	GAMESTATE_H

#include "DxLib.h"

typedef enum
{
	MAINMENU = 0,
	GAMEPLAY,
	GAMEOVER
}GAMESTATE;
extern GAMESTATE nGAMESTATE;

GAMESTATE GAMESTATE_Get(void);
void GAMESTATE_Set(GAMESTATE state);


#endif // !GAMESTATE_HEADER