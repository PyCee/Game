
#ifndef _ACTOR_SELECTION_
#define _ACTOR_SELECTION_

#define DYN 0
#define STA 1

unsigned int currentActor;
void bindActor(unsigned int);
unsigned int getActor(void);

unsigned char currentLight;
void bindLight(unsigned char);
unsigned char getLight(void);

static unsigned int cameraView;
void bindCameraView (unsigned int);
unsigned int getCameraView (void);

static unsigned int controlledActor;
void bindControlledActor (unsigned int);
unsigned int getControlledActor (void);

static unsigned int mapTerrain;
void bindMapTerrain (unsigned int);
unsigned int getMapTerrain (void);

static struct globalTimeline *globalTime;
void bindGlobalTimeline	(struct globalTimeline *);
struct globalTimeline* getGlobalTimeline (void);

#endif /* _ACTOR_SELECTION_ */
