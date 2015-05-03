
#include "globalBinds.h"

#include <stdio.h>
#include "actor.h"


void BindCameraView
(Camera_t *camera)
{	cameraView = camera;	}
Camera_t *GetCameraView
()
{	return cameraView;	}
void UnbindCameraView
()
{	cameraView = 0;	}
void BindMapTerrain
(Actor_t *terrain)
{	mapTerrain = terrain;	}
Actor_t *GetMapTerrain
()
{	return mapTerrain;	}
void UnbindMapTerrain
()
{	mapTerrain = 0;	}
void BindControlledActor
(Actor_t *actor)
{	controlledActor = actor;	}
Actor_t *GetControlledActor
()
{	return controlledActor;	}
void UnbindControlledActor
()
{	controlledActor = 0;	}
