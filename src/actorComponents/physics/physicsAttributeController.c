
#include "physicsAttributeController.h"

#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "../../math/quaternion.h"

physicsAttributeController genPhysicsAttributeController(void)
{
	physicsAttributeController controller;
	
	controller.attribute[0] = malloc(sizeof(vec3));
	*(controller.attribute[0]) = genVec3(0.0, 0.0, 0.0);
	controller.multiplier[0] = 1;
	controller.adjustment[0] = malloc(sizeof(vec4));
	*(controller.adjustment[0]) = UnitQuaternion(genVec3(1, 0, 0), 0);
	controller.active[0] = 1;
	
	unsigned char att;
	for(att = 1; att < ATTRIBUTE_QTY; att++)
		unBindPhysicsAttribute(&controller, att);
	
	return controller;
}
void freePhysicsAttributeController(physicsAttributeController *controller)
{
	free(controller->attribute[0]);
	free(controller->adjustment[0]);
}
unsigned char getOpenAttribute(physicsAttributeController controller)
{
	unsigned char att;
	for(att = 1; att < ATTRIBUTE_QTY; att++)
		if(!(controller.attribute[att]))
			return att;
	return 1;
}
unsigned char bindPhysicsAttribute(physicsAttributeController *controller, vec3 *dir, float mult, vec4 *adj)
{
	unsigned char att = getOpenAttribute(*controller);
	controller->attribute[att] = dir;
	controller->multiplier[att] = mult;
	controller->adjustment[att] = adj;
	controller->active[att] = 1;
	return att;
}
void unBindPhysicsAttribute(physicsAttributeController *controller, unsigned char att)
{
	controller->attribute[att] = 0;
	controller->multiplier[att] = 0;
	controller->adjustment[att] = 0;
	controller->active[att] = 0;
}
void Impulse(physicsAttributeController *controller, vec3 *impulse)
{
	*(controller->attribute[0]) = addVec3(*(controller->attribute[0]), *impulse);
}
