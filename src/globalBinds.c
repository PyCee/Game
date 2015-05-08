
#include "globalBinds.h"

#include <stdio.h>

#include "camera.h"
#include "actor.h"

void BindCameraView
(Camera_t *camera)
{	cameraView = camera;	}
Camera_t *GetCameraView
(void)
{	return cameraView;	}
void UnbindCameraView
(void)
{	cameraView = 0;	}
void BindControlledActor
(Actor_t *actor)
{	controlledActor = actor;	}
Actor_t *GetControlledActor
(void)
{	return controlledActor;	}
void UnbindControlledActor
(void)
{	controlledActor = 0;	}
void BindMapTerrain
(Actor_t *terrain)
{	mapTerrain = terrain;	}
Actor_t *GetMapTerrain
(void)
{	return mapTerrain;	}
void UnbindMapTerrain
(void)
{	mapTerrain = 0;	}
