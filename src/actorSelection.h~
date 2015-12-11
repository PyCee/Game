
#ifndef _ACTOR_SELECTION_
#define _ACTOR_SELECTION_

#define DYN 0
#define STA 1

#define MAX_ACTOR_COUNT 20
unsigned char currentActor;
void bindActor(unsigned char);
unsigned char getActor(void);

#define MAX_LIGHT_COUNT/*_PER_ACTOR */ 1
// Allows actors to have own light sources. Multiple, simply to allow for less limits.
unsigned char currentLight;
void bindLight(unsigned char);
unsigned char getLight(void);

static	unsigned char cameraView;
void bindCameraView (unsigned char);
unsigned char getCameraView (void);

static	unsigned char controlledActor;
void bindControlledActor (unsigned char);
unsigned char getControlledActor (void);

static	unsigned char mapTerrain;
void bindMapTerrain (unsigned char);
unsigned char getMapTerrain (void);

typedef struct _globalTimeLine_t globalTimeLine_t;

static	globalTimeLine_t * globalTimeLine;
void bindGlobalTimeLine	(globalTimeLine_t *);
globalTimeLine_t* getGlobalTimeLine (void);

#endif /* _ACTOR_SELECTION_ */
