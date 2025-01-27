#include "qmanager.h"
#include "player.h"
#include "ball.h"
#include "powerup.h"

#define Q_SIZE 2

QOBJ gmpiniQ[Q_SIZE] = { 
	{&PLAYER_Init},
	{&BALL_Init},
	//{&POWERUP_Generate}
};
QOBJ gmpuQ[Q_SIZE] = 
{ 
	{&PLAYER_Controls},
	{&BALL_Movement},
	//{&POWERUP_Movement}
};
QOBJ gmpdQ[Q_SIZE] = 
{
	{&PLAYER_Draw},
	{&BALL_Draw},
	//{&POWERUP_Draw}
};

QMAP_Node QMAP[] =
{
	{GAMEPLAY_INIT_Q, gmpiniQ, sizeof(gmpiniQ)/sizeof(gmpiniQ[0])},
	{GAMEPLAY_U_Q, gmpuQ, sizeof(gmpuQ) / sizeof(gmpuQ[0])},
	{GAMEPLAY_D_Q, gmpdQ, sizeof(gmpdQ) / sizeof(gmpdQ[0])}
};
#define QMAP_SIZE sizeof(QMAP)/sizeof(QMAP[0])

int QM_GetSizeOfQ(QTYPE Q) 
{
	for (int i = 0; i < QMAP_SIZE; i++) 
	{
		if (QMAP[i].qType == Q) 
		{
			return QMAP[i].qSize;
		}
	}
}

QOBJ* QM_GetQueue(QTYPE Q)
{
	for (int i = 0; i < QMAP_SIZE; i++) 
	{
		if (QMAP[i].qType == Q) 
		{
			return &QMAP[i].qPtr[0];
		}
	}
}