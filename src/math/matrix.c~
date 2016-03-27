
#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>
#include "quaternion.h"
#include "../actorComponents/physics/vector.h"
#include "../actorComponents/directionComponent.h"
#include <math.h>

mat4 genZeroMat4(void)
{
	mat4 result;
	unsigned char row = 0;
	unsigned char col = 0;
	while (row < 4) {
		col = 0;
		while (col < 4) {
			result.mat[row][col] = 0;
			col++;
		}
		row++;
	}
	return result;
}
mat4 genIdentityMat4(void)
{
	mat4 result;
	unsigned char row = 0;
	unsigned char col = 0;
	while (row < 4) {
		col = 0;
		while (col < 4) {
			if (row == col)
				result.mat[row][col] = 1;
			else
				result.mat[row][col] = 0;
			col++;
		}
		row++;
	}
	return result;
}
mat4 transposeMat4(mat4 mat)
{
	mat4 result;
	unsigned char row = 0;
	unsigned char col = 0;
	while (row < 4) {
		col = 0;
		while (col < 4) {
			result.mat[row][col] = mat.mat[col][row];
			col++;
		}
		row++;
	}
	return result;
}
void printMat4(mat4 mat)
{
	unsigned char row = 0;
	unsigned char col = 0;
	printf("Printing mat4:\n");
	while (row < 4) {
		printf("[ ");
		col = 0;
		while (col < 4) {
			printf("%f, ", mat.mat[row][col]);
			col++;
		}
		printf("]\n");
		row++;
	}
}
mat4 addMatrices(mat4 mat1, mat4 mat2)
{
	mat4 result;
	unsigned char row = 0;
	unsigned char col = 0;
	while (row < 4) {
		col = 0;
		while (col < 4) {
			result.mat[row][col] = mat1.mat[col][row] + mat2.mat[row][col];
			col++;
		}
		row++;
	}
	return result;
}
mat4 mat4Product(mat4 mat1, mat4 mat2)
{
	mat4 result;
	unsigned char row = 0;
	for(;row < 4; row++){
		unsigned char col = 0;
		for(;col < 4; col++){
			unsigned char index = 0;
			for(;index < 4; index++){
				result.mat[row][col] += mat1.mat[row][index] * mat2.mat[index][col];
			}
		}
	}
	return result;
}
vec3 multMat4Vec3(mat4 mat, vec3 vec)
{
	vec3 result;
	char index;
	vec4 vec2 = genVec4(vec.vec[0], vec.vec[1], vec.vec[2], 1.0);
	for(index = 0; index < 4; index++){
		char index2;
		for(index2 = 0; index2 < 4; index2++){
			result.vec[index] += mat.mat[index][index2] * vec2.vec[index2];
		}
	}
	return result;
}
mat4 translateMat4(mat4 mat, vec3 vec)
{
	mat.mat[0][3] += vec.vec[0];
	mat.mat[1][3] += vec.vec[1];
	mat.mat[2][3] += vec.vec[2];
	return mat;
}

mat4 genTransformationMat4(vec3 forward, vec3 position)
{
	float angle = (float) (acos(dotVec3(k, forward)));
	angle *= 180 / M_PI;
	vec3 around = crossProduct(forward, k);
	if( forward.vec[2] == 1.0)
		around = k;
	around = normalizeVec3(around);
	
	mat4 Translate = genIdentityMat4();
	Translate = translateMat4(Translate, scaleVec3(position, -2));
	mat4 Rotate = QuaternionToRotationMatrix(UnitQuaternion(around, angle));
	
	return mat4Product(Rotate, Translate);
}
