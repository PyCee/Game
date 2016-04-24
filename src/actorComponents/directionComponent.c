
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
#include "direction/rotation.h"

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
void genDirectionComponent() {
	FORWARD = malloc(sizeof(vec3));
	FORWARDROTATION = malloc(sizeof(vec4));
	*FORWARD = genVec3(0, 0, -1);
	*FORWARDROTATION = UnitQuaternion(genVec3(0, 0, -1), 0);
	
	DIR_ROTATE = malloc(sizeof(rotation));
	DIR_PREV_ROTATE = malloc(sizeof(rotation));
	DIR_DELTA_ROTATE = malloc(sizeof(rotation));
	
	YAW = 0;
	PITCH = 20;
	ROLL = 0;
	DELTA_YAW = 0;
	DELTA_PITCH = 0;
	DELTA_ROLL = 0;
	PAN_TIME = 0;
	setViewState(VIEWSTATE_FREE_ROAM);
}
void freeDirectionComponent() {
	free(FORWARD);
	free(FORWARDROTATION);
}
void updateDirectionComponent(unsigned short deltaMS)
{
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
	YAW += DELTA_YAW * deltaMS;
	PITCH += DELTA_PITCH * deltaMS;
	ROLL += DELTA_ROLL * deltaMS;
	
	printf("view state = %d\n", VIEWSTATE);
	
	*FORWARDROTATION = UnitQuaternion(genVec3(0, 0, -1), 0);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(j, -1 * YAW), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(i, -1 * PITCH), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(k, -1 * ROLL), *FORWARDROTATION);
	
	*FORWARD = applyRotationQuaternion(genVec3(0.0, 0.0, -1.0), *FORWARDROTATION);
	
	*FORWARDROTATION = UnitQuaternion(genVec3(0, 0, -1), 0);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(j, 1 * YAW), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(i, 1 * PITCH), *FORWARDROTATION);
	*FORWARDROTATION = QuatMultiply(UnitQuaternion(k, 1 * ROLL), *FORWARDROTATION);
	
	PREV_YAW = YAW;
	PREV_PITCH = PITCH;
	PREV_ROLL = ROLL;
}
void DirectionYaw(float degrees) {
	YAW += degrees;
}
void DirectionPitch(float degrees) {
	PITCH += degrees;
}
void DirectionRoll(float degrees) {
	ROLL += degrees;
}
void setViewState(unsigned char state)
{
	
	DELTA_YAW = 0;
	DELTA_PITCH = 0;
	DELTA_ROLL = 0;
	
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
	vec3 difference = addVec3Vec3(*lookAtPos, scaleVec3(*POSITION, -1));
	difference = normalizeVec3(difference);
	if(difference.vec[0] == 0){
		YAW = 0;
	} else{
		vec3 yawDifference = genVec3(difference.vec[0], 0.0, difference.vec[2]);
		yawDifference = normalizeVec3(yawDifference);
		YAW = acos(dotVec3(yawDifference, nk));
		YAW = RadiansToDegrees(YAW);
		
		YAW += (YAW > 180) ? -1 * 360 : 0;
		YAW += (YAW < -1.0 * 180) ? 360 : 0;
		
		if(POSITION->vec[0] > lookAtPos->vec[0])
			YAW *= -1.0;
	}
	if(difference.vec[1] == 0){
		PITCH = 0;
	} else{
		vec3 pitchDifference = genVec3(difference.vec[0], 0.0, difference.vec[2]);
		pitchDifference = normalizeVec3(pitchDifference);
		
		vec3 cross = crossProduct(pitchDifference, difference);
		PITCH = asin(cross.vec[0] * cross.vec[0] + cross.vec[1] * cross.vec[1] + cross.vec[2] * cross.vec[2]);
		PITCH = RadiansToDegrees(PITCH);
		PITCH += (PITCH > 180) ? -1 * 360 : 0;
		PITCH += (PITCH < -1.0 * 180) ? 360 : 0;
		if(POSITION->vec[1] < lookAtPos->vec[1])
			PITCH *= -1.0;
	}
	ROLL = 0;
	
}
void panView(void)
{
	float panTimeRemaining = PAN_TIME - (PAN_PROGRESS * PAN_TIME);
	lookAt(VIEW_TARGET);
	DELTA_YAW = (YAW - PREV_YAW) / (panTimeRemaining * 1000);
	YAW = PREV_YAW;
	DELTA_PITCH = (PITCH - PREV_PITCH) / (panTimeRemaining * 1000);
	PITCH = PREV_PITCH;
	DELTA_ROLL = (ROLL - PREV_ROLL) / (panTimeRemaining * 1000);
	ROLL = PREV_ROLL;
}
