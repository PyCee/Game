
#include "collisionsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>
#include <string.h>

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

	render[getActor()].BoundingBoxVerticies[0] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[1] = 0.0;
	render[getActor()].BoundingBoxVerticies[2] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[3] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[4] = 0.0;
	render[getActor()].BoundingBoxVerticies[5] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[6] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[7] = getHeight();
	render[getActor()].BoundingBoxVerticies[8] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[9] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[10] = getHeight();
	render[getActor()].BoundingBoxVerticies[11] = getWidth() * -1 * 0.5;

	render[getActor()].BoundingBoxVerticies[12] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[13] = 0.0;
	render[getActor()].BoundingBoxVerticies[14] = getWidth() * 1 * 0.5;

	render[getActor()].BoundingBoxVerticies[15] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[16] = 0.0;
	render[getActor()].BoundingBoxVerticies[17] = getWidth() * 1 * 0.5;

	render[getActor()].BoundingBoxVerticies[18] = getWidth() * 1 * 0.5;
	render[getActor()].BoundingBoxVerticies[19] = getHeight();
	render[getActor()].BoundingBoxVerticies[20] = getWidth() * 1 * 0.5;

	render[getActor()].BoundingBoxVerticies[21] = getWidth() * -1 * 0.5;
	render[getActor()].BoundingBoxVerticies[22] = getHeight();
	render[getActor()].BoundingBoxVerticies[23] = getWidth() * 1 * 0.5;

	glBindBuffer(GL_ARRAY_BUFFER, render[getActor()].BoundingBoxVBO);
	glBufferData(GL_ARRAY_BUFFER,
			sizeof(render[getActor()].BoundingBoxVerticies),
			render[getActor()].BoundingBoxVerticies, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
unsigned char CheckBoundingBoxCollision(unsigned char actorID) {
	//float Xsq = pow( POSX(getActor()) - POSX(actorID), 2);
	//float Zsq = pow( POSZ(getActor()) - POSZ(actorID), 2);
	//float distanceSq = Xsq + Zsq;
	unsigned char prevID = getActor();
	vec3 actOnePos = POS;
	float actOneWidth = getWidth();
	float actOneHeight = getHeight();

	unsigned char collide;

	bindActor(actorID);
	if (actOnePos.vec[0] - 0.5 * actOneWidth
			< POS.vec[0] + 0.5 * getWidth()
			&& actOnePos.vec[0] + 0.5 * actOneWidth
					> POS.vec[0] - 0.5 * getWidth()
			&& actOnePos.vec[1] < POS.vec[1] + getHeight()
			&& actOnePos.vec[1] + actOneHeight > POS.vec[1])
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
