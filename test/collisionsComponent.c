
#include "../dataTypes.h"
#include "collisionsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <math.h>

void genCollisionsComponent
(U8 actorID)
{
	Actors.collisions[actorID].Bounds = 1;
	Actors.collisions[actorID].drawBounds = 0;
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
(U8 actorID, F32 bounds)
{
	Actors.collisions[actorID].Bounds = bounds;
}
U8 CheckBoundingBoxCollision
(U8 actorIDOne, U8 actorIDTwo)
{
	F32 BoundsOne = getBounds( actorIDOne );
	F32 BoundsTwo = getBounds( actorIDTwo );
	if ( getPosX(actorIDOne) - 0.5 * BoundsOne < getPosX(actorIDTwo) + 0.5 * BoundsTwo &&
		getPosX(actorIDOne) + 0.5 * BoundsOne > getPosX(actorIDTwo) - 0.5 * BoundsTwo &&
   		getPosY(actorIDOne) < getPosY(actorIDTwo) + getBounds(actorIDTwo) &&
		getPosY(actorIDOne) + BoundsOne > getPosY(actorIDTwo)/* &&
		getPosZ(actorIDOne) - 0.5 * BoundsOne < getPosZ(actorIDTwo) + 0.5 * BoundsTwo &&
		getPosZ(actorIDOne) + 0.5 * BoundsOne > getPosZ(actorIDTwo) - 0.5 * BoundsTwo */)
    // Bounding Boxes Overlapping!
  	return 1;
  // Bounding Boxes Not Overlapping...
	return 0;
}
void DrawBoundingBox
(U8 actorID)
{
	F32 X = getPosX(actorID);
	F32 Y = getPosY(actorID);
	F32 Z = getPosZ(actorID);
	// TODO: update this function once drawing/rendering is fully impllimented
	glColor3f(0.4f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
 		glVertex2f((X - getBounds(actorID) * 0.5) / Z, Y / Z);
 		glVertex2f((X + getBounds(actorID) * 0.5) / Z, Y / Z);
 		glVertex2f((X + getBounds(actorID) * 0.5) / Z, (Y + getBounds(actorID)) / Z);
 		glVertex2f((X - getBounds(actorID) * 0.5) / Z, (Y + getBounds(actorID)) / Z);
	glEnd();
	
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
 		glVertex2f((X - getBounds(actorID) * 0.5 / 10) / Z, Y / Z);
 		glVertex2f((X + getBounds(actorID) * 0.5 / 10) / Z, Y / Z);
 		glVertex2f((X + getBounds(actorID) * 0.5 / 10) / Z, (Y + getBounds(actorID) / 10) / Z);
 		glVertex2f((X - getBounds(actorID) * 0.5 / 10) / Z, (Y + getBounds(actorID) / 10) / Z);
	glEnd();
}
F64 getBounds
(U8 actorID)
{
	return Actors.collisions[actorID].Bounds;
}
