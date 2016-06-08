#ifndef COLLISION_DETECTION
#define COLLISION_DETECTION

struct collisionData;
struct collisionController;

struct collisionData collisionDetection(void);
unsigned char testCollision(struct collisionController, struct collisionController);

#endif /* COLLISION_DETECTION */
