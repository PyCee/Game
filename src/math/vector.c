
#include "vector.h"

#include "gMath.h"
#include <stdlib.h>
#include <stdio.h>

void genVec3
(Vec3_t **vec3)
{
	*vec3 = malloc(sizeof(Vec3_t));
	Vec3_t *_vec3 = *vec3;
	_vec3->X = 0;
	_vec3->Y = 0;
	_vec3->Z = 0;
	_vec3->mag = 1;
}
void genVec2
(Vec2_t **vec2)
{
	*vec2 = malloc(sizeof(Vec2_t));
	Vec2_t *_vec2 = *vec2;
	_vec2->X = 0;
	_vec2->Y = 0;
	_vec2->mag = 1;
}

void freeVec3
(Vec3_t **vec3)
{
	free(*vec3);
}
void freeVec2
(Vec2_t **vec2)
{
	free(*vec2);
}
void NormalizeVec3
(Vec3_t *vec3)
{
	double change = PythagoreanTheoremDim3(vec3->X, vec3->Y, vec3->Z);
	if (change == 0)
		vec3->mag = 1;
	else
	{
	vec3->X = vec3->X / change;
	vec3->Y = vec3->Y / change;
	vec3->Z = vec3->Z / change;
	vec3->mag = vec3->mag * change;
	}
}
void NormalizeVec2
(Vec2_t *vec2)
{
	double change = PythagoreanTheoremDim2(vec2->X, vec2->Y);
	if (change == 0)
	{
		vec2->mag = 1;
	}
	vec2->X = vec2->X / change;
	vec2->Y = vec2->Y / change;
	vec2->mag = vec2->mag * change;
}
