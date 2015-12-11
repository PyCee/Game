
#include "pythag.h"
#include <math.h>

float PythagoreanTheorum
(float X, float Y, float Z)
{
	return sqrt((X * X) + (Y * Y) + (Z * Z));
	// for faster, but less acurate answer
	// return Q_rsqrt(pow(X, 2) + pow(X, 2) + pow(Z, 2));
}
