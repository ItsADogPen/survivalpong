#pragma once

#ifndef GAMEMATH_H
#define GAMEMATH_H

#include "DxLib.h"
#include <math.h>

double GM_Magnitude(VECTOR vect);
VECTOR GM_Normalize(VECTOR vect);
VECTOR GM_Velocity(VECTOR norm, double mag);

#endif