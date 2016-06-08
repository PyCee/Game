
#ifndef COLLISION_SPHERE
#define COLLISION_SPHERE

struct vec3;
struct collisionController;

#define SPHERE_P1 _vec3[0]
#define SPHERE_RADIUS _float[0]

struct collisionController genCollisionSphere(struct vec3 *, float);
unsigned char collisionSphereSphere(struct collisionController, struct collisionController);

#endif /* COLLISION_SPHERE */
