
#include "../dataTypes.h"
#include "collisionsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>

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
	Actors.collisions[actorID].Height = 0;
	Actors.collisions[actorID].Width = 0;
}
void updateCollisionsComponent
(U8 actorID, U16 deltaMS)
{
}
void setBounds
(U8 actorID, F32 height, F32 width)
{
	Actors.collisions[actorID].Height	=	height;
	Actors.collisions[actorID].Width	=	width;
}
U8 CheckBoundingBoxCollision
(U8 actorIDOne, U8 actorIDTwo)
{
	F32 Xsq = pow( getPosX(actorIDOne) - getPosX(actorIDTwo), 2);
	F32 Zsq = pow( getPosZ(actorIDOne) - getPosZ(actorIDTwo), 2);
	F32 distance = Xsq + Zsq;
	if ( distance < pow(getWidth(actorIDOne), 2) + pow(getWidth(actorIDTwo), 2) &&
   		getPosY(actorIDOne)	<
   				getPosY(actorIDTwo) + getHeight(actorIDTwo) &&
   		getPosY(actorIDOne)	+
   				getHeight(actorIDOne) > getPosY(actorIDTwo) )
    // Bounding Boxes Overlapping!
  	return 1;
  // Bounding Boxes Not Overlapping...
	return 0;
}
void DrawBoundingBox
(U8 actorID)
{
	F64 X = getPosX(actorID);
	F64 Y = getPosY(actorID);
	F64 Z = getPosZ(actorID);
	// TODO: update this function once drawing/rendering is fully impllimented
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
 		glVertex2f((X - getWidth(actorID) * 0.5) / Z, Y / Z);
 		glVertex2f((X + getWidth(actorID) * 0.5) / Z, Y / Z);
 		glVertex2f((X + getWidth(actorID) * 0.5) / Z, (Y + getHeight(actorID)) / Z);
 		glVertex2f((X - getWidth(actorID) * 0.5) / Z, (Y + getHeight(actorID)) / Z);
	glEnd();
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
 		glVertex2f((X - getWidth(actorID) * 0.5 / 8) / Z, Y / Z);
 		glVertex2f((X + getWidth(actorID) * 0.5 / 8) / Z, Y / Z);
 		glVertex2f((X + getWidth(actorID) * 0.5 / 8) / Z, (Y + getHeight(actorID) / 8) / Z);
 		glVertex2f((X - getWidth(actorID) * 0.5 / 8) / Z, (Y + getHeight(actorID) / 8) / Z);
	glEnd();
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
