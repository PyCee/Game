
#ifndef COLLISION_CYLINDER
#define COLLISION_CYLINDER

struct vec3;
struct collisionController;

struct collisionController genCollisionCylinder(struct vec3 *, struct vec3 *, float);
unsigned char collisionCylinderCylinder(struct collisionController, struct collisionController);

unsigned char collisionCylinderSphere(struct collisionController, struct collisionController);
unsigned char collisionSphereCylinder(struct collisionController, struct collisionController);
unsigned char collisionCylinderPoint(struct collisionController, struct collisionController);
unsigned char collisionPointCylinder(struct collisionController, struct collisionController);
unsigned char collisionCylinderCapsule(struct collisionController, struct collisionController);
unsigned char collisionCapsuleCylinder(struct collisionController, struct collisionController);
unsigned char collisionCylinderAABox(struct collisionController, struct collisionController);
unsigned char collisionAABoxCylinder(struct collisionController, struct collisionController);
unsigned char collisionCylinderBox(struct collisionController, struct collisionController);
unsigned char collisionBoxCylinder(struct collisionController, struct collisionController);

#endif /* COLLISION_CYLINDER */
