
#ifndef _PHYSICS_ATTRIBUTE_CONTROLLER_
#define _PHYSICS_ATTRIBUTE_CONTROLLER_


typedef struct physicsAttributeController {
	struct vec3 **attribute;
	float *multiplier;
	struct vec4 **adjustment;
	unsigned char *active;
	unsigned char attributeNum;
	struct vec3 *impulse;
} physicsAttributeController;

physicsAttributeController genPhysicsAttributeController(unsigned char);
void freePhysicsAttributeController(physicsAttributeController *);
unsigned char getOpenAttribute(physicsAttributeController);
unsigned char bindPhysicsAttribute(physicsAttributeController *, struct vec3 *, float, struct vec4 *);
void unBindPhysicsAttribute(physicsAttributeController *, unsigned char);
void applyImpulse(physicsAttributeController *);
void impulse(physicsAttributeController *, struct vec3 *);

#endif /* _PHYSICS_ATTRIBUTE_CONTROLLER_ */
