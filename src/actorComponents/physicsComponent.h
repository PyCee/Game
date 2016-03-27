#ifndef _PHYSICS_COMPONENT_
#define _PHYSICS_COMPONENT_

//typedef struct _Vec3_t  Vec3_t;
#include "physics/vector.h"
typedef struct _vec3 vec3;

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

#define POS physics[getActor()].Pos
#define VEL physics[getActor()].Vel
#define ACC physics[getActor()].Acc
#define JRK physics[getActor()].Jrk
#define VEL_MULT physics[getActor()].multVel
#define ACC_MULT physics[getActor()].multAcc
#define JRK_MULT physics[getActor()].multJrk
#define VEL_YAW physics[getActor()].yawVel
#define ACC_YAW physics[getActor()].yawAcc
#define JRK_YAW physics[getActor()].yawJrk
#define VEL_QTY 8
#define ACC_QTY 10
#define JRK_QTY 4

typedef struct _PhysicsComponent {
	vec3 Pos;
	vec3 *Vel[VEL_QTY];
	vec3 *Acc[ACC_QTY];
	vec3 *Jrk[JRK_QTY];
	float multVel[VEL_QTY];
	float multAcc[ACC_QTY];
	float multJrk[JRK_QTY];
	float yawVel[VEL_QTY];
	float yawAcc[ACC_QTY];
	float yawJrk[JRK_QTY];
	unsigned short mass; // Measured in Grams
	unsigned char speed;
} PhysicsComponent;

void genPhysicsComponent();
void freePhysicsComponent();
void updatePhysicsComponent(unsigned short);

unsigned char getOpenVel(void);
unsigned char getOpenAcc(void);
unsigned char getOpenJrk(void);
unsigned char bindVel(vec3 *, float, float);
unsigned char bindAcc(vec3 *, float, float);
unsigned char bindJrk(vec3 *, float, float);
void unBindVel(unsigned char);
void unBindAcc(unsigned char);
void unBindJrk(unsigned char);
#endif /* _PHYSICS_COMPONENT_ */
