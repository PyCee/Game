#include "collisionData.h"

#include "vector.h"
#include <stdlib.h>
collisionData genCollisionData(void)
{
	collisionData data;
	data.normal = malloc(sizeof(vec3));
	data.validActorPosition = malloc(sizeof(vec3));
	data.remainingVelocity = malloc(sizeof(vec3));
	return data;
}
