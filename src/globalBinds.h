
#ifndef _GLOBAL_BINDS_
#define _GLOBAL_BINDS_

typedef struct _Actor_t Camera_t;
typedef struct _Actor_t Actor_t;
typedef struct _globalTimeLine_t globalTimeLine_t;

static Camera_t *cameraView;
void BindCameraView(Camera_t *);
Camera_t *getCameraView(void);
void UnbindCameraView(void);

static Actor_t *controlledActor;
void BindControlledActor(Actor_t *);
Actor_t *getControlledActor(void);
void UnbindControlledActor(void);

static Actor_t *mapTerrain;
void BindMapTerrain(Actor_t *);
Actor_t *getMapTerrain(void);
void UnbindMapTerrain(void);

static globalTimeLine_t *globalTimeLine;
void BindGlobalTimeLine(globalTimeLine_t *);
globalTimeLine_t *getGlobalTimeLine(void);
void UnbindGlobalTimeLine(void);

#endif /* _GLOBAL_BINDS */
