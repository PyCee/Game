
#include "vertex.h"
#include "../physics/vector.h"

vertex genVertex(vec3 pos, vec3 norm, vec2 tex)
{
	vertex vert;
	vert.attribute[0] = pos.vec[0];
	vert.attribute[1] = pos.vec[1];
	vert.attribute[2] = pos.vec[2];
	vert.attribute[3] = norm.vec[0];
	vert.attribute[4] = norm.vec[1];
	vert.attribute[5] = norm.vec[2];
	vert.attribute[6] = tex.vec[0];
	vert.attribute[7] = tex.vec[1];
	return vert;
}
