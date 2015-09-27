
#ifndef _ACTOR_SELECTION_
#define _ACTOR_SELECTION_

#define DYN 0
#define STA 1

#define MAX_ACTOR_COUNT 20
U8 currentActor;
void bindActor(U8);
U8 getActor(void);

#define MAX_LIGHT_COUNT/*_PER_ACTOR */ 1
// Allows actors to have own light sources. Multiple, simply to allow for less limits.
U8 currentLight;
void bindLight(U8);
U8 getLight(void);

static	U8 cameraView;
void bindCameraView (U8);
U8 getCameraView (void);

static	U8 controlledActor;
void bindControlledActor (U8);
U8 getControlledActor (void);

static	U8 mapTerrain;
void bindMapTerrain (U8);
U8 getMapTerrain (void);

typedef struct _globalTimeLine_t globalTimeLine_t;

static	globalTimeLine_t * globalTimeLine;
void bindGlobalTimeLine	(globalTimeLine_t *);
globalTimeLine_t* getGlobalTimeLine (void);

#endif /* _ACTOR_SELECTION_ */
