#ifndef COLLISION_POINT
#define COLLISION_POINT

struct vec3;
struct collisionController;

struct collisionController genCollisionPoint(struct vec3 *);//TODO: test point collision functions

unsigned char collisionPointPoint(struct collisionController, struct collisionController);
unsigned char collisionPointSphere(struct collisionController, struct collisionController);
unsigned char collisionSpherePoint(struct collisionController, struct collisionController);
unsigned char collisionPointAABox(struct collisionController, struct collisionController);
unsigned char collisionAABoxPoint(struct collisionController, struct collisionController);
unsigned char collisionPointCapsule(struct collisionController, struct collisionController);
unsigned char collisionCapsulePoint(struct collisionController, struct collisionController);

#endif /* COLLISION_POINT */
