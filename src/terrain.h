

#ifndef _TERRAIN_
#define _TERRAIN_

#include <stdint.h>

typedef struct _Actor_t Actor_t;

void genTerrain(Actor_t **);
void UpdateTerrain(Actor_t *, uint64_t);

#endif
