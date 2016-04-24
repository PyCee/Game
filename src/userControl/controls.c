#include "controls.h"

#include "../actors.h"
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "../actorSelection.h"
#include "../actorComponents/physics/physicsAttributeController.h"
#include "../math/quaternion.h"

#include "../actorComponents/directionComponent.h"
#include "../actorComponents/physicsComponent.h"
#include "../actorComponents/physics/applyImpulses.h"

void ControlledActorJump(void)
{
	printf("Jump Called\n\n\n\n\n\n");
	bindActor(getControlledActor());
	vec3 *jump = malloc(sizeof(vec3));
	*jump = genVec3(0.0, 0.003, 0.0);
	impulse(VEL, jump);
	free(jump);
	
}
static unsigned char forwardVecIndex;
static unsigned char backwardVecIndex;
static unsigned char leftVecIndex;
static unsigned char rightVecIndex;
vec4 forwardRot;
vec4 backwardRot;
vec4 leftRot;
vec4 rightRot;
void ControlledActorForward(void)
{
	forwardRot = UnitQuaternion(j, 0);
	bindActor(getControlledActor());
	forwardVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED, &forwardRot);
	bindActor(getCameraView());
	forwardVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED, &forwardRot);
}
void UnControlledActorForward(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, forwardVecIndex);
	bindActor(getCameraView());
	unBindPhysicsAttribute(VEL, forwardVecIndex);
	bindActor(0);
}
void ControlledActorBackward(void)
{
	backwardRot = UnitQuaternion(j, 180);
	bindActor(getControlledActor());
	backwardVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED * SPEED_BACK, &backwardRot);
	bindActor(getCameraView());
	backwardVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED * SPEED_BACK, &backwardRot);
}
void UnControlledActorBackward(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, backwardVecIndex);
	bindActor(getCameraView());
	unBindPhysicsAttribute(VEL, backwardVecIndex);
	bindActor(0);
}
void ControlledActorLeft(void)
{
	leftRot = UnitQuaternion(j, 90);
	bindActor(getControlledActor());
	leftVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED * SPEED_SIDE, &leftRot);
	bindActor(getCameraView());
	leftVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED * SPEED_SIDE, &leftRot);
}
void UnControlledActorLeft(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, leftVecIndex);
	bindActor(getCameraView());
	unBindPhysicsAttribute(VEL, leftVecIndex);
	bindActor(0);
}
void ControlledActorRight(void)
{
	rightRot = UnitQuaternion(j, 270);
	bindActor(getControlledActor());
	rightVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED * SPEED_SIDE, &rightRot);
	bindActor(getCameraView());
	rightVecIndex = bindPhysicsAttribute(VEL, FORWARD, SPEED * SPEED_SIDE, &rightRot);
}
void UnControlledActorRight(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, rightVecIndex);
	bindActor(getCameraView());
	unBindPhysicsAttribute(VEL, rightVecIndex);
	bindActor(0);
}
void ToggleLockOn(void)
{
	bindActor(3);// TODO cl
	vec3 *pos = POSITION;
	bindActor(getControlledActor());
	VIEW_TARGET = pos;
	if(VIEWSTATE == VIEWSTATE_FREE_ROAM){
		setViewState(VIEWSTATE_PAN);
		PAN_TIME = 0.7;
	}
	else
		setViewState(VIEWSTATE_FREE_ROAM);
	//VIEWSTATE = (VIEWSTATE == VIEWSTATE_FREE_ROAM) ? VIEWSTATE_LOCK_ON : VIEWSTATE_FREE_ROAM;
	bindActor(getCameraView());
	VIEW_TARGET = pos;
	if(VIEWSTATE == VIEWSTATE_FREE_ROAM){
		setViewState(VIEWSTATE_PAN);
		PAN_TIME = 0.7;
	}
	else
		setViewState(VIEWSTATE_FREE_ROAM);
	//VIEWSTATE = (VIEWSTATE == VIEWSTATE_FREE_ROAM) ? VIEWSTATE_LOCK_ON : VIEWSTATE_FREE_ROAM;
}
