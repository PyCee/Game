
#ifndef _GLOBAL_TIMELINE_
#define _GLOBAL_TIMELINE_

/* SINGLETON */
typedef struct _globalTimeLine_t {
	unsigned long startTime;
	unsigned long currTime;
	unsigned long elapsedTime;
	unsigned short prevFrameDuration;
} globalTimeLine_t;

void genGlobalTimeLine(globalTimeLine_t **);
void freeGlobalTimeLine(globalTimeLine_t **);

unsigned short getPrevFrameDuration(globalTimeLine_t *);
unsigned long getCurrentTime(globalTimeLine_t *);
unsigned long getElapsedTime(globalTimeLine_t *);

void updateGlobalTimeLine(globalTimeLine_t *);

#endif /* _GLOBAL_TIMELINE_ */
