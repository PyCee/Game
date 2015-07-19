
#ifndef _MATRIX_
#define _MATRIX_

typedef struct _Matrix_t{
	F64 **ele;
	U8 height;
	U8 width;
} Matrix_t;

void						printMatrix					(Matrix_t);
F64	 				*		getMatrixEle				(Matrix_t *, U8, U8);
void						genMatrix						(Matrix_t *, U8, U8);
void						freeMatrix					(Matrix_t *);
void						copyMatrix					(Matrix_t *, Matrix_t *);
void						ZeroMatrix					(Matrix_t *);
void						IdentityMatrix			(Matrix_t *);
void						TransposeMatrix			(Matrix_t *);
U8							isMatrixSquare			(Matrix_t );
Matrix_t		*		AddMatricies				(Matrix_t, Matrix_t);
Matrix_t		*		MultiplyMatricies		(Matrix_t, Matrix_t);
Matrix_t		*		MultiplyMartixNum		(Matrix_t, F32);
#endif
