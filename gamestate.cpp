#include "gamestate.h"

GAMESTATE nGAMESTATE = MAINMENU;

GAMESTATE GAMESTATE_Get(void)
{
	return nGAMESTATE;
}

void GAMESTATE_Set(GAMESTATE state) 
{
	nGAMESTATE = state;
}