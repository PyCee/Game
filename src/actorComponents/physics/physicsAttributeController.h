
#ifndef _PHYSICS_ATTRIBUTE_CONTROLLER_
#define _PHYSICS_ATTRIBUTE_CONTROLLER_

#define ATTRIBUTE_QTY 4
//struct vec3

typedef struct physicsAttributeController {
	struct vec3 *attribute[ATTRIBUTE_QTY];
	float multiplier[ATTRIBUTE_QTY];
	struct vec4 *adjustment[ATTRIBUTE_QTY];
	char active[ATTRIBUTE_QTY];
} physicsAttributeController;

physicsAttributeController genPhysicsAttributeController(void);
void freePhysicsAttributeController(physicsAttributeController *);
unsigned char getOpenAttribute(physicsAttributeController);
unsigned char bindPhysicsAttribute(physicsAttributeController *, struct vec3 *, float, struct vec4 *);
void unBindPhysicsAttribute(physicsAttributeController *, unsigned char);
void Impulse(physicsAttributeController *, struct vec3 *);

#endif /* _PHYSICS_ATTRIBUTE_CONTROLLER_ */
