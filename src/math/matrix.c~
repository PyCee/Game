
#include "../dataTypes.h"
#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

mat4 genZeroMatrix(void)
{
	mat4 result;
	U8 row = 0;
	U8 col = 0;
	while (row < 4) {
		while (col < 4) {
			result[row][col] = 0;
			col++;
		}
		row++;
	}
	return result;
}
mat4 genIdentityMatrix(void)
{
	mat4 result;
	U8 row = 0;
	U8 col = 0;
	while (row < 4) {
		while (col < 4) {
			if (row == col)
				result[row][col] = 1;
			else
				result[row][col] = 0;
			col++;
		}
		row++;
	}
	return result;
}
mat4 transposeMatrix(mat4 mat)
{
	mat4 result;
	U8 row = 0;
	U8 col = 0;
	while (row < 4) {
		while (col < 4) {
			result[row][col] = mat.mat[col][row];
			col++;
		}
		row++;
	}
	return result;
}
void printMatrix(mat4 mat)
{
	U8 row = 0;
	U8 col = 0;
	while (row < 4) {
		printf("[ ");
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
	U8 row = 0;
	U8 col = 0;
	while (row < 4) {
		while (col < 4) {
			result[row][col] = mat1.mat[col][row] + mat2.mat[row][col];
			col++;
		}
		row++;
	}
	return result;
}
mat4 multiplyMatrices(mat4 mat1, mat4 mat2)
{
	mat4 result;
	U8 row = 0;
	U8 col = 0;
	U8 index = 0;
	while (row < 4) {
		col = 0;
		while (col < 4) {
			index = 0;
			while (index < 4) {
				result[row][col] += mat1.mat[row][index] * mat2.mat[index][col];
			}
			col++;
		}
		row++;
	}
	return result;
}
mat4 translateMat4(mat4 mat, vec3 vec)
{
	mat[0][3] += vec[0];
	mat[1][3] += vec[1];
	mat[2][3] += vec[2];
	return mat;
}
