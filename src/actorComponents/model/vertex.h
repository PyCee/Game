
#ifndef _VERTEX_
#define _VERTEX_

#include "../physics/vector.h"

typedef struct vertex{
	float attribute[3/*position*/ + 3/*normal*/ + 2/*texture coordinates*/];
	
} vertex;

vertex genVertex(vec3, vec3, vec2);

#endif /* _VERTEX_ */
