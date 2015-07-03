
#ifndef _LOCAL_TIMELINE_
#define _LOCAL_TIMELINE_

typedef struct _LocalTimeLine_t{
	U32 duration;
	U32 currTime;
	I8 forward;
	U8 isPaused;
} LocalTimeLine_t;

void genLocalTimeLine(LocalTimeLine_t **);
void freeLocalTimeLine(LocalTimeLine_t **);
void setLocalTimeLineDuration(LocalTimeLine_t *, U32);
void MapLocalTimeLine(LocalTimeLine_t *, U32);
void PauseLocalTimeLine(LocalTimeLine_t *);
void UnpauseLocalTimeLine(LocalTimeLine_t *);

void advanceLocalTimeLine(LocalTimeLine_t *, U64);

U8 isLocalTimeLinePaused(LocalTimeLine_t *);
U8 isLocalTimeLineOver(LocalTimeLine_t *);

#endif /* _LOCAL_*/
