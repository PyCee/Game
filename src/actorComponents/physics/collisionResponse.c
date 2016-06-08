#include "collisionResponse.h"

#include "collisionData.h"
#include "vector.h"
#include "../physicsComponent.h"
#include "../../actors.h"
#include "physicsAttributeController.h"

void collisionResponse(collisionData data)
{
	vec3 remainingVelocity = subtractVec3Vec3(*POSITION, *data.validActorPosition);
	float normalScale = dotProduct(*data.normal, remainingVelocity);
	vec3 newPosition = subtractVec3Vec3(*POSITION, scaleVec3(*data.normal, normalScale));
}
