
#include "../../dataTypes.h"
#include "normal.h"

#include <stdio.h>
#include "../physics/vector.h"
#include "../../math/pythag.h"

Normal_t genNormal(void)
{
	return genVec3(0, 0, 1);
}
Normal_t NormalizeNormal
(Normal_t normal)
{
	Normal_t normalized;
	F32 change = PythagoreanTheorum( normal.vec[0],  normal.vec[1],  normal.vec[2] );
	if (change == 0){
		return normal;
	}
	normalized.vec[0] = normal.vec[0]/change;
	normalized.vec[1] = normal.vec[1]/change;
	normalized.vec[2] = normal.vec[2]/change;
	return normalized;
}
void PrintNormal
(Normal_t normal)
{
	printVec3(normal);
}
