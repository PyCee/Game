

#include "../../dataTypes.h"
#include "vector.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void genVector
(Vector_t *vec)
{
	setVectorX(vec, 0);
	setVectorY(vec, 0);
	setVectorZ(vec, 0);
}
void freeVector
(Vector_t *vec)
{
}
void copyVector
(Vector_t *recieve, Vector_t send)
{
	setVectorX(recieve, getVectorX(send));
	setVectorY(recieve, getVectorY(send));
	setVectorZ(recieve, getVectorZ(send));
}
Vector_t * addVectors
(Vector_t vecOne, Vector_t vecTwo)
{
	Vector_t * answer = malloc(sizeof(Vector_t));
	setVectorX(answer, getVectorX(vecOne) + getVectorX(vecTwo));
	setVectorY(answer, getVectorY(vecOne) + getVectorY(vecTwo));
	setVectorZ(answer, getVectorZ(vecOne) + getVectorZ(vecTwo));
	return answer;
}
Vector_t * subtractVectors
(Vector_t vecOne, Vector_t vecTwo)
{
	return addVectors(vecOne, *scaleVector(vecTwo, -1));
}
Vector_t * scaleVector
(Vector_t vector, F32 scale)
{
	Vector_t * answer = malloc(sizeof(Vector_t));
	setVectorX(answer, getVectorX(vector) * scale);
	setVectorY(answer, getVectorY(vector) * scale);
	setVectorZ(answer, getVectorZ(vector) * scale);
	return answer;
}
F32 DotProduct
(Vector_t vecOne, Vector_t vecTwo)
{
	return getVectorX(vecOne) * getVectorX(vecTwo) + getVectorX(vecOne) * getVectorZ(vecTwo) + getVectorZ(vecOne) * getVectorZ(vecTwo);
}
F32 CrossProduct(Vector_t, Vector_t);

Vector_t * TranslateVector		(Vector_t vecOne, Vector_t vecTwo)
{
	return addVectors(vecOne, vecTwo);
}
// rotate around X-axis
Vector_t * PitchVector				(Vector_t vec, F32 rad)
{
	rad = -1 * rad;
	Vector_t * pitch = malloc(sizeof(Vector_t));
	genVector(pitch);
	setVectorY(pitch, getVectorY(vec) * cos(rad) - getVectorZ(vec) * sin(rad));
	setVectorZ(pitch, getVectorZ(vec) * cos(rad) + getVectorY(vec) * sin(rad));
	return pitch;
}
// rotate around Y-axis
Vector_t	* YawVector					(Vector_t vec, F32 rad)
{
	rad = -1 * rad;
	Vector_t * yaw = malloc(sizeof(Vector_t));
	genVector(yaw);
	setVectorX(yaw, getVectorX(vec) * cos(rad) - getVectorZ(vec) * sin(rad));
	setVectorZ(yaw, getVectorZ(vec) * cos(rad) + getVectorX(vec) * sin(rad));
	return yaw;
}
// rotate around Z-axis
Vector_t	*	RollVector				(Vector_t vec, F32 rad)
{
	rad = -1 * rad;
	Vector_t * roll = malloc(sizeof(Vector_t));
	genVector(roll);
	setVectorX(roll, getVectorX(vec) * cos(rad) - getVectorY(vec) * sin(rad));
	setVectorY(roll, getVectorY(vec) * cos(rad) + getVectorX(vec) * sin(rad));
	return roll;
}
void				PrintVector				(Vector_t vec)
{
	printf("[ %f, %f, %f]\n", getVectorX(vec), getVectorY(vec), getVectorZ(vec));
}

void				setVectorX						(Vector_t  * vec, F32 set)		{		vec->point[0] = set;			}
void				setVectorY						(Vector_t  * vec, F32 set)		{		vec->point[1] = set;			}
void				setVectorZ						(Vector_t  * vec, F32 set)		{		vec->point[2] = set;			}
F32					getVectorX						(Vector_t vec)								{		return vec.point[0];		}
F32					getVectorY						(Vector_t vec)								{		return vec.point[1];		}
F32					getVectorZ						(Vector_t vec)								{		return vec.point[2];		}
