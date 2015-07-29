
#ifndef _QUANTERNIONS_
#define _QUANTERNIONS_

#include "../actorComponents/physics/vector.h"

typedef struct _Quaternion_t{
	F32 val[4];
} Quaternion_t;

Quaternion_t * PureQuaternion(Vector_t);
Quaternion_t * UnitQuaternion(Vector_t, F32);
Quaternion_t * ConjugateQuaternion(Quaternion_t);
Quaternion_t * HProduct(Quaternion_t, Quaternion_t);
void rotateVector(Vector_t *, Vector_t, F32);

#endif /* _QUANTERNIONS_ */
