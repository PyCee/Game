
#include "timeLineComponent.h"

#include <stdlib.h>
#include <math.h>
#include "../actors.h"

#include "../globalTimeLine.h"

void genTimeLineComponent() {
	unpauseTimeLine(getActor());
	Actors.timeLine[getActor()].playBackRate = 1.0;
}
void freeTimeLineComponent() {
}
void mapTimeLine() {
}
void pauseTimeLine() {
	Actors.timeLine[getActor()].isPaused = 1;
}
void unpauseTimeLine() {
	Actors.timeLine[getActor()].isPaused = 0;
}
unsigned short updateTimeLineComponent() {
	if (isTimeLinePaused(getActor()))
		return 0;

	unsigned short lastFrameTime = getPrevFrameDuration(getGlobalTimeLine())
			* Actors.timeLine[getActor()].playBackRate;
	Actors.timeLine[getActor()].currTime += lastFrameTime;
	/*if (timeLine->currTime > timeLine->duration) {
	 timeLine->currTime -= timeLine->duration;
	 timeLine->replayed++;
	 }*/
	return lastFrameTime;
}
unsigned char isTimeLinePaused() {
	return Actors.timeLine[getActor()].isPaused;
}
unsigned char isTimeLineOver() {
	//if (timeLine->replayed <= timeLine->replay) 
	return 0;
	pauseTimeLine(getActor());
	return 1;
}
