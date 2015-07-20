
#include "../dataTypes.h"
#include "timeLineComponent.h"

#include <stdlib.h>
#include <math.h>
#include "../actors.h"

#include "../globalTimeLine.h"
#include "../globalBinds.h"

void genTimeLineComponent (U8 actorID)
{
	UnpauseTimeLine(actorID);
	Actors.timeLine[actorID].playBackRate = 2.0;
	/**timeLine = malloc(sizeof(TimeLine_t));
	TimeLine_t *_timeLine = *timeLine;
	_timeLine->startTime = getCurrentTime(getGlobalTimeLine());
	_timeLine->duration = 0;
	_timeLine->currTime = 0;
	_timeLine->playBackRate = 1;
	_timeLine->isPaused = 1;*/
}
void freeTimeLineComponent (U8 actorID)
{
}
void mapTimeLine (U8 actorID)
{
}
void PauseTimeLine (U8 actorID)
{
	Actors.timeLine[actorID].isPaused = 1;
}
void UnpauseTimeLine (U8 actorID)
{
	Actors.timeLine[actorID].isPaused = 0;
}
U16 updateTimeLineComponent (U8 actorID)
{
	if ( isTimeLinePaused( actorID ) )
		return 0;
	
	U16 lastFrameTime = getPrevFrameDuration(getGlobalTimeLine()) * Actors.timeLine[actorID].playBackRate;
	Actors.timeLine[actorID].currTime += lastFrameTime;
	/*if (timeLine->currTime > timeLine->duration) {
		timeLine->currTime -= timeLine->duration;
		timeLine->replayed++;
	}*/
	return lastFrameTime;
}
U8 isTimeLinePaused
(U8 actorID)
{
	return Actors.timeLine[actorID].isPaused;
}
U8 isTimeLineOver
(U8 actorID)
{
	//if (timeLine->replayed <= timeLine->replay) 
		return 0;
	pauseTimeLine(actorID);
	return 1;
}
