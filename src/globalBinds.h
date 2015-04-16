
#ifndef _GLOBAL_BINDS_
#define _GLOBAL_BINDS_

typedef struct _Camera_t Camera_t;
typedef struct _Character_t Character_t;

static Camera_t *cameraView;
void BindCameraView(Camera_t *);
Camera_t *GetCameraView();
void UnbindCameraView();

static Character_t *mapTerrain;
void BindMapTerrain(Character_t *);
Character_t *GetMapTerrain();
void UnbindMapTerrain();

static Character_t *controlledCharacter;
void BindControlledCharacter(Character_t *);
Character_t *GetControlledCharacter();
void UnbindControlledCharacter();

#endif
