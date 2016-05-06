
#ifndef CAPSULE
#define CAPSULE

typedef struct capsule{
	struct vec3 *point[2];
	float radius;
} capsule;

capsule genCapsule(struct vec3 *, struct vec3 *, float);
void freeCap(capsule *);

unsigned char collisionCapsuleCapsule(capsule, capsule);

#endif /* CAPSULE */
