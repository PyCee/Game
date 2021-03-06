#include "distanceCheck.h"
#include "callbackController.h"
#include "../../actors.h"
#include "../physicsComponent.h"

#include <stdio.h>
#include "../physics/vector.h"
#include "../physics/collisionController.h"
#include "../physics/collisionTypes/collisionCapsule.h"
#include "../physics/collisionTypes/collisionSphere.h"
#include "../physics/physicsAttributeController.h"

callbackController genDistanceCheck(void (*complete)(callbackController), float dis, vec3 *poi)
{
	callbackController call;
	float dist[] = {dis};
	vec3 vec[] = {*poi};
	call = genCallbackController(shouldDistanceCheck, complete);
	callbackControllerElement(&call, vec, 1, CALLBACK_VEC3);
	callbackControllerElement(&call, dist, 1, CALLBACK_FLOAT);
	return call;
}
char shouldDistanceCheck(callbackController call)
{
	collisionController cap = genCollisionCapsule(PREVIOUSPOSITION, POSITION, 0.001);
	collisionController sph = genCollisionSphere(&(call._vec3[0]), call._float[0]);
	return collisionCapsuleSphere(cap, sph);
}
