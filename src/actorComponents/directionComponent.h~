
#ifndef _DIRECTION_COMPONENT_
#define _DIRECTION_COMPONENT_

#include "physics/vector.h"
#include "direction/normal.h"

typedef struct _DirectionComponent_t{
	Normal_t forward;
} DirectionComponent_t;

void		genDirectionComponent				(U8);
void		freeDirectionComponent			(U8);
void		updateDirectionComponent		(U8, U16);

void		DirectionPitch							(U8, F32);
void		DirectionYaw								(U8, F32);
void		DirectionRoll								(U8, F32);
#endif /* _DIRECTION_COMPONENT_ */
