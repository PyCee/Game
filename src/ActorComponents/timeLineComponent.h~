
#ifndef _TIME_LINE_COMPONENT_
#define _TIME_LINE_COMPONENT_

typedef struct _TimeLineComponent_t{
	U64 startTime;
	U32 currTime;
	F32 playBackRate;
	F32 duration;
	U16 lastFrameTime;
	U8 replay;
	U8 replayed;
	U8 isPaused;
} TimeLineComponent_t;

void genTimeLineComponent(U8);
void freeTimeLineComponent(U8);
U16 updateTimeLineComponent(U8);
void mapTimeLine(U8);
void PauseTimeLine(U8);
void UnpauseTimeLine(U8);

U16 getAdvanceTime(void);

U8 isTimeLinePaused(U8);
U8 isTimeLineOver(U8);

#endif /*  _TIME_LINE_COMPONENT_*/
