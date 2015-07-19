
#ifndef _TIME_LINE_COMPONENT_
#define _TIME_LINE_COMPONENT_

typedef struct _TimeLineComponent_t{
	U64 startTime;
	U32 currTime;
	F32 playBackRate;
	F32 duration;
	U8 replay;
	U8 replayed;
	U8 isPaused;
} TimeLineComponent_t;

void genTimeLineComponent(U8);
void freeTimeLineComponent(U8);
void updateTimeLineComponent(U8);
void setTimeLineComponentStart(U8, U64);
void setTimeLineComponentDuration(U8, U32);
void setTimeLineComponentReplay(U8, U32);
void MapTimeLineComponent(U8, U32);
void PauseTimeLineComponent(U8);
void UnpauseTimeLineComponent(U8);

U8 isTimeLineComponentPaused(U8);
U8 isTimeLineComponentOver(U8);

#endif /*  _TIME_LINE_COMPONENT_*/
