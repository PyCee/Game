
#include "dataTypes.h"
#include "localTimeLine.h"

#include <stdlib.h>
#include <math.h>

#include "globalTimeLine.h"
#include "globalBinds.h"

void genLocalTimeLine
(LocalTimeLine_t **timeLine)
{
	*timeLine = malloc(sizeof(LocalTimeLine_t));
	LocalTimeLine_t *_timeLine = *timeLine;
	_timeLine->startTime = getCurrentTime(getGlobalTimeLine());
	_timeLine->duration = 0;
	_timeLine->currTime = 0;
	_timeLine->playBackRate = 1;
	_timeLine->replay = 1;
	_timeLine->replayed = 1;
	_timeLine->isPaused = 1;
}
void freeLocalTimeLine
(LocalTimeLine_t **timeLine)
{
	free(*timeLine);
	*timeLine = NULL;
}
void setLocalTimeLineStart
(LocalTimeLine_t *timeLine, U64 time)
{
	timeLine->startTime = time;
}
void setLocalTimeLineDuration
(LocalTimeLine_t *timeLine, U32 _duration)
{
	timeLine->duration = _duration;
}
void MapLocalTimeLine
(LocalTimeLine_t *timeLine, U32 scale)
{
	/*
	timeLine->duration = timeLine->duration / abs(scale);
	I8 forward = scale / abs(scale);
	
	if (forward == 1)
		timeLine->currTime = 0;
		// Map LocalTimeLine Forwards
	else
		timeLine->currTime = timeLine->duration;
		// Map LocalTimeLine Backwards
	
	UnpauseLocalTimeLine(timeLine);
	*/
}
void PauseLocalTimeLine
(LocalTimeLine_t *timeLine)
{
	timeLine->isPaused = 1;
}
void UnpauseLocalTimeLine
(LocalTimeLine_t *timeLine)
{
	timeLine->isPaused = 0;
}
void advanceLocalTimeLine
(LocalTimeLine_t *timeLine, U64 deltaMS)
{
	if (!isLocalTimeLinePaused(timeLine))
		timeLine->currTime += deltaMS * timeLine->playBackRate;
	if (timeLine->currTime > timeLine->duration) {
		timeLine->currTime -= timeLine->duration;
		timeLine->replayed++;
	}
}
U8 isLocalTimeLinePaused
(LocalTimeLine_t *timeLine)
{
	return timeLine->isPaused;
}
U8 isLocalTimeLineOver
(LocalTimeLine_t *timeLine)
{
	if (timeLine->replayed <= timeLine->replay) 
		return 0;
	PauseLocalTimeLine(timeLine);
	return 1;
}
