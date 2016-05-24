
#ifndef COLLISION_CONTROLLER
#define COLLISION_CONTROLLER

#define COLLISION_TYPE_SPHERE 0
#define COLLISION_TYPE_CAPSULE 1
#define COLLISION_TYPE_CYLINDER 2
#define COLLISION_TYPE_OBOX 3
#define COLLISION_TYPE_AABOX 4
#define COLLISION_TYPE_POINT 5

#define COLLISION_VEC3 0
#define COLLISION_FLOAT 1
#define COLLISION_INT 2
#define COLLISION_CHAR 3

typedef struct collisionController{
	struct vec3 **_vec3;
	unsigned char numVec3;
	float *_float;
	unsigned char numFloat;
	unsigned char collisionObjectType;
} collisionController;

collisionController genCollisionController(void);
void freeCollisionController(collisionController *);
void collisionControllerElement(collisionController *, void *, unsigned char, unsigned char);

#endif /* COLLISION_CONTROLLER */
