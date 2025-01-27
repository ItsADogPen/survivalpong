#pragma once

#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "DxLib.h"

typedef struct GAMEOBJ 
{
	VECTOR pos; // x y
	VECTOR size; //width height
	VECTOR vel; // x, y
	COLOR_F col; // r g b a
};

#endif // !OBJSTRUCT_H
