#ifndef COLLISION_AABOX
#define COLLISION_AABOX

struct vec3;
struct collisionController;

struct collisionController genCollisionAABox(struct vec3 *, float, float, float);

unsigned char collisionAABoxAABox(struct collisionController, struct collisionController);
unsigned char collisionAABoxSphere(struct collisionController, struct collisionController);
unsigned char collisionSphereAABox(struct collisionController, struct collisionController);
unsigned char collisionAABoxCapsule(struct collisionController, struct collisionController);
unsigned char collisionCapsuleAABox(struct collisionController, struct collisionController);

#endif /* COLLISION_AABOX */
