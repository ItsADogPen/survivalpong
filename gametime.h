#pragma once

#ifndef GAMETIME_H
#define GAMETIME_H

#include <Windows.h>
#include <stdbool.h>
#include "DxLib.h"

void GT_Init();

void GT_QueryPerfCounterPrev(void);
void GT_QueryPerfCounterNow(void);
void GT_SetPrevToNow(void);
float GT_DeltaTime(void);
int GT_GetFPS(void);
void GT_UpdateFPS(void);


#endif