
#ifndef _GLOBAL_TIMELINE_
#define _GLOBAL_TIMELINE_

/* SINGLETON */
typedef struct _globalTimeLine_t {
	U64 startTime;
	U64 currTime;
	U64 elapsedTime;
	U16 prevFrameDuration;
} globalTimeLine_t;

void genGlobalTimeLine(globalTimeLine_t **);
void freeGlobalTimeLine(globalTimeLine_t **);

U16 getPrevFrameDuration(globalTimeLine_t *);
U64 getCurrentTime(globalTimeLine_t *);
U64 getElapsedTime(globalTimeLine_t *);

void updateGlobalTimeLine(globalTimeLine_t *);

#endif /* _GLOBAL_TIMELINE_ */
