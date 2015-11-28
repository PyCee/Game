
#include "../dataTypes.h"
#include "timeLineComponent.h"

#include <stdlib.h>
#include <math.h>
#include "../actors.h"

#include "../globalTimeLine.h"
#include "../globalBinds.h"

void genTimeLineComponent ()
{
	UnpauseTimeLine(getActor());
	Actors.timeLine[getActor()].playBackRate = 1.0;
}
void freeTimeLineComponent ()
{
}
void mapTimeLine ()
{
}
void PauseTimeLine ()
{
	Actors.timeLine[getActor()].isPaused = 1;
}
void UnpauseTimeLine ()
{
	Actors.timeLine[getActor()].isPaused = 0;
}
U16 updateTimeLineComponent ()
{
	if ( isTimeLinePaused( getActor() ) )
		return 0;
	
	U16 lastFrameTime = getPrevFrameDuration(getGlobalTimeLine()) * Actors.timeLine[getActor()].playBackRate;
	Actors.timeLine[getActor()].currTime += lastFrameTime;
	/*if (timeLine->currTime > timeLine->duration) {
		timeLine->currTime -= timeLine->duration;
		timeLine->replayed++;
	}*/
	return lastFrameTime;
}
U8 isTimeLinePaused
()
{
	return Actors.timeLine[getActor()].isPaused;
}
U8 isTimeLineOver
()
{
	//if (timeLine->replayed <= timeLine->replay) 
		return 0;
	pauseTimeLine(getActor());
	return 1;
}
