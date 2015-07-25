
#include "dataTypes.h"
#include "terrain.h"

#include "actors.h"
#include <stdio.h>

U8 genTerrain
(void)
{
	U8 actorID = addSta_Actor();
	Actors.identifier[actorID].ActorName = TERRAIN_NAME;
	assignAIUpdate(actorID, UpdateTerrain);
	Actors.collisions[actorID].Height = 0.2;
	Actors.collisions[actorID].Width = 10.0;
	setPosX(actorID, 1 * 0.0);
	setPosY(actorID, -1 * 1.0);
	setPosZ(actorID, 1 * 1.0);
	return actorID;
}
void UpdateTerrain
(U8 actorID, U16 deltaMS)
{
}
