

#ifndef _GRUEL_
#define _GRUEL_

#include <stdint.h>

#define GRUEL_SPEED 0.0015

typedef struct _Actor_t Actor_t;

void genGruel(Actor_t **);
void freeGruel(Actor_t **);
void UpdateGruel(Actor_t *, uint64_t);

#endif
