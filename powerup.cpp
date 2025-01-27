#include <stdlib.h>
#include "powerup.h"
#include "player.h"
#include "miscdefs.h"
#include "gametime.h"
#include "gamemath.h"

#define NPUPS_MAX 3
#define RAND_SPD_MIN 20
#define RAND_SPD_MAX 200
#define RAND_X_MIN 50
#define RAND_X_MAX (SCREEN_W_DEFAULT - 50)

GAMEOBJ_POWERUP nPUPS[NPUPS_MAX] = {0};

int spawnChance = 15;
int spawnInterval = 240;

void POWERUP_Generate(void) 
{
	for (int i = 0; i < NPUPS_MAX; i++) 
	{
		nPUPS[i].obj.col = { 0,0,255,255 };
		nPUPS[i].obj.size.x = 10;
		nPUPS[i].obj.size.y = 10;
		nPUPS[i].spd = 0;
		nPUPS[i].freezeTimer = 0;
		nPUPS[i].isActive = false;
	}
}

void POWERUP_Movement(void)
{
	for (int i = 0; i < NPUPS_MAX; i++) 
	{
		if (!nPUPS[i].isActive)
		{
			nPUPS[i].freezeTimer++;

			if (nPUPS[i].freezeTimer % spawnInterval == 0) 
			{
				int n_chance = GetRand(100);

				if (n_chance <= spawnChance)
				{
					nPUPS[i].spd = RAND_SPD_MIN + GetRand(RAND_SPD_MAX);
					nPUPS[i].obj.vel.y = 1;
					nPUPS[i].obj.pos.x = RAND_X_MIN + GetRand(RAND_X_MAX);
					nPUPS[i].obj.pos.y = 0;
					nPUPS[i].isActive = true;
					continue;
				}
				else 
				{
					nPUPS[i].freezeTimer = 0;
					continue;
				}
			}
		}

		if (nPUPS[i].isActive)
		{
			//*posX += vel->x * *spd * GT_DeltaTime();
			nPUPS[i].obj.pos.y += nPUPS[i].obj.vel.y * nPUPS[i].spd * GT_DeltaTime();
		}

		if (nPUPS[i].obj.pos.y > SCREEN_H_DEFAULT + 30) 
		{
			nPUPS[i].obj.pos.y = 0;
			nPUPS[i].isActive = false;
			nPUPS[i].freezeTimer = 0;
		}
	}
}

void POWERUP_Draw(void)
{
	for (int i = 0; i < NPUPS_MAX; i++) 
	{
		if (nPUPS[i].isActive) 
		{
			DrawBox(
				nPUPS[i].obj.pos.x - (nPUPS[i].obj.size.x / 2), nPUPS[i].obj.pos.y - (nPUPS[i].obj.size.y / 2),
				nPUPS[i].obj.pos.x + (nPUPS[i].obj.size.x / 2), nPUPS[i].obj.pos.y + (nPUPS[i].obj.size.y / 2),
				GetColor(nPUPS->obj.col.r, nPUPS->obj.col.g, nPUPS->obj.col.b), TRUE
			);
		}
	}
}