
#ifndef _NORMAL_
#define _NORMAL_

#include "../physics/vector.h"
typedef struct _vec3 Normal_t;

vec3 genNormal(void);

Normal_t NormalizeNormal(Normal_t);

void PrintNormal(Normal_t);
#endif
