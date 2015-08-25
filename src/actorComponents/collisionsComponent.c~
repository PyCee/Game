
#include "../dataTypes.h"
#include "collisionsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>
#include <string.h>

void genCollisionsComponent
(U8 actorID)
{
	Actors.collisions[actorID].Height = 1;
	Actors.collisions[actorID].Width = 1;
	Actors.collisions[actorID].drawBounds = 1;
}
void freeCollisionsComponent
(U8 actorID)
{
}
void updateCollisionsComponent
(U8 actorID, U16 deltaMS)
{
}
void setBounds
(U8 actorID, F32 width, F32 height)
{
	Actors.collisions[actorID].Width = width;
	Actors.collisions[actorID].Height = height;
	
	/*Actors.render[actorID].BoundingBoxVerticies[0] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[1] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[2] = 0.0;
	
	Actors.render[actorID].BoundingBoxVerticies[3] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[4] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[5] = 0.0;
	
	Actors.render[actorID].BoundingBoxVerticies[6] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[7] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[8] = 0.0;
	
	Actors.render[actorID].BoundingBoxVerticies[9] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[10] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[11] = 0.0;*/
	Actors.render[actorID].BoundingBoxVerticies[0] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[1] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[2] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[3] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[4] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[5] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[6] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[7] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[8] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[9] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[10] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[11] = getWidth(actorID) * -1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[12] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[13] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[14] = getWidth(actorID) * 1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[15] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[16] = 0.0;
	Actors.render[actorID].BoundingBoxVerticies[17] = getWidth(actorID) * 1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[18] = getWidth(actorID) * 1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[19] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[20] = getWidth(actorID) * 1 * 0.5;
	
	Actors.render[actorID].BoundingBoxVerticies[21] = getWidth(actorID) * -1 * 0.5;
	Actors.render[actorID].BoundingBoxVerticies[22] = getHeight(actorID);
	Actors.render[actorID].BoundingBoxVerticies[23] = getWidth(actorID) * 1 * 0.5;
	
	glBindBuffer(GL_ARRAY_BUFFER, Actors.render[actorID].BoundingBoxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Actors.render[actorID].BoundingBoxVerticies), Actors.render[actorID].BoundingBoxVerticies, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
U8 CheckBoundingBoxCollision
(U8 actorIDOne, U8 actorIDTwo)
{
	//F32 Xsq = pow( getPosX(actorIDOne) - getPosX(actorIDTwo), 2);
	//F32 Zsq = pow( getPosZ(actorIDOne) - getPosZ(actorIDTwo), 2);
	//F32 distanceSq = Xsq + Zsq;
	if ( getPosX(actorIDOne) - 0.5 * getWidth(actorIDOne) <
   		getPosX(actorIDTwo) + 0.5 * getWidth(actorIDTwo) &&
   		getPosX(actorIDOne) + 0.5 * getWidth(actorIDOne) >
   		getPosX(actorIDTwo) - 0.5 * getWidth(actorIDTwo) &&
   		getPosY(actorIDOne)	<
   				getPosY(actorIDTwo) + getHeight(actorIDTwo) &&
   		getPosY(actorIDOne)	+
   				getHeight(actorIDOne) > getPosY(actorIDTwo) )
    // Bounding Boxes Overlapping!
  	return 1;
  // Bounding Boxes Not Overlapping...
	return 0;
}
F64 getHeight
(U8 actorID)
{
	return Actors.collisions[actorID].Height;
}
F64 getWidth
(U8 actorID)
{
	return Actors.collisions[actorID].Width;
}
