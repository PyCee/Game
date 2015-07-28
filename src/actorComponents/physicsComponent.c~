
#include "../dataTypes.h"
#include "physicsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "physics/vector.h"

void genPhysicsComponent
(U8 actorID)
{
	genVector(&(Actors.physics[actorID].Pos), 0, 0, 0);
	genVector(&(Actors.physics[actorID].Vel), 0, 0, 0);
	genVector(&(Actors.physics[actorID].Acc), 0, 0, 0);
	genVector(&(Actors.physics[actorID].Jrk), 0, 0, 0);
}
void freePhysicsComponent
(U8 actorID)
{
	// Don't free vectors since they were not dynamically allocated
}

void updatePhysicsComponent
(U8 actorID, U16 deltaMS)
{
	setAccX(actorID, getAccX(actorID) + (deltaMS * getJrkX(actorID) * 1));
	setAccY(actorID, getAccY(actorID) + (deltaMS * getJrkY(actorID) * 1));
	setAccZ(actorID, getAccZ(actorID) + (deltaMS * getJrkZ(actorID) * 1));
	
	setVelX(actorID, getVelX(actorID) + (deltaMS * getAccX(actorID) * 1));
	setVelY(actorID, getVelY(actorID) + (deltaMS * (getAccY(actorID) * 1 - ACC_GRAVITY)));
	setVelZ(actorID, getVelZ(actorID) + (deltaMS * getAccZ(actorID) * 1));
	
	setPosX(actorID, getPosX(actorID) + (deltaMS * getVelX(actorID) * 1));
	setPosY(actorID, getPosY(actorID) + (deltaMS * getVelY(actorID) * 1));
	setPosZ(actorID, getPosZ(actorID) + (deltaMS * getVelZ(actorID) * 1));
}
void setSpeed			(U8 actorID, U8 speed)		{		Actors.physics[actorID].Speed = speed;			}

void setPosX		(U8 actorID, F32 set)		{		setVectorX(&(Actors.physics[actorID].Pos), set);				}
void setPosY		(U8 actorID, F32 set)		{		setVectorY(&(Actors.physics[actorID].Pos), set);				}
void setPosZ		(U8 actorID, F32 set)		{		setVectorZ(&(Actors.physics[actorID].Pos), set);				}
F32			getPosX		(U8 actorID)						{		return getVectorX(Actors.physics[actorID].Pos);					}
F32			getPosY		(U8 actorID)						{		return getVectorY(Actors.physics[actorID].Pos);					}
F32			getPosZ		(U8 actorID)						{		return getVectorZ(Actors.physics[actorID].Pos);					}

void		setVelX		(U8 actorID, F32 set)		{		setVectorX(&(Actors.physics[actorID].Vel), set);				}
void		setVelY		(U8 actorID, F32 set)		{		setVectorY(&(Actors.physics[actorID].Vel), set);				}
void		setVelZ		(U8 actorID, F32 set)		{		setVectorZ(&(Actors.physics[actorID].Vel), set);				}
F32			getVelX		(U8 actorID)						{		return getVectorX(Actors.physics[actorID].Vel);					}
F32			getVelY		(U8 actorID)						{		return getVectorY(Actors.physics[actorID].Vel);					}
F32			getVelZ		(U8 actorID)						{		return getVectorZ(Actors.physics[actorID].Vel);					}

void		setAccX		(U8 actorID, F32 set)		{		setVectorX(&(Actors.physics[actorID].Acc), set);				}
void		setAccY		(U8 actorID, F32 set)		{		setVectorY(&(Actors.physics[actorID].Acc), set);				}
void		setAccZ		(U8 actorID, F32 set)		{		setVectorZ(&(Actors.physics[actorID].Acc), set);				}
F32			getAccX		(U8 actorID)						{		return getVectorX(Actors.physics[actorID].Acc);					}
F32			getAccY		(U8 actorID)						{		return getVectorY(Actors.physics[actorID].Acc);					}
F32			getAccZ		(U8 actorID)						{		return getVectorZ(Actors.physics[actorID].Acc);					}

void		setJrkX		(U8 actorID, F32 set)		{		setVectorX(&(Actors.physics[actorID].Jrk), set);				}
void		setJrkY		(U8 actorID, F32 set)		{		setVectorY(&(Actors.physics[actorID].Jrk), set);				}
void		setJrkZ		(U8 actorID, F32 set)		{		setVectorZ(&(Actors.physics[actorID].Jrk), set);				}
F32			getJrkX		(U8 actorID)						{		return getVectorX(Actors.physics[actorID].Jrk);					}
F32			getJrkY		(U8 actorID)						{		return getVectorY(Actors.physics[actorID].Jrk);					}
F32			getJrkZ		(U8 actorID)						{		return getVectorZ(Actors.physics[actorID].Jrk);					}
