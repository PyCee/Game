
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
vec4 UnitQuaternion(vec3 vector, float angle)
{
	vec4 result;
	float radians = DegreesToRadians(angle / 2.0);
	float sinAngle = sin(radians);
	result.vec[0] = cos(radians);
	result.vec[1] = sinAngle * vector.vec[0];
	result.vec[2] = sinAngle * vector.vec[1];
	result.vec[3] = sinAngle * vector.vec[2];
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
	unsigned char index = 1;
	while ( index <= 3 ) {
		result.vec[index] = quaOne.vec[0] * quaTwo.vec[index] + quaTwo.vec[0] * quaOne.vec[index] +
			quaOne.vec[ ( ( index + 0 ) % 3 ) + 1] * quaTwo.vec[ ( ( index + 1 ) % 3 ) + 1] -
			quaOne.vec[ ( ( index + 1 ) % 3 ) + 1] * quaTwo.vec[ ( ( index + 0 ) % 3 ) + 1];
		index++;
	}
	return result;
}
vec3 rotateVec3(vec3 rotate, vec3 around, float angle)
{
	vec4 quaRotate = PureQuaternion(rotate);
	vec4 quaAround = UnitQuaternion(around, angle);
	vec4 quaConjugate = ConjugateQuaternion(quaAround);
	vec4 result = HProduct( ( HProduct( quaAround, quaRotate ) ), quaConjugate );
	
	return genVec3(result.vec[1], result.vec[2], result.vec[3]);
}
vec4 QuatMultiply(vec4 qua1, vec4 qua2)
{
	vec4 result;
	result.vec[0] = qua1.vec[0]*qua2.vec[0] - qua1.vec[1]*qua2.vec[1] - qua1.vec[2]*qua2.vec[2] - qua1.vec[3]*qua2.vec[3];
	result.vec[1] = qua1.vec[0]*qua2.vec[1] + qua1.vec[1]*qua2.vec[0] + qua1.vec[2]*qua2.vec[3] - qua1.vec[3]*qua2.vec[2];
	result.vec[2] = qua1.vec[0]*qua2.vec[2] + qua1.vec[2]*qua2.vec[0] + qua1.vec[1]*qua2.vec[3] - qua1.vec[3]*qua2.vec[1];
	result.vec[3] = qua1.vec[0]*qua2.vec[3] + qua1.vec[3]*qua2.vec[0] + qua1.vec[1]*qua2.vec[2] - qua1.vec[2]*qua2.vec[1];
	return result;
}
mat4 QuaternionToRotationMatrix(vec4 qua)
{
	mat4 rotation;
	float w = qua.vec[0];
	float x = qua.vec[1];
	float y = qua.vec[2];
	float z = qua.vec[3];
	
	rotation.mat[0][0] = 1 - 2 * y * y - 2 * z * z;
	rotation.mat[0][1] = 2 * x * y - 2 * z * w;
	rotation.mat[0][2] = 2 * x * z + 2 * y * w;
	rotation.mat[0][3] = 0;
	rotation.mat[1][0] = 2 * x * y + 2 * z * w;
	rotation.mat[1][1] = 1 - 2 * x * x - 2 * z * z;
	rotation.mat[1][2] = 2 * y * z - 2 * x * w;
	rotation.mat[1][3] = 0;
	rotation.mat[2][0] = 2 * x * z - 2 * y * w;
	rotation.mat[2][1] = 2 * y * z + 2 * x * w;
	rotation.mat[2][2] = 1 - 2 * x * x - 2 * y * y;
	rotation.mat[2][3] = 0;
	rotation.mat[3][0] = 0;
	rotation.mat[3][1] = 0;
	rotation.mat[3][2] = 0;
	rotation.mat[3][3] = 1;
	
	return rotation;
}
