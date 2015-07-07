
#include "dataTypes.h"
#include "terrain.h"

#include "dyn_actors.h"
#include <stdio.h>

U8 genTerrain
(void)
{
	U8 actorID = AddActor();
	Dyn_Actors.identifier[actorID].ActorName = TERRAIN_NAME;
	assignAIUpdate(actorID, UpdateTerrain);
	Dyn_Actors.collisions[actorID].Height = 0.2;
	Dyn_Actors.collisions[actorID].Width = 10.0;
	Dyn_Actors.collisions[actorID].Length = 0.2;
	*getPosXPtr(actorID) = 1 * 0.0;
	*getPosYPtr(actorID) = -1 * 1.0;
	*getPosZPtr(actorID) = 1 * 1.0;
	return actorID;
}
void UpdateTerrain
(U8 actorID, U16 deltaMS)
{
}
