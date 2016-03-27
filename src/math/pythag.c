
#include "pythag.h"
#include <math.h>

double PythagoreanTheorum(float X, float Y, float Z)
{
	return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
	// for faster, but less acurate answer
	// return Q_rsqrt(pow(X, 2) + pow(X, 2) + pow(Z, 2));
}
