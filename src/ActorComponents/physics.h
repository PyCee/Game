
#ifndef _PHYSICS_
#define _PHYSICS_

#include <stdint.h>
#include "../math/vector.h"

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

typedef struct _Physics_t{
	
	F64 FrictCo;
	F64 Height;
	F64 Width;
	F64 Length;
	U16 Mass;
		// in kg
	U8 Terrain;
	U8 Conductor;
	U8 Elasticity;
	
	Vec3_t *Pos;
	Vec3_t *Vel;
	Vec3_t *Acc;
	Vec3_t *Jrk;
} Physics_t;

void genPhysics(Physics_t **);
void freePhysics(Physics_t **);
void UpdatePhysics(Physics_t *, U64);

unsigned char CheckBoundingBoxCollision(Physics_t *, Physics_t *);
void DrawBoundingBox(Physics_t *);

#endif
