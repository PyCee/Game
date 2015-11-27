#ifndef _PHYSICS_COMPONENT_
#define _PHYSICS_COMPONENT_

//typedef struct _Vec3_t  Vec3_t;
#include "physics/vector.h"
typedef struct _vec3 vec3;

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

typedef struct _PhysicsComponent_t {
	vec3 Pos;
	vec3 Vel;
	vec3 Acc;
	vec3 Jrk;
	U16 Mass;// Measured in Grams
	U8 Elasticity;
	U8 Speed;
} PhysicsComponent_t;

void genPhysicsComponent();
void freePhysicsComponent();
void updatePhysicsComponent(U16);

void setSpeed( U8);
void setPos(vec3);
void setVel(vec3);
void setAcc(vec3);
void setJrk(vec3);

vec3 getPos(void);
vec3 getVel(void);
vec3 getAcc(void);
vec3 getJrk(void);
#endif /* _PHYSICS_COMPONENT_ */
