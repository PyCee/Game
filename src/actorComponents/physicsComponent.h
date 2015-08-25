
#ifndef _PHYSICS_COMPONENT_
#define _PHYSICS_COMPONENT_

//typedef struct _Vec3_t  Vec3_t;
#include "physics/vector.h"
typedef struct _vec3 vec3;

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

typedef struct _PhysicsComponent_t{
	vec3		Pos;
	vec3		Vel;
	vec3		Acc;
	vec3		Jrk;
	U16 			Mass;					// Measured in Grams
	U8 				Elasticity;
	U8				Speed;
} PhysicsComponent_t;

void		genPhysicsComponent		(U8);
void		freePhysicsComponent		(U8);
void		updatePhysicsComponent		(U8, U16);

void		setSpeed	(U8, U8);
void	 	setPos		(U8, vec3);

void		setPosX		(U8, F32);
void		setPosY		(U8, F32);
void		setPosZ		(U8, F32);
F32		getPosX		(U8);
F32		getPosY		(U8);
F32		getPosZ		(U8);

void		setVelX		(U8, F32);
void		setVelY		(U8, F32);
void		setVelZ		(U8, F32);
F32		getVelX		(U8);
F32		getVelY		(U8);
F32		getVelZ		(U8);

void		setAccX		(U8, F32);
void		setAccY		(U8, F32);
void		setAccZ		(U8, F32);
F32		getAccX		(U8);
F32		getAccY		(U8);
F32		getAccZ		(U8);

void		setJrkX		(U8, F32);
void		setJrkY		(U8, F32);
void		setJrkZ		(U8, F32);
F32		getJrkX		(U8);
F32		getJrkY		(U8);
F32		getJrkZ		(U8);
#endif /* _PHYSICS_COMPONENT_ */
