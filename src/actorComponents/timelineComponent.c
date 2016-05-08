
#include "timelineComponent.h"

#include <stdlib.h>
#include <math.h>
#include "../actors.h"

#include "../globalTimeline.h"

void genTimelineComponent() {
	unpauseTimeline(getActor());
	TIME_PLAYBACK_RATE = 1.0;
}
void freeTimelineComponent() {
}
void mapTimeline() {
}
void pauseTimeline() {
	TIMELINE->isPaused = 1;
}
void unpauseTimeline() {
	TIMELINE->isPaused = 0;
}
unsigned short updateTimelineComponent() {
	if (isTimelinePaused(getActor()))
		return 0;

	unsigned short lastFrameTime = getPrevFrameDuration(*getGlobalTimeline())
			* TIMELINE->playBackRate;
	TIME_CURR += lastFrameTime;
	/*if (Timeline->currTime > Timeline->duration) {
	 Timeline->currTime -= Timeline->duration;
	 Timeline->replayed++;
	 }*/
	return lastFrameTime;
}
unsigned char isTimelinePaused() {
	return TIMELINE->isPaused;
}
unsigned char isTimelineOver() {
	//if (Timeline->replayed <= Timeline->replay) 
	return 0;
	pauseTimeline(getActor());
	return 1;
}
