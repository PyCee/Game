
#ifndef _VERTEX_
#define _VERTEX_

#include "../physics/vector.h"

typedef struct _Vertex{
	vec3 pos;
	vec3 normal;
	vec2 texCoords;
	
} Vertex;

Vertex genVertex(vec3, vec3, vec2);

#endif /* _VERTEX_ */
