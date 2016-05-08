
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
	HEIGHT = 1;
	WIDTH = 1;
	DRAW_BOUNDS = 1;
}
void freeCollisionsComponent() {
}
void updateCollisionsComponent(unsigned short deltaMS) {
}
void setBounds(float width, float height) {
	WIDTH = width;
	HEIGHT = height;
}
unsigned char CheckBoundingBoxCollision(unsigned char actorID) {
	//float Xsq = pow( POSX(getActor()) - POSX(actorID), 2);
	//float Zsq = pow( POSZ(getActor()) - POSZ(actorID), 2);
	//float distanceSq = Xsq + Zsq;
	unsigned char prevID = getActor();
	vec3 actOnePos = *POSITION;
	float actOneWidth = WIDTH;
	float actOneHeight = HEIGHT;
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
	return collide;
}
float getHeight() {
	return HEIGHT;
}
float getWidth() {
	return WIDTH;
}
