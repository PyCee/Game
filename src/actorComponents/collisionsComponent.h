#ifndef _COLLISIONS_COMPONENT_
#define _COLLISIONS_COMPONENT_

#include "../actorSelection.h"

// when collisions are based off of actual character (not bounding box), change to circular bounds.
typedef struct _CollisionsComponent_t {
	F32 Height;		// Measured in Meters
	F32 Width;		// Measured in Meters
	U8 drawBounds;
} CollisionsComponent_t;

void genCollisionsComponent();
void freeCollisionsComponent();
void updateCollisionsComponent(U16);
void setBounds(F32, F32);
U8 CheckBoundingBoxCollision(U8);

F32 getHeight();
F32 getWidth();

#endif /* _COLLISIONS_COMPONENT_ */
