

#include "../../dataTypes.h"
#include "vector.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

vec3 genVec3(F32 X, F32 Y, F32 Z)
{
	vec3 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	result.vec[2] = Z;
	return result;
}
vec4 genVec4(F32 X, F32 Y, F32 Z, F32 W)
{
	vec4 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	result.vec[2] = Z;
	result.vec[3] = W;
	return result;
}
vec3 addVec3
(vec3 vecOne, vec3 vecTwo)
{
	vec3 result;
	result.vec[0] = getVec3X(vecOne) + getVec3X(vecTwo);
	result.vec[1] = getVec3Y(vecOne) + getVec3Y(vecTwo);
	result.vec[2] = getVec3Z(vecOne) + getVec3Z(vecTwo);
	return result;
}
vec3 subtractVec3
(vec3 vecOne, vec3 vecTwo)
{
	return addVec3(vecOne, scaleVec3(vecTwo, -1));
}
vec3 scaleVec3
(vec3 vector, F32 scale)
{
	return genVec3(getVec3X(vector) * scale, getVec3Y(vector) * scale, getVec3Z(vector) * scale);
}
F32 dot
(vec3 vecOne, vec3 vecTwo)
{
	return getVec3X(vecOne) * getVec3X(vecTwo) + getVec3X(vecOne) * getVec3Z(vecTwo) + getVec3Z(vecOne) * getVec3Z(vecTwo);
}
vec3 cross(vec3 vecOne, vec3 vecTwo)
{
	F32 X = vecOne.vec[1] * vecTwo.vec[2] - vecOne.vec[2] * vecTwo.vec[1];
	F32 Y = vecOne.vec[2] * vecTwo.vec[0] - vecOne.vec[0] * vecTwo.vec[2];
	F32 Z = vecOne.vec[0] * vecTwo.vec[1] - vecOne.vec[1] * vecTwo.vec[0];
	return genVec3(X, Y, Z);
}
void				PrintVec3				(vec3 vec)
{
	printf("[ %f, %f, %f]\n", getVec3X(vec), getVec3Y(vec), getVec3Z(vec));
}

void				setVec3X						(vec3  * vec, F32 set)		{		vec->vec[0] = set;			}
void				setVec3Y						(vec3  * vec, F32 set)		{		vec->vec[1] = set;			}
void				setVec3Z						(vec3  * vec, F32 set)		{		vec->vec[2] = set;			}
F32				getVec3X						(vec3 vec)			{		return vec.vec[0];		}
F32				getVec3Y						(vec3 vec)			{		return vec.vec[1];		}
F32				getVec3Z						(vec3 vec)			{		return vec.vec[2];		}
