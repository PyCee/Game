#ifndef PHYSICS_COMPONENT
#define PHYSICS_COMPONENT

#define ACC_GRAVITY 9.8

#define POS_ATTRIBUTES 1
#define VEL_ATTRIBUTES 5
#define ACC_ATTRIBUTES 4
#define JRK_ATTRIBUTES 3
extern struct PhysicsComponent **physics;
#define PHYSICS physics[getActor()]
#define POS PHYSICS->pos
#define VEL PHYSICS->vel
#define ACC PHYSICS->acc
#define JRK PHYSICS->jrk
#define GRAVITY PHYSICS->Gravity
#define POSITION POS->attribute[0]
#define VELOCITY VEL->attribute[0]
#define ACCELERATION ACC->attribute[0]
#define JERK JRK->attribute[0]
#define PREVIOUSPOSITION PHYSICS->prevPos
#define SPEED PHYSICS->speed
#define SPEED_SIDE PHYSICS->sideSpeed
#define SPEED_BACK PHYSICS->backSpeed
#define MASS PHYSICS->mass
#define BOUNDING_BOX PHYSICS->AABB
#define CONTAINING_OCTREE_NODE PHYSICS->containingOctreeNode

#define HEIGHT PHYSICS->height
#define WIDTH PHYSICS->width
#define DRAW_BOUNDS PHYSICS->drawBounds

#define COLLISION_TABLE_SIZE 5

struct collisionController;

typedef struct PhysicsComponent {
	struct physicsAttributeController *pos, *vel, *acc, *jrk;
	struct vec3 *prevPos, *Gravity; // Allows for altered gravity
	float speed, sideSpeed, backSpeed;
	
	float height;
	float width;
	unsigned char drawBounds;
	
	unsigned short mass; // Measured in Grams
	
	struct collisionController *AABB;
	struct collisionController *colisionObjects;
	struct octreeNode *containingOctreeNode;
} PhysicsComponent;

extern unsigned char (*collisionTable[COLLISION_TABLE_SIZE][COLLISION_TABLE_SIZE])(struct collisionController, struct collisionController);

void initPhysics(void);
void genPhysicsComponent();
void freePhysicsComponent();
void updatePhysicsComponent(unsigned short);
unsigned char CheckBoundingBoxCollision(unsigned char);
unsigned char testCollision(struct collisionController, struct collisionController);

#endif /* PHYSICS_COMPONENT */
