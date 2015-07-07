
#include "../dataTypes.h"
#include "physicsComponent.h"

#include "../dyn_actors.h"

#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../math/vector.h"
#include "../math/matrix.h"

void genPhysicsComponent
(U8 actorID)
{
	printf("Gening physics Component\n");
	genVec3(&(Dyn_Actors.physics[actorID].Pos));
	genVec3(&(Dyn_Actors.physics[actorID].Vel));
	genVec3(&(Dyn_Actors.physics[actorID].Acc));
	genVec3(&(Dyn_Actors.physics[actorID].Jrk));
}
void freePhysicsComponent
(U8 actorID)
{
	// Don't free vectors since they were not dynamically allocated
}

void updatePhysicsComponent
(U8 actorID, U16 deltaMS)
{
	if (actorID == getMapTerrain())
		return;
	*getVecXPtr(&(Dyn_Actors.physics[actorID].Acc)) +=
			deltaMS * getVecX(Dyn_Actors.physics[actorID].Jrk) * 1;
	*getVecYPtr(&(Dyn_Actors.physics[actorID].Acc)) +=
			deltaMS * getVecY(Dyn_Actors.physics[actorID].Jrk) * 1;
	*getVecZPtr(&(Dyn_Actors.physics[actorID].Acc)) +=
			deltaMS * getVecZ(Dyn_Actors.physics[actorID].Jrk) * 1;
	*getVecXPtr(&(Dyn_Actors.physics[actorID].Vel)) +=
			deltaMS * getVecX(Dyn_Actors.physics[actorID].Acc) * 1;
	*getVecYPtr(&(Dyn_Actors.physics[actorID].Vel)) +=
			deltaMS * (getVecY(Dyn_Actors.physics[actorID].Acc) * 1 - ACC_GRAVITY);
	*getVecZPtr(&(Dyn_Actors.physics[actorID].Vel)) +=
			deltaMS * getVecZ(Dyn_Actors.physics[actorID].Acc) * 1;
	*getVecXPtr(&(Dyn_Actors.physics[actorID].Pos)) +=
			deltaMS * getVecX(Dyn_Actors.physics[actorID].Vel) * 1;
	*getVecYPtr(&(Dyn_Actors.physics[actorID].Pos)) +=
			deltaMS * getVecY(Dyn_Actors.physics[actorID].Vel) * 1;
	*getVecZPtr(&(Dyn_Actors.physics[actorID].Pos)) +=
			deltaMS * getVecZ(Dyn_Actors.physics[actorID].Vel) * 1;
}
void			setSpeed			(U8 actorID, U8 speed)		{		Dyn_Actors.physics[actorID].Speed = speed;			}

F64		*		getPosXPtr		(U8 actorID)		{		return getVecXPtr(&(Dyn_Actors.physics[actorID].Pos));		}
F64		*		getPosYPtr		(U8 actorID)		{		return getVecYPtr(&(Dyn_Actors.physics[actorID].Pos));		}
F64 	*		getPosZPtr		(U8 actorID)		{		return getVecZPtr(&(Dyn_Actors.physics[actorID].Pos));		}
F64				getPosX				(U8 actorID)		{		return getVecX(Dyn_Actors.physics[actorID].Pos);					}
F64				getPosY				(U8 actorID)		{		return getVecY(Dyn_Actors.physics[actorID].Pos);					}
F64				getPosZ				(U8 actorID)		{		return getVecZ(Dyn_Actors.physics[actorID].Pos);					}

F64		*		getVelXPtr		(U8 actorID)		{		return getVecXPtr(&(Dyn_Actors.physics[actorID].Vel));		}
F64		*		getVelYPtr		(U8 actorID)		{		return getVecYPtr(&(Dyn_Actors.physics[actorID].Vel));		}
F64 	*		getVelZPtr		(U8 actorID)		{		return getVecZPtr(&(Dyn_Actors.physics[actorID].Vel));		}
F64				getVelX				(U8 actorID)		{		return getVecX(Dyn_Actors.physics[actorID].Vel);					}
F64				getVelY				(U8 actorID)		{		return getVecY(Dyn_Actors.physics[actorID].Vel);					}
F64				getVelZ				(U8 actorID)		{		return getVecZ(Dyn_Actors.physics[actorID].Vel);					}

F64		*		getAccXPtr		(U8 actorID)		{		return getVecXPtr(&(Dyn_Actors.physics[actorID].Acc));		}
F64		*		getAccYPtr		(U8 actorID)		{		return getVecYPtr(&(Dyn_Actors.physics[actorID].Acc));		}
F64 	*		getAccZPtr		(U8 actorID)		{		return getVecZPtr(&(Dyn_Actors.physics[actorID].Acc));		}
F64				getAccX				(U8 actorID)		{		return getVecX(Dyn_Actors.physics[actorID].Acc);					}
F64				getAccY				(U8 actorID)		{		return getVecY(Dyn_Actors.physics[actorID].Acc);					}
F64				getAccZ				(U8 actorID)		{		return getVecZ(Dyn_Actors.physics[actorID].Acc);					}

F64		*		getJrkXPtr		(U8 actorID)		{		return getVecXPtr(&(Dyn_Actors.physics[actorID].Jrk));		}
F64		*		getJrkYPtr		(U8 actorID)		{		return getVecYPtr(&(Dyn_Actors.physics[actorID].Jrk));		}
F64 	*		getJrkZPtr		(U8 actorID)		{		return getVecZPtr(&(Dyn_Actors.physics[actorID].Jrk));		}
F64				getJrkX				(U8 actorID)		{		return getVecX(Dyn_Actors.physics[actorID].Jrk);					}
F64				getJrkY				(U8 actorID)		{		return getVecY(Dyn_Actors.physics[actorID].Jrk);					}
F64				getJrkZ				(U8 actorID)		{		return getVecZ(Dyn_Actors.physics[actorID].Jrk);					}
