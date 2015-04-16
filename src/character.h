
#ifndef _CHARACTER_
#define _CHARACTER_

#include "physics.h"

typedef struct _Character_t
{
	void (*Update)(struct _Character_t *, uint64_t);
	unsigned char Control;
	Physics_t *physics;
} Character_t;

void genCharacter(Character_t **);
void freeCharacter(Character_t **);

void setBounds(Character_t *, double, double);
void Update(Character_t *, uint64_t);

void UselessUpdate(Character_t *, uint64_t);

char CheckBoundingBoxCollision(Character_t *, Character_t *);

void Move(Character_t *, double, double);
void setPos(Character_t *, double, double);

#endif
