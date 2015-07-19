
#ifndef _VERTEX_
#define _VERTEX_

#include "../direction/normal.h"

typedef struct _Vertex_t{
	//Normal_t		SurfaceNormal;
	F32					Pos												[3];
	/*F32					AmbiantReflectivity;
	F32					DiffuseReflectivity;
	F32					SpecularReflectivity;
	*/
} Vertex_t;

void genVertex(Vertex_t *);
void freeVertex(Vertex_t *);

#endif /* _VERTEX_ */
