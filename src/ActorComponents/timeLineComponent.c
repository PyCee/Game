
#include "../dataTypes.h"
#include "timeLineComponent.h"

#include <stdlib.h>
#include <math.h>
#include "../actors.h"

#include "../globalTimeLine.h"
#include "../globalBinds.h"

void genTimeLineComponent
(U8 actorID)
{
	/**timeLine = malloc(sizeof(TimeLine_t));
	TimeLine_t *_timeLine = *timeLine;
	_timeLine->startTime = getCurrentTime(getGlobalTimeLine());
	_timeLine->duration = 0;
	_timeLine->currTime = 0;
	_timeLine->playBackRate = 1;
	_timeLine->isPaused = 1;*/
}
void freeTimeLineComponent
(U8 actorID)
{
	/*free(*timeLine);
	*timeLine = NULL;*/
}
void setTimeLineComponentStart
(U8 actorID, U64 time)
{
	//timeLine->startTime = time;
}
void setTimeLineDuration
(U8 actorID, U32 _duration)
{
	//timeLine->duration = _duration;
}
void MapTimeLineComponent
(U8 actorID, U32 scale)
{
	/*
	timeLine->duration = timeLine->duration / abs(scale);
	I8 forward = scale / abs(scale);
	
	if (forward == 1)
		timeLine->currTime = 0;
		// Map TimeLine Forwards
	else
		timeLine->currTime = timeLine->duration;
		// Map TimeLine Backwards
	
	UnpauseTimeLine(timeLine);
	*/
}
void PauseTimeLineComponent
(U8 actorID)
{
	Actors.timeLine[actorID].isPaused = 1;
}
void UnpauseTimeLineComponent
(U8 actorID)
{
	Actors.timeLine[actorID].isPaused = 0;
}
void updateTimeLineComponent
(U8 actorID)
{
	Actors.timeLine[actorID].currTime += getPrevFrameDuration(getGlobalTimeLine());
	/*if (!isTimeLinePaused(timeLine))
		timeLine->currTime += deltaMS * timeLine->playBackRate;
	if (timeLine->currTime > timeLine->duration) {
		timeLine->currTime -= timeLine->duration;
		timeLine->replayed++;
	}*/
}
U8 isTimeLineComponentPaused
(U8 actorID)
{
	return Actors.timeLine[actorID].isPaused;
}
U8 isTimeLineComponentOver
(U8 actorID)
{
	//if (timeLine->replayed <= timeLine->replay) 
		return 0;
	PauseTimeLineComponent(actorID);
	return 1;
}
