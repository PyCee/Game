
#include "../dataTypes.h"
#include "gMath.h"

#include "matrix.h"
#include <math.h>

// TODO: free mamory of matricies
Matrix_t *Transform
(Matrix_t *matrix, F64 x, F64 y, F64 z)
{
	Matrix_t *transform;
	genMatrix(&transform, 4, 4);
	*getMatrixEle(transform, 3, 0) = x;
	*getMatrixEle(transform, 3, 1) = y;
	*getMatrixEle(transform, 3, 2) = z;
	*getMatrixEle(transform, 3, 3) = 1;
	return MultiplyMatricies(matrix, transform);
}

Matrix_t *Pitch
(Matrix_t *matrix, F64 angle)
{
	angle = -1 * angle;
	Matrix_t *pitch;
	genMatrix(&pitch, 4, 4);
	IdentityMatrix(pitch);
	/**getMatrixEle(pitch, 1, 1) = cos(angle);
	*getMatrixEle(pitch, 1, 2) = -1 * sin(angle);
	*getMatrixEle(pitch, 2, 2) = cos(angle);
	*getMatrixEle(pitch, 2, 1) = sin(angle);*/
	*getMatrixEle(pitch, 1, 1) = cos(angle);
	*getMatrixEle(pitch, 1, 2) = sin(angle);
	*getMatrixEle(pitch, 2, 2) = cos(angle);
	*getMatrixEle(pitch, 2, 1) = -1 * sin(angle);
	return MultiplyMatricies(matrix, pitch);
}
Matrix_t *Yaw
(Matrix_t *matrix, F64 angle)
{
	angle = -1 * angle;
	Matrix_t *yaw;
	genMatrix(&yaw, 4, 4);
	IdentityMatrix(yaw);
	/**getMatrixEle(yaw, 0, 0) = cos(angle);
	*getMatrixEle(yaw, 0, 2) = -1 * sin(angle);
	*getMatrixEle(yaw, 2, 2) = cos(angle);
	*getMatrixEle(yaw, 2, 0) = sin(angle);*/
	*getMatrixEle(yaw, 0, 0) = cos(angle);
	*getMatrixEle(yaw, 0, 2) = sin(angle);
	*getMatrixEle(yaw, 2, 2) = cos(angle);
	*getMatrixEle(yaw, 2, 0) = -1 * sin(angle);
	return MultiplyMatricies(matrix, yaw);
}
Matrix_t *Roll
(Matrix_t *matrix, F64 angle)
{
	angle = -1 * angle;
	Matrix_t *rotate;
	genMatrix(&rotate, 4, 4);
	IdentityMatrix(rotate);
	/**getMatrixEle(rotate, 0, 0) = cos(angle);
	*getMatrixEle(rotate, 0, 1) = -1 * sin(angle);
	*getMatrixEle(rotate, 1, 1) = cos(angle);
	*getMatrixEle(rotate, 1, 0) = sin(angle);*/
	*getMatrixEle(rotate, 0, 0) = cos(angle);
	*getMatrixEle(rotate, 0, 1) = sin(angle);
	*getMatrixEle(rotate, 1, 1) = cos(angle);
	*getMatrixEle(rotate, 1, 0) = -1 * sin(angle);
	return MultiplyMatricies(matrix, rotate);
}
