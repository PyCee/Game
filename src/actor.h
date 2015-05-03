
#ifndef _CHARACTER_
#define _CHARACTER_

#include "physics.h"
#include <stdint.h>

typedef struct _Actor_t
{
	void (*Update)(struct _Actor_t *, uint64_t);
	unsigned char Control;
	Physics_t *physics;
} Actor_t;

void genActor(Actor_t **);
void freeActor(Actor_t **);

void setBounds(Actor_t *, double, double);
void Update(Actor_t *, uint64_t);

void UselessUpdate(Actor_t *, uint64_t);

char CheckBoundingBoxCollision(Actor_t *, Actor_t *);

void Move(Actor_t *, double, double);
void setPos(Actor_t *, double, double);

#endif
