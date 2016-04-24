#include "applyImpulses.h"

#include "../../actors.h"
#include "../physicsComponent.h"
#include "physicsAttributeController.h"
#include "vector.h"
#include "../../math/quaternion.h"

void applyPhysicsImpulses(void)
{
	applyImpulse(POS);
	applyImpulse(VEL);
	applyImpulse(ACC);
	applyImpulse(JRK);
}
