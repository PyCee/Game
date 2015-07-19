
#include "../dataTypes.h"
#include "angles.h"

F64 DegreesToRadians(F64 degrees)
{
	return degrees * PI / 180;
}
F64 RadiansToDegrees(F64 radians)
{
	return radians * 180 / PI;
}
