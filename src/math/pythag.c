
#include "../dataTypes.h"
#include "pythag.h"
#include <math.h>

F32 PythagoreanTheorum
(F32 X, F32 Y, F32 Z)
{
	return sqrt((X * X) + (Y * Y) + (Z * Z));
	// for faster, but less acurate answer
	// return Q_rsqrt(pow(X, 2) + pow(X, 2) + pow(Z, 2));
}
