
#include "protag.h"

#include "actors.h"
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "actorSelection.h"
#include "actorComponents/physics/physicsAttributeController.h"
#include "math/quaternion.h"

#include "actorComponents/directionComponent.h"
#include "actorComponents/physicsComponent.h"

void UpdateProtag(unsigned short deltaMS)
{
	printf("updating protag\n");
}
void Jump(void)
{
	printf("Jump Called\n\n\n\n\n\n");
	bindActor(getControlledActor());
	vec3 *jump = malloc(sizeof(vec3));
	*jump = genVec3(0.0, 0.003, 0.0);
	Impulse(VEL, jump);
	free(jump);
	
}
static unsigned char forwardVecIndex;
static unsigned char backwardVecIndex;
static unsigned char leftVecIndex;
static unsigned char rightVecIndex;
static vec4 forwardRot;
static vec4 backwardRot;
static vec4 leftRot;
static vec4 rightRot;
void ControlledActorForward(void)
{
	forwardRot = UnitQuaternion(j, 180);
	bindActor(getControlledActor());
	forwardVecIndex = bindPhysicsAttribute(VEL, &FORWARD, SPEED_FORWARD, &forwardRot);
}
void UnControlledActorForward(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, forwardVecIndex);
	bindActor(0);
}
void ControlledActorBackward(void)
{
	backwardRot = UnitQuaternion(j, 0);
	bindActor(getControlledActor());
	backwardVecIndex = bindPhysicsAttribute(VEL, &FORWARD, SPEED_FORWARD, &backwardRot);
}
void UnControlledActorBackward(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, backwardVecIndex);
	bindActor(0);
}
void ControlledActorLeft(void)
{
	leftRot = UnitQuaternion(j, 270);
	bindActor(getControlledActor());
	leftVecIndex = bindPhysicsAttribute(VEL, &FORWARD, SPEED_FORWARD, &leftRot);
}
void UnControlledActorLeft(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, leftVecIndex);
	bindActor(0);
}
void ControlledActorRight(void)
{
	rightRot = UnitQuaternion(j, 90);
	bindActor(getControlledActor());
	rightVecIndex = bindPhysicsAttribute(VEL, &FORWARD, SPEED_FORWARD, &rightRot);
}
void UnControlledActorRight(void)
{
	bindActor(getControlledActor());
	unBindPhysicsAttribute(VEL, rightVecIndex);
	bindActor(0);
}
