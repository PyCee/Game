#ifndef RAY_TRACE
#define RAY_TRACE

struct collisionController;
struct vec3;

typedef struct rayTrace{
	struct vec3 *origin, *direction;
} rayTrace;

typedef struct rayTraceHit{
	rayTrace *ray;
	float delta;
} rayTraceHit;

rayTrace genRayTrace(void);
void freeRayTrace(rayTrace *);
rayTraceHit genRayTraceHit(void);
void freeRayTraceHit(rayTraceHit *);
rayTraceHit *rayTracePlane(rayTrace *, struct collisionController);

#endif /* RAY_TRACE */
