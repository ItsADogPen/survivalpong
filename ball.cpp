#include <stdlib.h>
#include "ball.h"
#include "player.h"
#include "miscdefs.h"
#include "gametime.h"
#include "gamemath.h"
#include "gamestate.h"

static GAMEOBJ_BALL ball;
float velLim = 5;
int ballSpawnChance = 50;

#define MAX_BALLS 10
GAMEOBJ_BALL nBalls[MAX_BALLS] = {0};

void BALL_Init(void)
{
	for (int i = 0; i < MAX_BALLS; i++) 
	{
		if (i == 0) nBalls[i].isActive = true;
		else		nBalls[i].isActive = false;
		nBalls[i].obj.pos.x = 50 + (GetRand(SCREEN_W_DEFAULT) - 50);
		nBalls[i].obj.pos.y = 10;
		nBalls[i].obj.size.x = 10;
		nBalls[i].obj.col = {255, 255, 255, 255};
		nBalls[i].obj.vel.x = 5;
		nBalls[i].obj.vel.y = 5;
		nBalls[i].spd = 10;
	}
	nBalls[0].spd = 30;
}

void BALL_Movement(void)
{
	for (int i = 0; i < MAX_BALLS; i++) 
	{
		if (nBalls[i].isActive) 
		{
			int sign = 0;

			// -- Corner screen collisions --
			nBalls[i].obj.pos.x += nBalls[i].obj.vel.x * nBalls[i].spd * GT_DeltaTime();
			if ((nBalls[i].obj.pos.x < nBalls[i].obj.size.x && nBalls[i].obj.vel.x < 0)
				||
				(nBalls[i].obj.pos.x > SCREEN_W_DEFAULT - nBalls[i].obj.size.x && nBalls[i].obj.vel.x > 0))
			{
				sign = nBalls[i].obj.vel.x < 0 ? 1 : -1;
				nBalls[i].obj.vel.x = (nBalls[i].obj.vel.x * -1) + ((rand() * sign) % (int)velLim);
			}
			if (nBalls[i].obj.vel.x < -velLim)	nBalls[i].obj.vel.x = -velLim;
			if (nBalls[i].obj.vel.x > velLim)	nBalls[i].obj.vel.x = velLim;

			nBalls[i].obj.pos.y += nBalls[i].obj.vel.y * nBalls[i].spd * GT_DeltaTime();
			if ((nBalls[i].obj.pos.y < nBalls[i].obj.size.x && nBalls[i].obj.vel.y < 0)
				//||
				//(nBalls[i].obj.pos.y > SCREEN_H_DEFAULT - nBalls[i].obj.size.x && nBalls[i].obj.vel.y > 0)
				)
			{
				sign = nBalls[i].obj.vel.y < 0 ? 1 : -1;
				nBalls[i].obj.vel.y = (nBalls[i].obj.vel.y * -1) + ((rand() * sign) % (int)velLim);
			}
			if (nBalls[i].obj.vel.y < -velLim)	nBalls[i].obj.vel.y = -velLim * nBalls[i].spd * GT_DeltaTime();
			if (nBalls[i].obj.vel.y > velLim)	nBalls[i].obj.vel.y = velLim * nBalls[i].spd * GT_DeltaTime();

			// If any balls drop below screen
			if (nBalls[i].obj.pos.y > SCREEN_H_DEFAULT)
			{
				GAMESTATE_Set(GAMEOVER);
			}

			// -----------------------------------

			// -- Collision against player racket --
			int pX = PLAYER_GetProperty('x');
			int pY = PLAYER_GetProperty('y');

			int dx = nBalls[i].obj.pos.x - pX;
			int dy = nBalls[i].obj.pos.y - pY;
			if (((-PLAYER_GetProperty('w') / 2) - 10 < dx)
				&&
				dx < ((PLAYER_GetProperty('w') / 2) + 10)
				&&
				-20 < dy && dy < 0)
			{
				nBalls[i].obj.vel.y = (-velLim - rand() % (int)velLim) * nBalls[i].spd * GT_DeltaTime();;
				velLim += 0.100000f;

				int n_chance = GetRand(100);
				if (n_chance <= ballSpawnChance)
				{
					for (int j = i; j < MAX_BALLS; j++) 
					{
						if (!nBalls[j].isActive) 
						{
							nBalls[j].isActive = true;
							break;
						}
					}
				}
			}
		}
	}
}

void BALL_Draw(void)
{
	for (int i = 0; i < MAX_BALLS; i++) 
	{
		if (nBalls[i].isActive) 
		{
			DrawCircle(nBalls[i].obj.pos.x, nBalls[i].obj.pos.y,
				nBalls[i].obj.size.x,
				GetColor(nBalls[i].obj.col.r, nBalls[i].obj.col.g, nBalls[i].obj.col.b), TRUE);
		}
	}
}