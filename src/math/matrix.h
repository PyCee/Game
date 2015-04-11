
#ifndef _MATRIX_
#define _MATRIX_

typedef struct _Matrix_t{
	unsigned char height;
	unsigned char width;
	double *ele;
} Matrix_t;

void printMatrix(Matrix_t *);

void genMatrix(Matrix_t **, unsigned char, unsigned char);
void freeMatrix(Matrix_t **);
double *getMatrixEle(Matrix_t *, unsigned char, unsigned char);
void ZeroMatrix(Matrix_t *);
void IdentityMatrix(Matrix_t *);
void TransposeMatrix(Matrix_t **);
unsigned char isMatrixSquare(Matrix_t *);
Matrix_t *AddMatricies(Matrix_t *, Matrix_t *);
Matrix_t *MultiplyMatricies(Matrix_t *, Matrix_t *);
void MultiplyMartixNum(Matrix_t *, double);

#endif
