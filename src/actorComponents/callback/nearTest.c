#include "nearTest.h"
#include "callbackController.h"
#include "../../actors.h"
#include "../physicsComponent.h"

#include <stdio.h>
#include "../physics/vector.h"
#include "../physics/physicsAttributeController.h"

callbackController genNearTest(void (*complete)(callbackController), float dis, vec3 *poi)
{
	callbackController call;
	float dist[] = {dis};
	vec3 vec[] = {*poi};
	call = genCallbackController(shouldNearTest, complete);
	callbackControllerElement(&call, vec, 1, CALLBACK_VEC3);
	callbackControllerElement(&call, dist, 1, CALLBACK_FLOAT);
	return call;
}
char shouldNearTest(callbackController call)
{
	printf("should near test\n");
	vec3 diff = subtractVec3Vec3(*POSITION, call._vec3[0]);
	float distance = diff.vec[0] * diff.vec[0] + diff.vec[1] * diff.vec[1] + diff.vec[2] * diff.vec[2];
	float aws = call._float[0];
	if(distance <= call._float[0] * call._float[0])
		return 1;
	return 0;
}
