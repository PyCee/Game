#include "rayTrace.h"
#include "collisionController.h"
#include "collisionTypes/collisionPlane.h"
#include "vector.h"
#include <stdlib.h>

rayTrace genRayTrace(void)
{
	rayTrace ray;
	ray.origin = 0;
	ray.direction = 0;
	return ray;
}
void freeRayTrace(rayTrace *ray)
{
	if(ray->origin)
		free(ray->origin);
	ray->origin = 0;
	if(ray->direction)
		free(ray->direction);
	ray->direction = 0;
}
rayTraceHit genRayTraceHit(void)
{
	rayTraceHit hit;
	hit.ray = 0;
	hit.delta = 0;
	return hit;
}
void freeRayTraceHit(rayTraceHit *hit)
{
}
rayTraceHit *rayTracePlane(rayTrace *trace, collisionController pla)//TODO: TEST
{
	rayTraceHit *hit;
	
	float planeDist = dotProduct(*pla.PLANE_NORMAL, *trace->origin) + pla.PLANE_D;
	float projLineLength = dotProduct(*pla.PLANE_NORMAL, *trace->direction);
	if(projLineLength == 0) return 0;
	
	hit = malloc(sizeof(rayTraceHit));
	*hit = genRayTraceHit();
	hit->ray = trace;
	hit->delta = planeDist / projLineLength;
	
	return hit;
}
