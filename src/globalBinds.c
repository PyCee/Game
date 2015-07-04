
#include "dataTypes.h"
#include "globalBinds.h"

#include <stdio.h>

#include "camera.h"
#include "actor.h"
#include "globalTimeLine.h"

void BindCameraView
(Camera_t *camera)
{	cameraView = camera;	}
Camera_t *getCameraView
(void)
{	return cameraView;	}
void UnbindCameraView
(void)
{	cameraView = 0;	}
void BindControlledActor
(Actor_t *actor)
{	controlledActor = actor;	}
Actor_t *getControlledActor
(void)
{	return controlledActor;	}
void UnbindControlledActor
(void)
{	controlledActor = 0;	}
void BindMapTerrain
(Actor_t *terrain)
{	mapTerrain = terrain;	}
Actor_t *getMapTerrain
(void)
{	return mapTerrain;	}
void UnbindMapTerrain
(void)
{	mapTerrain = 0;	}
void BindGlobalTimeLine
(globalTimeLine_t *timeLine)
{	globalTimeLine = timeLine;	}
globalTimeLine_t *getGlobalTimeLine
(void)
{	return globalTimeLine;	}
void UnbindGlobalTimeLine
(void)
{	globalTimeLine = 0;	}
