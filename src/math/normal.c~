
#include "../dataTypes.h"
#include "normal.h"

#include <stdio.h>
#include "gMath.h"
#include "matrix.h"


void genNormal2
(Normal_t *normal)
{
	genMatrix(normal, 1, 3);
	*getMatrixEle(normal, 0, 1) = 1;
}
void genNormal3
(Normal_t *normal)
{
	genMatrix(normal, 1, 4);
	*getMatrixEle(normal, 0, 2) = 1;
}
void freeNormal2
(Normal_t *normal)
{
	freeMatrix(normal);
}
void freeNormal3
(Normal_t *normal)
{
	freeMatrix(normal);
}
void NormalizeNormal2
(Normal_t *normal)
{
	F64 change = PythagoreanTheoremDim2(*getMatrixEle(normal, 0, 0), *getMatrixEle(normal, 0, 1));
	*getMatrixEle(normal, 0, 0) = *getMatrixEle(normal, 0, 0) / change;
	*getMatrixEle(normal, 0, 1) = *getMatrixEle(normal, 0, 1) / change;
}
void NormalizeNormal3
(Normal_t *normal)
{
	F64 change = PythagoreanTheoremDim3(*getMatrixEle(normal, 0, 0), *getMatrixEle(normal, 0, 1), 
		*getMatrixEle(normal, 0, 2));
	*getMatrixEle(normal, 0, 0) = *getMatrixEle(normal, 0, 0) / change;
	*getMatrixEle(normal, 0, 1) = *getMatrixEle(normal, 0, 1) / change;
	*getMatrixEle(normal, 0, 2) = *getMatrixEle(normal, 0, 2) / change;
}
void PrintNormal2
(Normal_t normal)
{
	printMatrix(normal);
}
void PrintNormal3
(Normal_t normal)
{
	printMatrix(normal);
}
