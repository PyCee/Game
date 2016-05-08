
#ifndef _ACTOR_SELECTION_
#define _ACTOR_SELECTION_

#define DYN 0
#define STA 1

unsigned char currentActor;
void bindActor(unsigned char);
unsigned char getActor(void);

unsigned char currentLight;
void bindLight(unsigned char);
unsigned char getLight(void);

static unsigned char cameraView;
void bindCameraView (unsigned char);
unsigned char getCameraView (void);

static unsigned char controlledActor;
void bindControlledActor (unsigned char);
unsigned char getControlledActor (void);

static unsigned char mapTerrain;
void bindMapTerrain (unsigned char);
unsigned char getMapTerrain (void);

static struct globalTimeline *globalTime;
void bindGlobalTimeline	(struct globalTimeline *);
struct globalTimeline* getGlobalTimeline (void);

#endif /* _ACTOR_SELECTION_ */
