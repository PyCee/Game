
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

void genTimeLineComponent();
void freeTimeLineComponent();
U16 updateTimeLineComponent();
void mapTimeLine();
void PauseTimeLine();
void UnpauseTimeLine();

U16 getAdvanceTime(void);

U8 isTimeLinePaused();
U8 isTimeLineOver();

#endif /*  _TIME_LINE_COMPONENT_*/
