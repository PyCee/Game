
#ifndef COLLISION_SPHERE
#define COLLISION_SPHERE

struct vec3;
struct collisionController;

struct collisionController genCollisionSphere(struct vec3 *, float);

unsigned char collisionSphereSphere(struct collisionController, struct collisionController);

#endif /* COLLISION_SPHERE */
