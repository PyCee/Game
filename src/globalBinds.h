
#ifndef _GLOBAL_BINDS_
#define _GLOBAL_BINDS_

typedef struct _Camera_t Camera_t;
typedef struct _Actor_t Actor_t;

static Camera_t *cameraView;
void BindCameraView(Camera_t *);
Camera_t *GetCameraView();
void UnbindCameraView();

static Actor_t *mapTerrain;
void BindMapTerrain(Actor_t *);
Actor_t *GetMapTerrain();
void UnbindMapTerrain();

static Actor_t *controlledActor;
void BindControlledActor(Actor_t *);
Actor_t *GetControlledActor();
void UnbindControlledActor();

#endif
