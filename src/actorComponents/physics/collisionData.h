#ifndef COLLISION_DATA
#define COLLISION_DATA

typedef struct collisionData{
	struct vec3 *normal, *validActorPosition, *remainingVelocity;
	float t;
} collisionData;

collisionData genCollisionData(void);
void freeCollisionData(collisionData *);

#endif /* COLLISION_DATA */
