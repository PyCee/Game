#include "collisionData.h"

#include "vector.h"
#include <stdlib.h>
collisionData genCollisionData(void)
{
	collisionData data;
	data.normal = malloc(sizeof(vec3));
	*data.normal = genVec3(0.0, 0.0, 1.0);
	data.validActorPosition = malloc(sizeof(vec3));
	*data.validActorPosition = genVec3(0.0, 0.0, 0.0);
	data.remainingVelocity = malloc(sizeof(vec3));
	*data.remainingVelocity = genVec3(0.0, 0.0, 0.0);
	data.t = 1;
	return data;
}

void freeCollisionData(collisionData *data)
{
	if(data->normal == 0){
		free(data->normal);
		data->normal = 0;
	}
	if(data->validActorPosition == 0){
		free(data->validActorPosition);
		data->validActorPosition = 0;
	}
	if(data->remainingVelocity == 0){
		free(data->remainingVelocity);
		data->remainingVelocity = 0;
	}
	
}
