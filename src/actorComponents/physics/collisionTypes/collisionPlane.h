
#ifndef COLLISION_PLANE
#define COLLISION_PLANE

#define PLANE_POSITION _vec3[0]
#define PLANE_NORMAL _vec3[1]
#define PLANE_D _float[0]

struct vec3;
struct collisionController;

float distancePlanePoint(struct collisionController, struct vec3);

struct collisionController genCollisionPlane(struct vec3 *, struct vec3 *);
struct collisionController genCollisionPlaneFromTriangle(struct vec3 *, struct vec3 *, struct vec3 *);

unsigned char collisionPlanePlane(struct collisionController, struct collisionController);
unsigned char collisionPlaneCapsule(struct collisionController, struct collisionController);
unsigned char collisionCapsulePlane(struct collisionController, struct collisionController);
unsigned char collisionPlaneSphere(struct collisionController, struct collisionController);
unsigned char collisionSpherePlane(struct collisionController, struct collisionController);

#endif /* COLLISION_PLANE */
