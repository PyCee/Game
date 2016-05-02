
#include "directionComponent.h"

#include "../actors.h"
#include <stdio.h>
#include "../math/gMath.h"
#include "../math/angles.h"
#include "physics/vector.h"
#include "physics/physicsAttributeController.h"
#include "../math/quaternion.h"
#include "../actors.h"
#include "physicsComponent.h"
#include "../math/pythag.h"
#include "../math/angles.h"
#include <math.h>
#include <stdlib.h>
#include "direction/rotationController.h"

void initDirectionComponent(void)
{
	XAxis = malloc(sizeof(vec3));
	YAxis = malloc(sizeof(vec3));
	ZAxis = malloc(sizeof(vec3));
	negZAxis = malloc(sizeof(vec3));
	
	i = genVec3(1.0, 0.0, 0.0);
	j = genVec3(0.0, 1.0, 0.0);
	k = genVec3(0.0, 0.0, 1.0);
	nk = genVec3(0.0, 0.0, -1.0);
}
void genDirectionComponent(void)
{
	FORWARD = malloc(sizeof(vec3));
	FORWARDROTATION = malloc(sizeof(vec4));
	*FORWARD = genVec3(0, 0, -1);
	*FORWARDROTATION = UnitQuaternion(genVec3(0, 0, -1), 0);
	
	DIR_ROTATE = malloc(sizeof(rotationController));
	DIR_DELTA_ROTATE = malloc(sizeof(rotationController));
	
	YAW = 0;
	PITCH = 20;
	ROLL = 0;
	DELTA_YAW = 0;
	DELTA_PITCH = 0;
	DELTA_ROLL = 0;
	PAN_TIME = 0;
	setViewState(VIEWSTATE_FREE_ROAM);
}
void freeDirectionComponent(void)
{
	free(FORWARD);
	free(FORWARDROTATION);
}
void updateDirectionComponent(unsigned short deltaMS)
{
	while(YAW > 180)
		YAW -= 360;
	while(YAW < 180)
		YAW += 360;
	PITCH = (PITCH > 85) ? 85 : PITCH;
	PITCH = (PITCH < -1.0 * 45) ? -1.0 * 45 : PITCH;
	
	switch(VIEWSTATE){
	case VIEWSTATE_FREE_ROAM:
		break;
	case VIEWSTATE_LOCK_ON:
		lookAt(VIEW_TARGET);
		break;
	case VIEWSTATE_PAN:
		DELTA_PAN_PROGRESS = deltaMS / (PAN_TIME * 1000);
		PAN_PROGRESS += DELTA_PAN_PROGRESS;
		if(PAN_PROGRESS >= 1){
			PAN_TIME = 0;
			PAN_PROGRESS = 0;
			lookAt(VIEW_TARGET);
			setViewState(VIEWSTATE_LOCK_ON);
		} else
			panView();
		break;
	}
	while(DELTA_YAW > 180)
		DELTA_YAW = 360 - DELTA_YAW;
		
	YAW += DELTA_YAW * deltaMS;
	PITCH += DELTA_PITCH * deltaMS;
	ROLL += DELTA_ROLL * deltaMS;
	
	*FORWARDROTATION = UnitQuaternion(genVec3(0, 0, -1), 0);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(j, -1 * YAW), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(i, -1 * PITCH), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(k, -1 * ROLL), *FORWARDROTATION);
	
	*FORWARD = applyRotationQuaternion(genVec3(0.0, 0.0, -1.0), *FORWARDROTATION);
	
	*FORWARDROTATION = UnitQuaternion(genVec3(0, 0, -1), 0);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(j, 1 * YAW), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(i, 1 * PITCH), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(k, 1 * ROLL), *FORWARDROTATION);
}
void DirectionYaw(float degrees)
{
	YAW += degrees;
}
void DirectionPitch(float degrees)
{
	PITCH += degrees;
}
void DirectionRoll(float degrees)
{
	ROLL += degrees;
}
void setViewState(unsigned char state)
{
	DELTA_YAW = 0;
	DELTA_PITCH = 0;
	DELTA_ROLL = 0;
	
	switch(VIEWSTATE){
		case VIEWSTATE_FREE_ROAM:
			break;
		case VIEWSTATE_LOCK_ON:
			break;
		case VIEWSTATE_PAN:
			PAN_TIME = 0;
			PAN_PROGRESS = 0;
			DELTA_PAN_PROGRESS = 0;
			break;
	}
	
	VIEWSTATE = state;
	
	switch(VIEWSTATE){
		case VIEWSTATE_FREE_ROAM:
			break;
		case VIEWSTATE_LOCK_ON:
			break;
		case VIEWSTATE_PAN:
			break;
	}
}
void lookAt(vec3 *lookAtPos)
{
	*DIR_ROTATE = getRotationToVec3(lookAtPos);
}
void panView(void)
{
	float panTimeRemaining = PAN_TIME * (1.0 - PAN_PROGRESS);
	rotationController rot = getRotationToVec3(VIEW_TARGET);
	float deltaYaw = (rot.yaw - YAW);
	float deltaPitch = (rot.pitch - PITCH);
	float deltaRoll = (rot.roll - ROLL);
	while(deltaYaw > 180)
		deltaYaw = 360 - deltaYaw;
	while(deltaYaw < -1.0 * 180)
		deltaYaw = 360 + deltaYaw;
	DELTA_YAW = deltaYaw / (panTimeRemaining * 1000);
	DELTA_PITCH = (rot.pitch - PITCH) / (panTimeRemaining * 1000);
	DELTA_ROLL = (rot.roll - ROLL) / (panTimeRemaining * 1000);
}
