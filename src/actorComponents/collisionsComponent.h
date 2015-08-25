
#ifndef _COLLISIONS_COMPONENT_
#define _COLLISIONS_COMPONENT_

#include "../actorCounts.h"

// when collisions are based off of actual character (not bounding box), change to circular bounds.
typedef struct _CollisionsComponent_t{
	F32	Height;		// Measured in Meters
	F32 	Width;		// Measured in Meters
	U8	drawBounds;
} CollisionsComponent_t;

void	genCollisionsComponent		(U8);
void	freeCollisionsComponent		(U8);
void	updateCollisionsComponent	(U8, U16);
void	setBounds			(U8, F32, F32);
U8	CheckBoundingBoxCollision	(U8, U8);


F64 getHeight(U8);
F64 getWidth(U8);

#endif /* _COLLISIONS_COMPONENT_ */