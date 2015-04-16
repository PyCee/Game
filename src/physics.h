
#ifndef _PHYSICS_
#define _PHYSICS_

#include <stdint.h>
#include "math/vector.h"

#define ACC_GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

typedef struct _Physics_t{
	
	unsigned char Terrain;
	unsigned char Conductor;
	unsigned char Bounciness;
	unsigned short Mass;
	double FrictCo;
	double Height;
	double Width;
	double Length;
	
	Vec3_t *Pos;
	Vec3_t *Vel;
	Vec3_t *Acc;
	Vec3_t *Jrk;
} Physics_t;

void genPhysics(Physics_t **);
void freePhysics(Physics_t **);
void UpdatePhysics(Physics_t *, uint64_t);

#endif
