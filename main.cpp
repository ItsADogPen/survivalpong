#include "main.h"
#include "gamestate.h"
#include "gametime.h"
#include "updatedraw.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	if (DxLib_Init() == -1) return -1;

	const int WIDTH = SCREEN_W_DEFAULT, HEIGHT = SCREEN_H_DEFAULT;
	bool isRun = true;

	SetWindowText(L"Survival Pong");
	SetGraphMode(WIDTH, HEIGHT, 32);
	ChangeWindowMode(TRUE);
	SetWaitVSyncFlag(FALSE);		// No idea.., maybe for deltaTime ? ?
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);

	// == Initialization Q ==
	GT_Init();
	UpdateDrawManagerInit();
	// ----------------------

	while (isRun) 
	{
		ClearDrawScreen();
		// == Double Buffer begin ==
		
		// -- Update and Draw Loop
		UpdateDraw(GAMESTATE_Get());
		// ------------------

		ScreenFlip();
		// == Double Buffer End ==
		WaitTimer(10);
		if (ProcessMessage() == -1) break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		if (!isRun) break;
	}


	DxLib_End();
	return 0;
}