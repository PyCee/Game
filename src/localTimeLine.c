
#include "dataTypes.h"
#include "timeLine.h"

#include <stdlib.h>
#include <math.h>

void genLocalTimeLine
(LocalTimeLine_t **timeLine)
{
	*timeLine = malloc(sizeof(LocalTimeLine_t));
	LocalTimeLine_t *_timeLine = *timeLine;
	_timeLine->duration = 0;
	_timeLine->currTime = 0;
	_timeLine->forward = 1;
	_timeLine->isPaused = 1;
}
void freeLocalTimeLine
(LocalTimeLine_t **timeLine)
{
	free(*timeLine);
	*timeLine = NULL;
}
void setLocalTimeLineDuration
(LocalTimeLine_t *timeLine, U32 _duration)
{
	timeLine->duration = _duration;
}
void MapLocalTimeLine
(LocalTimeLine_t *timeLine, U32 scale)
{
	timeLine->duration = timeLine->duration / abs(scale);
	timeLine->forward = scale / abs(scale);
	
	if (timeLine->forward == 1)
		// Map LocalTimeLine Forwards
	else
		// Map LocalTimeLine Backwards
	
	UnpauseLocalTimeLine(timeLine);
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
		timeLine->currTime += deltaMS * timeLine->forward;
}
U8 isLocalTimeLinePaused
(LocalTimeLine_t *timeLine)
{
	return timeLine->isPaused;
}
U8 isLocalTimeLineOver
(LocalTimeLine_t *timeLine)
{
	if (timeLine->currTime > timeLine->duration) {
		PauseLocalTimeLine(timeLine);
		return 1;
	}
	return 0;
}
