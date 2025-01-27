#include "player.h"
#include "miscdefs.h"
#include "gametime.h"
#include "gamemath.h"

static GAMEOBJ_PLAYER player;

// == Pointers for readibility sakes ==
static float* posX = &player.obj.pos.x;
static float* posY = &player.obj.pos.y;
static float* sizeW = &player.obj.size.x;
static float* sizeH = &player.obj.size.y;
static COLOR_F* col = &player.obj.col;
static int* spd = &player.spd;
static VECTOR* vel = &player.obj.vel;

void PLAYER_Init(void) 
{
	*posX = SCREEN_W_DEFAULT / 2;
	*posY = SCREEN_H_DEFAULT - 30;
	*sizeW = 80;
	*sizeH = 12;
	*col = { 255, 0, 0, 255 };
	*spd = 500;
	*vel = { 0 };
}

void PLAYER_Controls(void) 
{
	VECTOR norm = {0};
	*vel = { 0 };

	if (CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) 
	{
		norm = GM_Normalize({-1,0,0});
		*vel = GM_Velocity(norm, *spd);
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D))
	{
		norm = GM_Normalize({ 1,0,0 });
		*vel = GM_Velocity(norm, *spd);
	}

	*posX += vel->x * GT_DeltaTime();
	if (*posX < *sizeW / 2) *posX = *sizeW / 2;
	if (*posX > SCREEN_W_DEFAULT - *sizeW / 2) *posX = SCREEN_W_DEFAULT - *sizeW / 2;
}

void PLAYER_Draw(void) 
{
	DrawBox(
		*posX - (*sizeW / 2), *posY - (*sizeH / 2),
		*posX + (*sizeW / 2), *posY + (*sizeH / 2),
		GetColor(col->r, col->g, col->b), TRUE
	);
}

int PLAYER_GetProperty(wchar_t c) 
{
	switch (c)
	{
		case L'x':
		case L'X': 
		{
				return *posX;
		}
		break;

		case L'y':
		case L'Y':
		{
				return *posY;
		}
		break;

		case L'w':
		case L'W':
		{
			return *sizeW;
		}
		break;

		case L'h':
		case L'H':
		{
			return *sizeH;
		}
		break;
	}
}