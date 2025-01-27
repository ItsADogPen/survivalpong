#pragma once

#ifndef QMANAGER_H
#define QMANAGER_H

#include "DxLib.h"

typedef enum QTYPE 
{
	UPDATE_Q,
	DRAW_Q,
	MAINMENU_Q,
	GAMEPLAY_INIT_Q,
	GAMEPLAY_U_Q,
	GAMEPLAY_D_Q
}QTYPE;

typedef struct QOBJ
{
	void (*process_func)(void);
}QOBJ;

typedef struct QMAP_Node 
{
	QTYPE qType;
	QOBJ* qPtr;
	int qSize;
}QMAP_NODE;

int QM_GetSizeOfQ(QTYPE Q);
QOBJ* QM_GetQueue(QTYPE Q);

#endif // !QMANAGER_H
