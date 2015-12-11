
#include "terrain.h"

#include "actors.h"
#include <stdio.h>
#include "actorSelection.h"

unsigned char genTerrain
(void)
{
	addSta_Actor();
	assignAIUpdate(UpdateTerrain);
	setBounds(10.0, 0.2);
	setPos(genVec3(0.0, -1.0, 5.5));
	return getActor();
}
void UpdateTerrain
(unsigned short deltaMS)
{
	setPos(genVec3(0.0, -1.0, 5.5));
}
