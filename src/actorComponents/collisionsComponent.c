
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
	vec3 actOnePos = *POSITION;
	float actOneWidth = getWidth();
	float actOneHeight = getHeight();
	bindActor(actorID);
	unsigned char collide;
	if (actOnePos.vec[0] - 0.5 * actOneWidth
			< POSITION->vec[0] + 0.5 * getWidth()
			&& actOnePos.vec[0] + 0.5 * actOneWidth
					> POSITION->vec[0] - 0.5 * getWidth()
			&& actOnePos.vec[1] < POSITION->vec[1] + getHeight()
			&& actOnePos.vec[1] + actOneHeight > POSITION->vec[1])
		collide = 1;// Bounding Boxes Overlapping
	else
		collide = 0;// Bounding Boxes Not Overlapping
	bindActor(prevID);
	printf("collide = %hhu\n", collide);
	return collide;
}
float getHeight() {
	return collisions[getActor()].height;
}
float getWidth() {
	return collisions[getActor()].width;
}
