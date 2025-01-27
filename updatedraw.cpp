#include "updatedraw.h"
#include "gametime.h"

static int uqSize = 0;
// === Update Queue ===
static QOBJ* updateQ;

static int dqSize = 0;
// == Draw Queue ==
static QOBJ* drawQ;

void UpdateDrawManagerInit() 
{
}

void UpdateDraw(GAMESTATE state) 
{
	GT_QueryPerfCounterNow();
	UpdateLoop(state);
	DrawLoop(state);
	GT_QueryPerfCounterPrev();
}

void UpdateLoop(GAMESTATE state) 
{
	switch (state)
	{
		case MAINMENU:
		{
				// Main menu jizz
				

				if (CheckHitKey(KEY_INPUT_0)) 
				{
					updateQ = QM_GetQueue(GAMEPLAY_INIT_Q);
					uqSize = QM_GetSizeOfQ(GAMEPLAY_INIT_Q);

					GAMESTATE_Set(GAMEPLAY);
				}
		}
		break;
		
		case GAMEPLAY:
		{
				updateQ = QM_GetQueue(GAMEPLAY_U_Q);
				uqSize = QM_GetSizeOfQ(GAMEPLAY_U_Q);
		}
		break;

		case GAMEOVER: 
		{

		}break;
	default:
		break;
	}

	// -- Process Q --
	for (int i = 0; i < uqSize; i++)
	{
		updateQ[i].process_func();
	}

	GT_UpdateFPS();
}

void DrawLoop(GAMESTATE state) 
{
	switch (state)
	{
		case MAINMENU:
		{
				static int timer = 0;

				timer++;
				// Main menu jizz
				SetFontSize(50);
				DrawString(
					(SCREEN_W_DEFAULT / 2) - (50 / 2 * 12 / 2),
					SCREEN_H_DEFAULT / 3,
					L"Survival Pong", 0x00ff00);

				if (timer % 60 < 30) 
				{
					SetFontSize(30);
					DrawString(
						(SCREEN_W_DEFAULT / 2) - (30 / 2 * 21 / 2),
						SCREEN_H_DEFAULT * 2 / 3,
						L"Press 0 to start", 0x00ffff);
				}
		}
		break;
	
		case GAMEPLAY:
		{
				drawQ = QM_GetQueue(GAMEPLAY_D_Q);
				dqSize = QM_GetSizeOfQ(GAMEPLAY_D_Q);
		}
		break;

		case GAMEOVER: 
		{
			SetFontSize(50);
			DrawString(
				(SCREEN_W_DEFAULT / 2) - (50 / 2 * 12 / 2),
				SCREEN_H_DEFAULT / 3,
				L"GAME OVER", 0x00ff00);
		}
		break;

	default:
		break;
	}

	
	// -- Process Q --
	for (int i = 0; i < dqSize; i++)
	{
		drawQ[i].process_func();
	}

	SetFontSize(15);
	DrawFormatString(0, 0, GetColor( 255, 255, 255 ), L"%d", GT_GetFPS());
}