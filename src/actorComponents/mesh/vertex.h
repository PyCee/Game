
#ifndef _VERTEX_
#define _VERTEX_

#include "vector.h"
typedef struct _vec3 Normal_t;

typedef struct _Vertex_t{
	
	Normal_t surfaceNormal;
	float Pos [3];
	float ambiantReflectivity;
	float diffuseReflectivity;
	float specularReflectivity;
} Vertex_t;

void genVertex(Vertex_t *);
void freeVertex(Vertex_t *);

#endif /* _VERTEX_ */
