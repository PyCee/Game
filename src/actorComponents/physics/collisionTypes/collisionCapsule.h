
#ifndef COLLISION_CAPSULE
#define COLLISION_CAPSULE

struct vec3;
struct collisionController;

struct collisionController genCollisionCapsule(struct vec3 *, struct vec3 *, float);
unsigned char collisionCapsuleCapsule(struct collisionController, struct collisionController)
;
unsigned char collisionCapsuleSphere(struct collisionController, struct collisionController);
unsigned char collisionSphereCapsule(struct collisionController, struct collisionController);

#endif /* COLLISION_CAPSULE */
