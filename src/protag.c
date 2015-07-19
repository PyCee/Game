
#include "dataTypes.h"
#include "protag.h"

#include "actors.h"

#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "globalBinds.h"

U8 genProtag
(void)
{
	U8 actorID = addDyn_Actor();
	Actors.identifier[actorID].ActorName = PROTAG_NAME;
	assignAIUpdate(actorID, UpdateProtag);
	setBounds(actorID, 0.2, 0.2, 0.0);
	setPosX(actorID, -1 * 0.75);
	setPosY(actorID, -1 * 0.75);
	setPosZ(actorID, 1 * 1.0);
	return actorID;
}
void UpdateProtag
(U8 actorID, U16 deltaMS)
{
}
void Jump
(void)
{
	setVelY(getControlledActor(), getVelY(getControlledActor()) + 1 * 0.002);
}
void ControlledActorForward
(void)
{
	setVelZ(getControlledActor(), getVelZ(getControlledActor()) + 1 * SPEED_FORWARD);
	setVelZ(getCameraView(), getVelZ(getCameraView()) + 1 * SPEED_FORWARD);
}
void ControlledActorLeft
(void)
{
	setVelX(getControlledActor(), getVelX(getControlledActor()) - 1 * SPEED_FORWARD);
	setVelX(getCameraView(), getVelX(getCameraView()) - 1 * SPEED_FORWARD);
}
void ControlledActorBackward
(void)
{
	setVelZ(getControlledActor(), getVelZ(getControlledActor()) - 1 * SPEED_FORWARD);
	setVelZ(getCameraView(), getVelZ(getCameraView()) - 1 * SPEED_FORWARD);
}
void ControlledActorRight
(void)
{
	setVelX(getControlledActor(), getVelX(getControlledActor()) + 1 * SPEED_FORWARD);
	setVelX(getCameraView(), getVelX(getCameraView()) + 1 * SPEED_FORWARD);
}
