
#include "../dataTypes.h"
#include "collisionsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>
#include <string.h>

void genCollisionsComponent
()
{
	Actors.collisions[getActor()].Height = 1;
	Actors.collisions[getActor()].Width = 1;
	Actors.collisions[getActor()].drawBounds = 1;
}
void freeCollisionsComponent
()
{
}
void updateCollisionsComponent
(U16 deltaMS)
{
}
void setBounds
(F32 width, F32 height)
{
	Actors.collisions[getActor()].Width = width;
	Actors.collisions[getActor()].Height = height;
	
	Actors.render[getActor()].BoundingBoxVerticies[0] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[1] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[2] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[3] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[4] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[5] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[6] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[7] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[8] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[9] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[10] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[11] = getWidth() * -1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[12] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[13] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[14] = getWidth() * 1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[15] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[16] = 0.0;
	Actors.render[getActor()].BoundingBoxVerticies[17] = getWidth() * 1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[18] = getWidth() * 1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[19] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[20] = getWidth() * 1 * 0.5;
	
	Actors.render[getActor()].BoundingBoxVerticies[21] = getWidth() * -1 * 0.5;
	Actors.render[getActor()].BoundingBoxVerticies[22] = getHeight();
	Actors.render[getActor()].BoundingBoxVerticies[23] = getWidth() * 1 * 0.5;
	
	glBindBuffer(GL_ARRAY_BUFFER, Actors.render[getActor()].BoundingBoxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Actors.render[getActor()].BoundingBoxVerticies), Actors.render[getActor()].BoundingBoxVerticies, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
U8 CheckBoundingBoxCollision
(U8 actorID)
{
	//F32 Xsq = pow( getPosX(getActor()) - getPosX(actorID), 2);
	//F32 Zsq = pow( getPosZ(getActor()) - getPosZ(actorID), 2);
	//F32 distanceSq = Xsq + Zsq;
	U8 prevID = getActor();
	vec3 actOnePos = getPos();
	F32 actOneWidth = getWidth();
	F32 actOneHeight = getHeight();
	
	U8 collide;
	
	bindActor(actorID);
	if (actOnePos.vec[0] - 0.5 * actOneWidth <
   			getPos().vec[0] + 0.5 * getWidth() &&
   		actOnePos.vec[0] + 0.5 * actOneWidth >
   			getPos().vec[0] - 0.5 * getWidth() &&
   		actOnePos.vec[1] <
   			getPos().vec[1] + getHeight() &&
   		actOnePos.vec[1] +
   			actOneHeight > getPos().vec[1] )
    // Bounding Boxes Overlapping!
  		collide = 1;
  // Bounding Boxes Not Overlapping...
  	else
		collide = 0;
	bindActor(prevID);
	return collide;
}
F32 getHeight()
{
	return Actors.collisions[getActor()].Height;
}
F32 getWidth()
{
	return Actors.collisions[getActor()].Width;
}
