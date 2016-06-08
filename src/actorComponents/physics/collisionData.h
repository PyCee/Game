#ifndef COLLISION_DATA
#define COLLISION_DATA

typedef struct collisionData{
	struct vec3 *normal, *validActorPosition, *remainingVelocity;
} collisionData;

collisionData genCollisionData(void);

#endif /* COLLISION_DATA */
