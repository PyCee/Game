#ifndef _PHYSICS_COMPONENT_
#define _PHYSICS_COMPONENT_

#include "physics/vector.h"

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

#define POS physics[getActor()].Pos
#define VEL physics[getActor()].Vel
#define ACC physics[getActor()].Acc
#define JRK physics[getActor()].Jrk
#define GRAVITY physics[getActor()].Gravity
#define POSITION POS->attribute[0]
#define VELOCITY VEL->attribute[0]
#define ACCELERATION ACC->attribute[0]
#define JERK JRK->attribute[0]


typedef struct PhysicsComponent {
	
	struct physicsAttributeController *Pos;
	struct physicsAttributeController *Vel;
	struct physicsAttributeController *Acc;
	struct physicsAttributeController *Jrk;
	
	struct vec3 *Gravity;
	
	unsigned short mass; // Measured in Grams
	unsigned char speed;
} PhysicsComponent;

void genPhysicsComponent();
void freePhysicsComponent();
void updatePhysicsComponent(unsigned short);

void updatePosition(unsigned short);

#endif /* _PHYSICS_COMPONENT_ */
