
#ifndef SPHERE
#define SPHERE

struct vec3;
struct  collisionController;

struct collisionController genSphere(struct vec3 *, float);

unsigned char collisionSphereSphere(struct collisionController, struct collisionController);

#endif /* SPHERE */
