
#include "../dataTypes.h"
#include "renderComponent.h"

#include "../actors.h"
#include "collisionsComponent.h"
#include <stdio.h>


void genRenderComponent (U8 actorID)
{
}
void freeRenderComponent (U8 actorID)
{
}
// returns 1 if in range

//TODO: make culling based on field of view
static U8 XCulling( actorID )
{
	F32 ZPer = ( getPosZ(actorID) - MIN_Z ) / RANGE_Z;
	return ( getPosX(actorID) + getWidth(actorID) < -1 * RANGE_X * ZPer ^ getPosX(actorID) > RANGE_X * ZPer ) ? 0 : 1;
}
static U8 YCulling( actorID )
{
	F32 ZPer = ( getPosZ(actorID) - MIN_Z ) / RANGE_Z;
	return ( getPosY(actorID) + getHeight(actorID) < -1 * RANGE_Y * ZPer ^ getPosY(actorID) > RANGE_Y * ZPer ) ? 0 : 1;
}

static U8 ZCulling( actorID )
{
	return ( getPosZ(actorID) + getWidth(actorID) < MIN_Z ) ? 0 : 1;
	
	// use next line only if there is to be a limit on how far away something is (in terms of Z)
	//return ( getPosZ(actorID) + getWidth(actorID) < MIN_Z ^ getPosZ(actorID) - getWidth(actorID) > MAX_Z ) ? 0 : 1;
}
void updateRenderComponent (U8 actorID, U16 deltaMS)
{
	if ( !ZCulling(actorID) )
		return;
	if ( !XCulling(actorID) )
		return;
	if ( !YCulling(actorID) )
		return;
	if ( Actors.collisions[actorID].drawBounds )
		DrawBoundingBox(actorID);
	
	//TODO: draw.
}
