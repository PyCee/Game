
#include "../dataTypes.h"
#include "quaternions.h"
#include <math.h>
#include "angles.h"
#include <stdio.h>
#include <stdlib.h>

Quaternion_t * PureQuaternion(Vector_t vector)
{
	Quaternion_t * result = malloc(sizeof(Quaternion_t));
	result->val[0] = 0.0;
	result->val[1] = vector.point[0];
	result->val[2] = vector.point[1];
	result->val[3] = vector.point[2];
	return result;
}
Quaternion_t * UnitQuaternion(Vector_t vector, F32 angle)
{
	Quaternion_t * result = malloc(sizeof(Quaternion_t));
	F32 radians = DegreesToRadians(angle / 2.0);
	result->val[0] = cos(radians);
	result->val[1] = sin(radians) * vector.point[0];
	result->val[2] = sin(radians) * vector.point[1];
	result->val[3] = sin(radians) * vector.point[2];
	return result;
}
Quaternion_t * ConjugateQuaternion(Quaternion_t qua)
{
	Quaternion_t * result = malloc(sizeof(Quaternion_t));
	result->val[0] = qua.val[0];
	result->val[1] = -1 * qua.val[1];
	result->val[2] = -1 * qua.val[2];
	result->val[3] = -1 * qua.val[3];
	return result;
}
// returns Hamilton Product of Quaternions
Quaternion_t * HProduct(Quaternion_t quaOne, Quaternion_t quaTwo)
{
	Quaternion_t * result = malloc(sizeof(Quaternion_t));
	result->val[0] = quaOne.val[0] * quaTwo.val[0] - quaOne.val[1] * quaTwo.val[1] + quaOne.val[2] * quaTwo.val[2] + quaOne.val[3] * quaTwo.val[3];
	U8 index = 1;
	while ( index <= 3 ) {
		result->val[index] = quaOne.val[0] * quaTwo.val[index] + quaTwo.val[0] * quaOne.val[index] +
			quaOne.val[ ( ( index + 0 ) % 3 ) + 1] * quaTwo.val[ ( ( index + 1 ) % 3 ) + 1] -
			quaOne.val[ ( ( index + 1 ) % 3 ) + 1] * quaTwo.val[ ( ( index + 0 ) % 3 ) + 1];
		index++;
	}
	return result;
}
void rotateVector(Vector_t *rotate, Vector_t around, F32 angle)
{
	Quaternion_t * quaRotate = PureQuaternion(*rotate);
	Quaternion_t * quaAround = UnitQuaternion(around, angle);
	Quaternion_t * quaConjugate = ConjugateQuaternion(*quaAround);
	Quaternion_t * result = HProduct( *( HProduct( *quaAround, *quaRotate ) ), *quaConjugate );
	if ( result->val[0] != 0.0 ) {
		printf( "ERROR:: result of rotateVector(Vector_t *, Vector_t, F32) not a Pure Quaternion.\n Non-zero valure is %f\n", result->val[0] );
		return;
	}
	rotate->point[0] = result->val[1];
	rotate->point[1] = result->val[2];
	rotate->point[2] = result->val[3];
}
