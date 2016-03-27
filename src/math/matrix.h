
#ifndef _MATRIX_
#define _MATRIX_

#include "../actorComponents/physics/vector.h"

typedef struct _mat4{
	float mat[4][4];
} mat4;
mat4 genZeroMat4(void);
mat4 genIdentityMat4(void);
mat4 transposeMat4(mat4);
void printMat4(mat4);
mat4 addMat4(mat4, mat4);
mat4 mat4Product(mat4, mat4);
vec3 multMat4Vec3(mat4, vec3);
mat4 translateMat4(mat4, vec3);

mat4 genTransformationMat4(vec3, vec3);
#endif
