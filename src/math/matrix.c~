
#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

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
mat4 multiplyMatrices(mat4 mat1, mat4 mat2)
{
	mat4 result;
	unsigned char row = 0;
	unsigned char col = 0;
	unsigned char index = 0;
	while (row < 4) {
		col = 0;
		while (col < 4) {
			index = 0;
			while (index < 4) {
				result.mat[row][col] += mat1.mat[row][index] * mat2.mat[index][col];
			}
			col++;
		}
		row++;
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
