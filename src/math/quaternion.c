
#include "../dataTypes.h"
#include "quaternion.h"
#include <math.h>
#include "angles.h"
#include <stdio.h>
#include <stdlib.h>

vec4 PureQuaternion(vec3 vector)
{
	vec4 result;
	result.vec[0] = 0.0;
	result.vec[1] = vector.vec[0];
	result.vec[2] = vector.vec[1];
	result.vec[3] = vector.vec[2];
	return genVec4(0.0, vector.vec[0], vector.vec[1], vector.vec[2]);
}
vec4 UnitQuaternion(vec3 vector, F32 angle)
{
	vec4 result;
	F32 radians = DegreesToRadians(angle / 2.0);
	result.vec[0] = cos(radians);
	result.vec[1] = sin(radians) * vector.vec[0];
	result.vec[2] = sin(radians) * vector.vec[1];
	result.vec[3] = sin(radians) * vector.vec[2];
	return result;
}
vec4 ConjugateQuaternion(vec4 qua)
{
	vec4 result;
	result.vec[0] = qua.vec[0];
	result.vec[1] = -1 * qua.vec[1];
	result.vec[2] = -1 * qua.vec[2];
	result.vec[3] = -1 * qua.vec[3];
	return result;
}
// returns Hamilton Product of Quaternions
vec4 HProduct(vec4 quaOne, vec4 quaTwo)
{
	vec4 result;
	result.vec[0] = quaOne.vec[0] * quaTwo.vec[0] - quaOne.vec[1] * quaTwo.vec[1] + quaOne.vec[2] * quaTwo.vec[2] + quaOne.vec[3] * quaTwo.vec[3];
	U8 index = 1;
	while ( index <= 3 ) {
		result.vec[index] = quaOne.vec[0] * quaTwo.vec[index] + quaTwo.vec[0] * quaOne.vec[index] +
			quaOne.vec[ ( ( index + 0 ) % 3 ) + 1] * quaTwo.vec[ ( ( index + 1 ) % 3 ) + 1] -
			quaOne.vec[ ( ( index + 1 ) % 3 ) + 1] * quaTwo.vec[ ( ( index + 0 ) % 3 ) + 1];
		index++;
	}
	return result;
}
vec3 rotateVec3(vec3 rotate, vec3 around, F32 angle)
{
	vec4 quaRotate = PureQuaternion(rotate);
	vec4 quaAround = UnitQuaternion(around, angle);
	vec4 quaConjugate = ConjugateQuaternion(quaAround);
	vec4 result = HProduct( ( HProduct( quaAround, quaRotate ) ), quaConjugate );
	
	return genVec3(result.vec[1], result.vec[2], result.vec[3]);
}
