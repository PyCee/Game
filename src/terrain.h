

#ifndef _TERRAIN_
#define _TERRAIN_

#include <stdint.h>

#define TERRAIN_NAME "TERRAIN"

typedef struct _Dyn_Actor_t Terrain_t;

U8 genTerrain(void);
void UpdateTerrain(U8, U16);

#endif
