
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
	setBounds(actorID, 10.0, 0.2);
	setPos(actorID, genVec3(0.0, -1.0, 5.5));
	return actorID;
}
void UpdateTerrain
(U8 actorID, U16 deltaMS)
{
}
