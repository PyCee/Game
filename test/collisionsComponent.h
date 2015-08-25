
#ifndef _COLLISIONS_COMPONENT_
#define _COLLISIONS_COMPONENT_

#include "../actorCounts.h"

typedef struct _CollisionsComponent_t{
	F32	Bounds;		// Measured in Meters
	U8	drawBounds;
} CollisionsComponent_t;

void	genCollisionsComponent		(U8);
void	freeCollisionsComponent		(U8);
void	updateCollisionsComponent	(U8, U16);
void	setBounds			(U8, F32);
U8	CheckBoundingBoxCollision	(U8, U8);
void	DrawBoundingBox			(U8);

F64 getBounds(U8);

#endif /* _COLLISIONS_COMPONENT_ */
