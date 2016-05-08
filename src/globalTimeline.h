
#ifndef _GLOBAL_TIMELINE_
#define _GLOBAL_TIMELINE_

/* SINGLETON */
typedef struct globalTimeline {
	unsigned long startTime;
	unsigned long currTime;
	unsigned long elapsedTime;
	unsigned short prevFrameDuration;
} globalTimeline;

globalTimeline genGlobalTimeline(void);
void freeGlobalTimeline(globalTimeline *);

unsigned short getPrevFrameDuration(globalTimeline);
unsigned long getCurrentTime(globalTimeline);
unsigned long getElapsedTime(globalTimeline);

void updateGlobalTimeline(globalTimeline *);

#endif /* _GLOBAL_TIMELINE_ */
