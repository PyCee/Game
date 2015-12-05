
#include "dataTypes.h"
#include "protag.h"

#include "actors.h"

#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "actorSelection.h"

U8 genProtag
(void)
{
	addDyn_Actor();
	Actors.identifier[getActor()].actorName = PROTAG_NAME;
	assignAIUpdate(UpdateProtag);
	setBounds(0.2, 0.2);
	setPos(genVec3(0.0, 0.3, 1.0));
	return getActor();
}
void UpdateProtag
(U16 deltaMS)
{
}
void Jump
(void)
{
	bindActor(getControlledActor());
	setVel(genVec3(getVel().vec[0], getVel().vec[1] + 1 * 0.002, getVel().vec[2]));
}
void ControlledActorForward
(void)
{
	bindActor(getControlledActor());
	setVel(genVec3(getVel().vec[0], getVel().vec[1], getVel().vec[2] + 1 * SPEED_FORWARD));
	bindActor(getCameraView());
	setVel(genVec3(getVel().vec[0], getVel().vec[1], getVel().vec[2] + 1 * SPEED_FORWARD));
}
void ControlledActorLeft
(void)
{
	bindActor(getControlledActor());
	setVel(genVec3(getVel().vec[0] - 1 * SPEED_FORWARD, getVel().vec[1], getVel().vec[2]));
	bindActor(getCameraView());
	setVel(genVec3(getVel().vec[0] - 1 * SPEED_FORWARD, getVel().vec[1], getVel().vec[2]));
}
void ControlledActorBackward
(void)
{
	bindActor(getControlledActor());
	setVel(genVec3(getVel().vec[0], getVel().vec[1], getVel().vec[2] - 1 * SPEED_FORWARD));
	bindActor(getCameraView());
	setVel(genVec3(getVel().vec[0], getVel().vec[1], getVel().vec[2] - 1 * SPEED_FORWARD));
}
void ControlledActorRight
(void)
{
	bindActor(getControlledActor());
	setVel(genVec3(getVel().vec[0] + 1 * SPEED_FORWARD, getVel().vec[1], getVel().vec[2]));
	bindActor(getCameraView());
	setVel(genVec3(getVel().vec[0] + 1 * SPEED_FORWARD, getVel().vec[1], getVel().vec[2]));
}
