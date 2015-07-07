
#include "dataTypes.h"
#include "protag.h"

#include "dyn_actors.h"

#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "math/vector.h"
#include "globalBinds.h"

U8 genProtag
(void)
{
	U8 actorID = AddActor();
	Dyn_Actors.identifier[actorID].ActorName = PROTAG_NAME;
	assignAIUpdate(actorID, UpdateProtag);
	setBounds(actorID, 0.2, 0.2, 0.0);
	*getPosXPtr(actorID) = -1 * 0.75;
	*getPosYPtr(actorID) = -1 * 0.75;
	*getPosZPtr(actorID) = 1.0;
	return actorID;
}
void UpdateProtag
(U8 actorID, U16 deltaMS)
{
}
void Jump
(void)
{
	*getVelYPtr(getControlledActor()) += 0.002;
}
void ControlledActorForward
(void)
{
	*getVelZPtr(getControlledActor()) += 1 * SPEED_FORWARD;
	*getVelZPtr(getCameraView()) += 1 * SPEED_FORWARD;
}
void ControlledActorLeft
(void)
{
	*getVelXPtr(getControlledActor()) -= 1 * SPEED_FORWARD;
	*getVelXPtr(getCameraView()) -= 1 * SPEED_FORWARD;
}
void ControlledActorBackward
(void)
{
	*getVelZPtr(getControlledActor()) -= 1 * SPEED_FORWARD;
	*getVelZPtr(getCameraView()) -= 1 * SPEED_FORWARD;
}
void ControlledActorRight
(void)
{
	*getVelXPtr(getControlledActor()) += 1 * SPEED_FORWARD;
	*getVelXPtr(getCameraView()) += 1 * SPEED_FORWARD;
}
