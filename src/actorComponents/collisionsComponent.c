
#include "collisionsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>
#include <string.h>
#include "physics/physicsAttributeController.h"
#include <stdio.h>
#include "physicsComponent.h"
#include "physics/vector.h"

void genCollisionsComponent() {
	collisions[getActor()].height = 1;
	collisions[getActor()].width = 1;
	collisions[getActor()].drawBounds = 1;
}
void freeCollisionsComponent() {
}
void updateCollisionsComponent(unsigned short deltaMS) {
}
void setBounds(float width, float height) {
	collisions[getActor()].width = width;
	collisions[getActor()].height = height;
}
unsigned char CheckBoundingBoxCollision(unsigned char actorID) {
	//float Xsq = pow( POSX(getActor()) - POSX(actorID), 2);
	//float Zsq = pow( POSZ(getActor()) - POSZ(actorID), 2);
	//float distanceSq = Xsq + Zsq;
	unsigned char prevID = getActor();
	vec3 actOnePos = *(POS->attribute[0]);
	float actOneWidth = getWidth();
	float actOneHeight = getHeight();

	unsigned char collide;

	bindActor(actorID);
	if (actOnePos.vec[0] - 0.5 * actOneWidth
			< (*(POS->attribute[0])).vec[0] + 0.5 * getWidth()
			&& actOnePos.vec[0] + 0.5 * actOneWidth
					> (*(POS->attribute[0])).vec[0] - 0.5 * getWidth()
			&& actOnePos.vec[1] < (*(POS->attribute[0])).vec[1] + getHeight()
			&& actOnePos.vec[1] + actOneHeight > (*(POS->attribute[0])).vec[1])
		// Bounding Boxes Overlapping!
		collide = 1;
	// Bounding Boxes Not Overlapping...
	else
		collide = 0;
	bindActor(prevID);
	return collide;
}
float getHeight() {
	return collisions[getActor()].height;
}
float getWidth() {
	return collisions[getActor()].width;
}
