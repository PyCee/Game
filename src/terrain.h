

#ifndef _TERRAIN_
#define _TERRAIN_

#include <stdint.h>

typedef struct _Character_t Character_t;

void genTerrain(Character_t **);
void UpdateTerrain(Character_t *, uint64_t deltaMS);

#endif
