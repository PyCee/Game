
#ifndef _QUANTERNIONS_
#define _QUANTERNIONS_

#include "../actorComponents/physics/vector.h"

vec4 PureQuaternion(vec3);
vec4 UnitQuaternion(vec3, F32);
vec4 ConjugateQuaternion(vec4);
vec4 HProduct(vec4, vec4);
vec3 rotateVec3(vec3, vec3, F32);

#endif /* _QUANTERNIONS_ */
