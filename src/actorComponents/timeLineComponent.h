#ifndef _TIME_LINE_COMPONENT_
#define _TIME_LINE_COMPONENT_

typedef struct TimeLineComponent {
	unsigned long startTime;
	unsigned int currTime;
	float playBackRate;
	float duration;
	unsigned short lastFrameTime;
	unsigned char replay;
	unsigned char replayed;
	unsigned char isPaused;
} TimeLineComponent;

void genTimeLineComponent();
void freeTimeLineComponent();
unsigned short updateTimeLineComponent();
void mapTimeLine();
void pauseTimeLine();
void unpauseTimeLine();

unsigned short getAdvanceTime(void);

unsigned char isTimeLinePaused();
unsigned char isTimeLineOver();

#endif /*  _TIME_LINE_COMPONENT_*/
