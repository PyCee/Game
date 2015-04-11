
#ifndef _CHARACTER_
#define _CHARACTER_

#include <stdlib.h>
#include <stdint.h>
#include "physics.h"

typedef struct _Character_t
{
	void (*Update)(struct _Character_t *, uint64_t);
	char Control;
	Physics_t physics;
} Character_t;

void setBounds(Character_t *, double, double);
void Update(Character_t *, uint64_t);

void UselessUpdate(Character_t *, uint64_t);

char CheckBoundingBoxCollision(Character_t *, Character_t *);

void Move(Character_t *, double, double);
void setPos(Character_t *, double, double);

#endif
