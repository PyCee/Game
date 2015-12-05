
#include "dataTypes.h"
#include "terrain.h"

#include "actors.h"
#include <stdio.h>
#include "actorSelection.h"

U8 genTerrain
(void)
{
	addSta_Actor();
	Actors.identifier[getActor()].actorName = TERRAIN_NAME;
	assignAIUpdate(UpdateTerrain);
	setBounds(10.0, 0.2);
	setPos(genVec3(0.0, -1.0, 5.5));
	return getActor();
}
void UpdateTerrain
(U16 deltaMS)
{
	setPos(genVec3(0.0, -1.0, 5.5));
}
