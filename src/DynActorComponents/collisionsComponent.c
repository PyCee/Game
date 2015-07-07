
#include "../dataTypes.h"
#include "collisionsComponent.h"

#include "../dyn_actors.h"
#include <SDL2/SDL_opengl.h>

void genCollisionsComponent
(U8 actorID)
{
	Dyn_Actors.collisions[actorID].Height = 1;
	Dyn_Actors.collisions[actorID].Width = 1;
	Dyn_Actors.collisions[actorID].Length = 1;
}
void freeCollisionsComponent
(U8 actorID)
{
	Dyn_Actors.collisions[actorID].Height = 0;
	Dyn_Actors.collisions[actorID].Width = 0;
	Dyn_Actors.collisions[actorID].Length = 0;
}
void updateCollisionsComponent
(U8 actorID, U16 deltaMS)
{
	DrawBoundingBox(actorID);
}
void setBounds
(U8 actorID, F32 height, F32 width, F32 length)
{
	Dyn_Actors.collisions[actorID].Height	=	height;
	Dyn_Actors.collisions[actorID].Width	=	width;
	Dyn_Actors.collisions[actorID].Length	=	length;
}
U8 CheckBoundingBoxCollision
(U8 actorIDOne, U8 actorIDTwo)
{
	if (getVecX(Dyn_Actors.physics[actorIDOne].Pos)	- getWidth(actorIDOne) * 0.5 <
					getVecX(Dyn_Actors.physics[actorIDTwo].Pos) + getWidth(actorIDTwo) * 0.5 &&
   		getVecX(Dyn_Actors.physics[actorIDOne].Pos)	+ getWidth(actorIDOne) * 0.5 >
   				getVecX(Dyn_Actors.physics[actorIDTwo].Pos) - getWidth(actorIDTwo) * 0.5 &&
   		getVecY(Dyn_Actors.physics[actorIDOne].Pos)	<
   				getVecY(Dyn_Actors.physics[actorIDTwo].Pos) + getHeight(actorIDTwo) &&
   		getVecY(Dyn_Actors.physics[actorIDOne].Pos)	+
   				getHeight(actorIDOne) > getVecY(Dyn_Actors.physics[actorIDTwo].Pos)/* &&
   		getVecZ(Dyn_Actors.physics[actorIDOne].Pos)	- getLength(actorIDOne) * 0.5	<
   				getVecZ(Dyn_Actors.physics[actorIDTwo].Pos) + getLength(actorIDTwo) * 0.5 &&
   		getVecZ(Dyn_Actors.physics[actorIDOne].Pos)	+ getLength(actorIDOne) * 0.5 >
   				getVecZ(Dyn_Actors.physics[actorIDTwo].Pos)	- getLength(actorIDTwo) * 0.5 */)
    // Bounding Boxes Overlapping!
  	return 1;
  // Bounding Boxes Not Overlapping...
	return 0;
}
void DrawBoundingBox
(U8 actorID)
{
	F64 X = getVecX(Dyn_Actors.physics[actorID].Pos);
	F64 Y = getVecY(Dyn_Actors.physics[actorID].Pos);
	F64 Z = getVecZ(Dyn_Actors.physics[actorID].Pos);
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
	return Dyn_Actors.collisions[actorID].Height;
}
F64 getWidth
(U8 actorID)
{
	return Dyn_Actors.collisions[actorID].Width;
}
F64 getLength
(U8 actorID)
{
	return Dyn_Actors.collisions[actorID].Length;
}
