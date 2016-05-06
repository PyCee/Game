
#ifndef SPHERE
#define SPHERE

typedef struct sphere{
	struct vec3 *point;
	float radius;
} sphere;

sphere genSphere(struct vec3 *, float);
void freeSphere(sphere *);

unsigned char collisionSphereSphere(sphere, sphere);

#endif /* SPHERE */
