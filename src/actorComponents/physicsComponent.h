#ifndef _PHYSICS_COMPONENT_
#define _PHYSICS_COMPONENT_

#define ACC_GRAVITY 0.000006

#define POS_ATTRIBUTES 1
#define VEL_ATTRIBUTES 5
#define ACC_ATTRIBUTES 4
#define JRK_ATTRIBUTES 3

#define POS physics[getActor()].pos
#define VEL physics[getActor()].vel
#define ACC physics[getActor()].acc
#define JRK physics[getActor()].jrk
#define GRAVITY physics[getActor()].Gravity
#define POSITION POS->attribute[0]
#define VELOCITY VEL->attribute[0]
#define ACCELERATION ACC->attribute[0]
#define JERK JRK->attribute[0]
#define PREVIOUSPOSITION physics[getActor()].prevPos
#define SPEED physics[getActor()].speed
#define SPEED_SIDE physics[getActor()].sideSpeed
#define SPEED_BACK physics[getActor()].backSpeed

typedef struct PhysicsComponent {
	
	struct physicsAttributeController *pos, *vel, *acc, *jrk;
	
	struct vec3 *prevPos;
	struct vec3 *Gravity;
	float speed, sideSpeed, backSpeed;
	
	unsigned short mass; // Measured in Grams
} PhysicsComponent;

void genPhysicsComponent();
void freePhysicsComponent();
void updatePhysicsComponent(unsigned short);

#endif /* _PHYSICS_COMPONENT_ */
