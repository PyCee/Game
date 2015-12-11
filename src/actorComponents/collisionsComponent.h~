#ifndef _COLLISIONS_COMPONENT_
#define _COLLISIONS_COMPONENT_

#include "../actorSelection.h"

// when collisions are based off of actual character (not bounding box), change to circular bounds.
typedef struct _CollisionsComponent {
	float height;		// Measured in Meters
	float width;		// Measured in Meters
	unsigned char drawBounds;
} CollisionsComponent;

void genCollisionsComponent();
void freeCollisionsComponent();
void updateCollisionsComponent(unsigned short);
void setBounds(float, float);
unsigned char CheckBoundingBoxCollision(unsigned char);

float getHeight();
float getWidth();

#endif /* _COLLISIONS_COMPONENT_ */
