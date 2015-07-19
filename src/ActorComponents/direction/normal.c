
#include "../../dataTypes.h"
#include "normal.h"

#include <stdio.h>
#include "../physics/vector.h"
#include "../../math/pythag.h"

void genNormal
(Normal_t *normal)
{
	genVector(normal);
}
void freeNormal
(Normal_t *normal)
{
}
void NormalizeNormal
(Normal_t *normal)
{
	F32 vectorX = getVectorX(*normal);
	F32 vectorY = getVectorY(*normal);
	F32 vectorZ = getVectorZ(*normal);
	F32 change = PythagoreanTheorum(vectorX, vectorY, vectorZ);
	if (change == 0)
		return;
	setVectorX(normal, vectorX / change);
	setVectorY(normal, vectorY / change);
	setVectorZ(normal, vectorZ / change);
}
void PrintNormal
(Normal_t normal)
{
	PrintVector(normal);
}
