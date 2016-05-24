#ifndef COLLISION_BOX
#define COLLISION_BOX

struct vec3;
struct collisionController;

struct collisionController genCollisionOBox(struct vec3 *, float);

unsigned char collisionOBoxOBox(struct collisionController, struct collisionController);

#endif /* COLLISION_BOX */
