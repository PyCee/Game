
#ifndef CAPSULE
#define CAPSULE

struct vec3;
struct collisionController;

struct collisionController genCapsule(struct vec3 *, struct vec3 *, float);
unsigned char collisionCapsuleCapsule(struct collisionController, struct collisionController);

#endif /* CAPSULE */
