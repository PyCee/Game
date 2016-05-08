#ifndef TIMELINE_COMPONENT
#define TIMELINE_COMPONENT

#define TIMELINE localTimeline[getActor()]
#define TIME_START TIMELINE->startTime
#define TIME_CURR TIMELINE->currTime
#define TIME_PLAYBACK_RATE TIMELINE->playBackRate


typedef struct TimelineComponent {
	unsigned long startTime;
	unsigned int currTime;
	float playBackRate;
	float duration;
	unsigned short lastFrameTime;
	unsigned char replay;
	unsigned char replayed;
	unsigned char isPaused;
} TimelineComponent;

void genTimelineComponent();
void freeTimelineComponent();
unsigned short updateTimelineComponent();
void mapTimeline();
void pauseTimeline();
void unpauseTimeline();

unsigned short getAdvanceTime(void);

unsigned char isTimelinePaused();
unsigned char isTimelineOver();

#endif /*  TIMELINE_COMPONENT */
