

#include "../dataTypes.h"
#include "vector.h"

#include <stdlib.h>
#include <stdio.h>

#include "gMath.h"
#include "matrix.h"

void genVec2
(Vec2_t *vec)
{
	genMatrix(vec, 1, 3);
}
void genVec3
(Vec3_t *vec)
{
	genMatrix(vec, 1, 4);
}

void freeVec2
(Vec2_t *vec)
{
	freeMatrix(vec);
}
void freeVec3
(Vec3_t *vec)
{
	printf("asdasdasdasd\n");
	freeMatrix(vec);
}
void PrintVec2
(Vec2_t vec)
{
	printf("[ %f, %f]\n", getVecX(vec), getVecY(vec));
}
void PrintVec3
(Vec3_t vec)
{
	printf("[ %f, %f, %f]\n", getVecX(vec), getVecY(vec), getVecZ(vec));
}

F64		*		getVecXPtr		(Matrix_t *vec)		{		return getMatrixEle(vec, 0, 0);			}
F64		*		getVecYPtr		(Matrix_t *vec)		{		return getMatrixEle(vec, 0, 1);			}
F64		*		getVecZPtr		(Matrix_t *vec)		{		return getMatrixEle(vec, 0, 2);			}
F64				getVecX				(Matrix_t vec)		{		return *getMatrixEle(&vec, 0, 0);		}
F64				getVecY				(Matrix_t vec)		{		return *getMatrixEle(&vec, 0, 1);		}
F64				getVecZ				(Matrix_t vec)		{		return *getMatrixEle(&vec, 0, 2);		}
