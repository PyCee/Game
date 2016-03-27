
#include "protag.h"

#include "actors.h"
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "actorSelection.h"

void UpdateProtag(unsigned short deltaMS)
{
	printVec3(POS);
}
void Jump(void)
{
	printf("Jump Called\n\n\n\n\n\n");
	bindActor(getControlledActor());
	//setVel(genVec3(getVel().vec[0], getVel().vec[1] + 1 * 0.002, getVel().vec[2]));
	VEL[0]->vec[1] += 0.002;
	
}
static unsigned char forwardVecIndex;
static unsigned char backwardVecIndex;
static unsigned char leftVecIndex;
static unsigned char rightVecIndex;
void ControlledActorForward(void)
{
	bindActor(getControlledActor());
	forwardVecIndex = bindVel(&FORWARD, SPEED_FORWARD, 180.0);
}
void UnControlledActorForward(void)
{
	bindActor(getControlledActor());
	unBindVel(forwardVecIndex);
	bindActor(0);
}
void ControlledActorBackward(void)
{
	bindActor(getControlledActor());
	backwardVecIndex = bindVel(&FORWARD, SPEED_FORWARD, 0.0);
}
void UnControlledActorBackward(void)
{
	bindActor(getControlledActor());
	unBindVel(backwardVecIndex);
	bindActor(0);
}
void ControlledActorLeft(void)
{
	bindActor(getControlledActor());
	leftVecIndex = bindVel(&FORWARD, SPEED_FORWARD, 270.0);
}
void UnControlledActorLeft(void)
{
	bindActor(getControlledActor());
	unBindVel(leftVecIndex);
	bindActor(0);
}
void ControlledActorRight(void)
{
	bindActor(getControlledActor());
	rightVecIndex = bindVel(&FORWARD, SPEED_FORWARD, 90.0);
}
void UnControlledActorRight(void)
{
	bindActor(getControlledActor());
	unBindVel(rightVecIndex);
	bindActor(0);
}
