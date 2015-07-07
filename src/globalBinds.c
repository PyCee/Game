
#include "dataTypes.h"
#include "globalBinds.h"

#include <stdio.h>

#include "camera.h"
#include "dyn_actors.h"
#include "globalTimeLine.h"

void BindCameraView
(U8 camera)
{	cameraView = camera;	}
U8 getCameraView
(void)
{	return cameraView;	}
void UnbindCameraView
(void)
{	cameraView = MAX_ACTOR_COUNT;	}
void BindControlledActor
(U8 protag)
{	controlledActor = protag;	}
U8 getControlledActor
(void)
{	return controlledActor;	}
void UnbindControlledActor
(void)
{	controlledActor = MAX_ACTOR_COUNT;	}
void BindMapTerrain
(U8 terrain)
{	mapTerrain = terrain;	}
U8 getMapTerrain
(void)
{	return mapTerrain;	}
void UnbindMapTerrain
(void)
{	mapTerrain = MAX_ACTOR_COUNT;	}
void BindGlobalTimeLine
(globalTimeLine_t *timeLine)
{	globalTimeLine = timeLine;	}
globalTimeLine_t *getGlobalTimeLine
(void)
{	return globalTimeLine;	}
void UnbindGlobalTimeLine
(void)
{	globalTimeLine = NULL;	}
