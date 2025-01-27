#include "gamemath.h"

double GM_Magnitude(VECTOR vect)
{
	double sumSquare = (vect.x * vect.x) + (vect.y * vect.y) + (vect.z * vect.z);
	return sqrt(sumSquare);
}

VECTOR GM_Normalize(VECTOR vect) 
{
	double mag = GM_Magnitude(vect);
	if (mag == 0) return vect;
	double invMag = 1.0 / mag;
	VECTOR norm = { vect.x * invMag,
					vect.y * invMag,
					vect.z * invMag };
	return norm;
}

VECTOR GM_Velocity(VECTOR norm, double mag) 
{
	double normMag = GM_Magnitude(norm);
	if (fabs(normMag - 1.0) > 0.0001) 
	{
		norm = GM_Normalize(norm);
	}

	VECTOR vel = { norm.x * mag,
				   norm.y * mag,
				   norm.z * mag };
	return vel;
}