
#ifndef COLLISION_CAPSULE
#define COLLISION_CAPSULE

struct vec3;
struct collisionController;

#define CAPSULE_P1 _vec3[0]
#define CAPSULE_P2 _vec3[1]
#define CAPSULE_RADIUS _float[0]

struct collisionController genCollisionCapsule(struct vec3 *, struct vec3 *, float);
unsigned char collisionCapsuleCapsule(struct collisionController, struct collisionController)
;
unsigned char collisionCapsuleSphere(struct collisionController, struct collisionController);
unsigned char collisionSphereCapsule(struct collisionController, struct collisionController);

#endif /* COLLISION_CAPSULE */
