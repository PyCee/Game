
#ifndef _PHYSICS_COMPONENT_
#define _PHYSICS_COMPONENT_

//typedef struct _Vec3_t  Vec3_t;
#include "../math/vector.h"
#include "../math/matrix.h"
typedef struct _Matrix_t Vec3_t;

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

typedef struct _PhysicsComponent_t{
	Vec3_t		Pos;
	Vec3_t		Vel;
	Vec3_t		Acc;
	Vec3_t		Jrk;
	U16 			Mass;					// Measured in Grams
	U8 				Elasticity;
	U8				Speed;
} PhysicsComponent_t;

void	genPhysicsComponent				(U8);
void	freePhysicsComponent			(U8);
void	updatePhysicsComponent		(U8, U16);

void	setSpeed									(U8, U8);

F64		*		getPosXPtr		(U8);
F64		*		getPosYPtr		(U8);
F64		*		getPosZPtr		(U8);
F64				getPosX				(U8);
F64				getPosY				(U8);
F64				getPosZ				(U8);

F64		*		getVelXPtr		(U8);
F64		*		getVelYPtr		(U8);
F64		*		getVelZPtr		(U8);
F64				getVelX				(U8);
F64				getVelY				(U8);
F64				getVelZ				(U8);

F64		*		getAccXPtr		(U8);
F64		*		getAccYPtr		(U8);
F64		*		getAccZPtr		(U8);
F64				getAccX				(U8);
F64				getAccY				(U8);
F64				getAccZ				(U8);

F64		*		getJrkXPtr		(U8);
F64		*		getJrkYPtr		(U8);
F64		*		getJrkZPtr		(U8);
F64				getJrkX				(U8);
F64				getJrkY				(U8);
F64				getJrkZ				(U8);


#endif /* _PHYSICS_COMPONENT_ */
