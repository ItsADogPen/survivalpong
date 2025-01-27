#include "gametime.h"

LONGLONG nowTime;
LONGLONG prevTime;
float deltaTime;
int FPS;
int FPSCounter;
LONGLONG FPSCheckTime;

void GT_Init(void)
{
	deltaTime = 0.000001f;
	prevTime = GetNowHiPerformanceCount();
	FPSCheckTime = GetNowHiPerformanceCount();
	FPS = 0;
	FPSCounter = 0;
}

void GT_QueryPerfCounterPrev(void)
{
	prevTime = GetNowHiPerformanceCount();
}

void GT_QueryPerfCounterNow(void)
{
	nowTime = GetNowHiPerformanceCount();
}

void GT_SetPrevToNow(void)
{
	prevTime = nowTime;
}

int GT_GetFPS(void)
{
	return FPS;
}

void GT_UpdateFPS(void) {
	FPSCounter++;
	if ( nowTime - FPSCheckTime > 1000000 ) 
	{
		FPS = FPSCounter;
		FPSCounter = 0;
		FPSCheckTime = nowTime;
	}
}

float GT_DeltaTime(void)
{
	return deltaTime = ( nowTime - prevTime ) / 1000000.0f;
}