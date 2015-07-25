
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
	F32 change = PythagoreanTheorum( getVectorX(*normal),  getVectorY(*normal),  getVectorZ(*normal) );
	if (change == 0)
		return;
	setVectorX(normal,  getVectorX(*normal) / change);
	setVectorY(normal,  getVectorY(*normal) / change);
	setVectorZ(normal,  getVectorZ(*normal) / change);
}
void PrintNormal
(Normal_t normal)
{
	PrintVector(normal);
}
