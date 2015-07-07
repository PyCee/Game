
#include "../dataTypes.h"
#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

void printMatrix
(Matrix_t matrix)
{
	U8 indexHeight = 0;
	U8 indexWidth;
	while (indexHeight < matrix.height)
	{
		indexWidth = 0;
		printf("[ ");
		while(indexWidth < matrix.width)
		{
			printf("%f, ", *getMatrixEle(&matrix, indexHeight, indexWidth));
			indexWidth++;
		}
		printf("]\n");
		indexHeight++;
	}
}
double *getMatrixEle(Matrix_t *matrix, U8 height, U8 width)
{
	if (height < matrix->height && width < matrix->width)
		return &(matrix->ele[((height) * matrix->width) + width]);
	printf(" ::: Accessing Matrix[%d, %d]. (remember, indexing starts at zero)\n",
			 height, width);
	printf(" ::: ::: Matrix Height: %d\n ::: ::: Matrix Width: %d\n", matrix->height, matrix->width);
	return 0;
}
void genMatrix
(Matrix_t *matrix, U8 height, U8 width)
{
	matrix->height = height;
	matrix->width = width;
	matrix->ele = malloc(sizeof(F64) * height * width);
	ZeroMatrix(matrix);
}
void freeMatrix
(Matrix_t *matrix)
{
	static U8 freedMat = 0;
	if (matrix != NULL)
	{
 		free(matrix);
		matrix = NULL;
	}
}
void copyMatrix
(Matrix_t *recieve, Matrix_t *send)
{
	free(recieve->ele);
	genMatrix(recieve, send->height, send->width);
	U8 indexHeight = 0;
	U8 indexWidth;
	while (indexHeight < send->height)
	{
		indexWidth = 0;
		while (indexWidth < send->width)
		{
			*getMatrixEle(recieve, indexHeight, indexWidth) = *getMatrixEle(send, indexHeight, indexWidth);
			indexWidth++;
		}
		indexHeight++;
	}
}
void ZeroMatrix
(Matrix_t *matrix)
{
	U8 height = matrix->height;
	U8 width = matrix->width;
	U8 indexHeight = 0;
	U8 indexWidth;
	while (indexHeight < height)
	{
		indexWidth = 0;
		while (indexWidth < width)
		{
			*getMatrixEle(matrix, indexHeight, indexWidth) = 0;
			indexWidth++;
		}
		indexHeight++;
	}
}
void IdentityMatrix
(Matrix_t *matrix)
{
	if (isMatrixSquare(*matrix))
	{
		U8 height = matrix->height;
		U8 width = matrix->width;
		U8 indexHeight = 0;
		while (indexHeight < height)
		{
			U8 indexWidth = 0;
			while (indexWidth < width)
			{
				if (indexHeight == indexWidth)
					*getMatrixEle(matrix, indexHeight, indexWidth) = 1;
				else
					*getMatrixEle(matrix, indexHeight, indexWidth) = 0;
				indexWidth++;
			}
			indexHeight++;
		}
	}
}
void TransposeMatrix
(Matrix_t *matrix)
{
	U8 height = matrix->height;
	U8 width = matrix->width;
	Matrix_t *answer;
	genMatrix(answer, width, height);
	U8 indexHeight = 0;
	U8 indexWidth;
	while (indexHeight < width)
	{
		indexWidth = 0;
		while (indexWidth < height)
		{
			*getMatrixEle(answer, indexHeight, indexWidth) = *getMatrixEle(matrix, indexWidth, indexHeight);
			indexWidth++;
		}
		indexHeight++;
	}
	copyMatrix(matrix, answer);
}
U8 isMatrixSquare
(Matrix_t matrix)
{
	if (matrix.height == matrix.width)
		return 1;
	return 0;
}
Matrix_t *AddMatricies
(Matrix_t matrixOne, Matrix_t matrixTwo)
{
	U8 height = matrixOne.height;
	U8 width = matrixOne.width;
	Matrix_t *answer;
	answer = malloc(sizeof(Matrix_t));
	genMatrix(answer, height, width);
	if (height == matrixTwo.height && width == matrixTwo.width)
	{
		U8 indexHeight = 0;
		U8 indexWidth;
		while (indexHeight < height)
		{
			indexWidth = 0;
			while (indexWidth < width)
			{
				*getMatrixEle(answer, indexHeight, indexWidth) =
						*getMatrixEle(&matrixOne, indexHeight, indexWidth) +
						*getMatrixEle(&matrixTwo, indexHeight, indexWidth);
				indexWidth++;
			}
			indexHeight++;
		}
	} else
		ZeroMatrix(answer);
	return answer;
}
Matrix_t *MultiplyMatricies
(Matrix_t matrixOne, Matrix_t matrixTwo)
{	
	// dimensions of answer
	U8 height = matrixOne.height;
	U8 width = matrixTwo.width;
	Matrix_t *answer;
	answer = malloc(sizeof(Matrix_t));
	genMatrix(answer, height, width);
	if (matrixOne.width == matrixTwo.height)
	{
		U8 indexHeight = 0;
		U8 indexWidth;
		while (indexHeight < height)
		{
			indexWidth = 0;
			while (indexWidth < width)
			{
				F64 *activeElement = getMatrixEle(answer, indexHeight, indexWidth);
				U8 index = 0;
				while (index < matrixOne.width)
				{
					*activeElement +=
							*getMatrixEle(&matrixOne, indexHeight, index) *
							*getMatrixEle(&matrixTwo, index, indexWidth);
					index++;
				}
				indexWidth++;
			}
			indexHeight++;
		}
	} else
		ZeroMatrix(answer);
	return answer;
}
Matrix_t *MultiplyMartixNum
(Matrix_t matrix, F64 number)
{
	U8 height = matrix.height;
	U8 width = matrix.width;
	U8 indexHeight = 0;
	U8 indexWidth;
	Matrix_t *answer;
	answer = malloc(sizeof(Matrix_t));
	genMatrix(answer, height, width);
	while (indexHeight < height)
	{
		indexWidth = 0;
		while (indexWidth < width)
		{
			*getMatrixEle(answer, indexHeight, indexWidth) = *getMatrixEle(&matrix, indexHeight, indexWidth) * number;
			indexWidth++;
		}
		indexHeight++;
	}
	return answer;
}
