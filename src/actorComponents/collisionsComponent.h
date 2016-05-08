#ifndef _COLLISIONS_COMPONENT_
#define _COLLISIONS_COMPONENT_

#include "../actorSelection.h"

#define COLLISIONS collisions[getActor()]
#define HEIGHT COLLISIONS->height
#define WIDTH COLLISIONS->width
#define DRAW_BOUNDS COLLISIONS->drawBounds

typedef struct CollisionsComponent {
	float height;
	float width;
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
