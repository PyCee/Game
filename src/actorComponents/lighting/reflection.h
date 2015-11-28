
#ifndef _REFLECTION_
#define _REFLECTION_

typedef struct _Color_t Color_t;
#include "../physics/vertex.h"
#include "../../actorSelection.h"
void PhongReflection(Color_t *, Vertex_t, U8 light[MAX_ACTOR_COUNT][MAX_LIGHT_COUNT], F32);

#endif /* _REFLECTION_ */
