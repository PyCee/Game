
#include "../../dataTypes.h"
#include "normal.h"

#include <stdio.h>
#include "../physics/vector.h"
#include "../../math/pythag.h"

Normal_t genNormal(void)
{
	return genVec3(0, 0, 1);
}
void NormalizeNormal
(Normal_t *normal)
{
	F32 change = PythagoreanTheorum( getVec3X(*normal),  getVec3Y(*normal),  getVec3Z(*normal) );
	if (change == 0)
		return;
	setVec3X(normal,  getVec3X(*normal) / change);
	setVec3Y(normal,  getVec3Y(*normal) / change);
	setVec3Z(normal,  getVec3Z(*normal) / change);
}
void PrintNormal
(Normal_t normal)
{
	PrintVec3(normal);
}
