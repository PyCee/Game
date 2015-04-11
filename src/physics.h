
#ifndef _PHYSICS_
#define _PHYSICS_

#include <stdint.h>
#include "math/vector.h"

#define GRAVITY 0.000006
#define BOUNCY_DMG_REDUCTION 0.75

typedef struct _Physics_t{
	
	char Terrain;
	double Mass;
	double Height;
	double Width;
	double Length;
	char Conductor;
	double Friction;
	double Bounciness;
	
	Vec3_t Pos;
	Vec3_t Vel;
	Vec3_t Acc;
	Vec3_t Jerk;
} Physics_t;

void UpdatePhysics(Physics_t *, uint64_t);

#endif
