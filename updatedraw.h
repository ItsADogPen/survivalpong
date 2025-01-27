#pragma once

#ifndef UPDATEDRAW_H
#define UPDATEDRAW_H

#include "DxLib.h"
#include "gamestate.h"
#include "qmanager.h"
#include "miscdefs.h"

#define UPDATEQ_MAX 256
#define DRAWQ_MAX 256

void UpdateDrawManagerInit();
void UpdateDraw(GAMESTATE state);

void InitLoop(GAMESTATE state);
void UpdateLoop(GAMESTATE state);
void DrawLoop(GAMESTATE state);

#endif // !UPDATEDRAW
