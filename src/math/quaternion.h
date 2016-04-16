
#ifndef _QUANTERNIONS_
#define _QUANTERNIONS_

#include "../actorComponents/physics/vector.h"
#include "matrix.h"

vec4 PureQuaternion(vec3);
vec4 UnitQuaternion(vec3, float);
vec4 ConjugateQuaternion(vec4);
vec4 HProduct(vec4, vec4);
vec3 rotateVec3(vec3, vec3, float);

vec4 QuatMultiply(vec4, vec4);
mat4 QuaternionToRotationMatrix(vec4);
vec3 applyRotationQuaternion(vec3, vec4);

#endif /* _QUANTERNIONS_ */
