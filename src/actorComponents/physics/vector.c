
#include "vector.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
vec2 genVec2(float X, float Y)
{
	vec2 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	return result;
}
vec3 genVec3(float X, float Y, float Z)
{
	vec3 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	result.vec[2] = Z;
	return result;
}
vec4 genVec4(float X, float Y, float Z, float W)
{
	vec4 result;
	result.vec[0] = X;
	result.vec[1] = Y;
	result.vec[2] = Z;
	result.vec[3] = W;
	return result;
}
vec3 normalizeVec3(vec3 vec)
{
	vec3 result;
	float change = PythagoreanTheorum(getVec3X(vec), getVec3Y(vec), getVec3Z(vec));
	if(change == 0)
		return genVec3(0, 0, 1);
	setVec3X(&result, getVec3X(vec) / change);
	setVec3Y(&result, getVec3Y(vec) / change);
	setVec3Z(&result, getVec3Z(vec) / change);
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
(vec3 vector, float scale)
{
	return genVec3(getVec3X(vector) * scale, getVec3Y(vector) * scale, getVec3Z(vector) * scale);
}
float dotVec3
(vec3 vecOne, vec3 vecTwo)
{
	return getVec3X(vecOne) * getVec3X(vecTwo) + getVec3X(vecOne) * getVec3Z(vecTwo) + getVec3Z(vecOne) * getVec3Z(vecTwo);
}
vec3 crossVec3(vec3 vecOne, vec3 vecTwo)
{
	float X = vecOne.vec[1] * vecTwo.vec[2] - vecOne.vec[2] * vecTwo.vec[1];
	float Y = vecOne.vec[2] * vecTwo.vec[0] - vecOne.vec[0] * vecTwo.vec[2];
	float Z = vecOne.vec[0] * vecTwo.vec[1] - vecOne.vec[1] * vecTwo.vec[0];
	return genVec3(X, Y, Z);
}
void	printVec3	(vec3 vec)
{
	printf("[ %f, %f, %f]\n", getVec3X(vec), getVec3Y(vec), getVec3Z(vec));
}

void				setVec3X						(vec3  * vec, float set)		{		vec->vec[0] = set;			}
void				setVec3Y						(vec3  * vec, float set)		{		vec->vec[1] = set;			}
void				setVec3Z						(vec3  * vec, float set)		{		vec->vec[2] = set;			}
float				getVec3X						(vec3 vec)			{		return vec.vec[0];		}
float				getVec3Y						(vec3 vec)			{		return vec.vec[1];		}
float				getVec3Z						(vec3 vec)			{		return vec.vec[2];		}
