
#include "vector.h"

#include "gMath.h"

double getVec2Magnitude
(Vec2_t vec)
{
	return PythagoreanTheoremDim2(vec.X, vec.Y);
}
double getVec3Magnitude
(Vec3_t vec)
{
	return PythagoreanTheoremDim3(vec.X, vec.Y, vec.Z);
}
