
#include "vector.h"

#include "../../math/pythag.h"
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
	double change = PythagoreanTheorum(vec.vec[0], vec.vec[1], vec.vec[2]);
	if(change == 0){
		printf("Pythagorean Theorem equated out to 0 during normalization.\n");
		return genVec3(0, 0, 1);
	}
	return scaleVec3(vec, 1 / change);
}
vec3 addVec3(vec3 vecOne, vec3 vecTwo)
{
	vec3 result;
	result.vec[0] = vecOne.vec[0] + vecTwo.vec[0];
	result.vec[1] = vecOne.vec[1] + vecTwo.vec[1];
	result.vec[2] = vecOne.vec[2] + vecTwo.vec[2];
	return result;
}
vec3 subtractVec3(vec3 vecOne, vec3 vecTwo)
{
	return addVec3(vecOne, scaleVec3(vecTwo, -1));
}
vec3 scaleVec3(vec3 vector, float scale)
{
	return genVec3(vector.vec[0] * scale, vector.vec[1] * scale, vector.vec[2] * scale);
}
float dotVec3(vec3 vecOne, vec3 vecTwo)
{
	return vecOne.vec[0] * vecTwo.vec[0] + vecOne.vec[1] * vecTwo.vec[1] + vecOne.vec[2] * vecTwo.vec[2];
}
vec3 crossProduct(vec3 vecOne, vec3 vecTwo)
{
	float X = vecOne.vec[1] * vecTwo.vec[2] - vecOne.vec[2] * vecTwo.vec[1];
	float Y = vecOne.vec[2] * vecTwo.vec[0] - vecOne.vec[0] * vecTwo.vec[2];
	float Z = vecOne.vec[0] * vecTwo.vec[1] - vecOne.vec[1] * vecTwo.vec[0];
	return genVec3(X, Y, Z);
}
void printVec3(vec3 vec)
{
	printf("[ %f, %f, %f]\n", vec.vec[0], vec.vec[1], vec.vec[2]);
}
void printVec4(vec4 vec)
{
	printf("[ %f, %f, %f, %f]\n", vec.vec[0], vec.vec[1], vec.vec[2], vec.vec[3]);
}
