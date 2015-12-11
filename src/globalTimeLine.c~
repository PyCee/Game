
#include "globalTimeLine.h"

#include <stdio.h>
#include <stdlib.h>

void genGlobalTimeLine
(globalTimeLine_t **timeLine)
{
	*timeLine = malloc(sizeof(globalTimeLine_t));
	globalTimeLine_t *_timeLine = *timeLine;
	_timeLine->startTime = SDL_GetTicks();
	_timeLine->currTime = SDL_GetTicks();
	_timeLine->elapsedTime = 0;
	_timeLine->prevFrameDuration = 0;
}
void freeGlobalTimeLine
(globalTimeLine_t **timeLine)
{
	printf("Elapsed Time: %lu milliseconds\n", (*timeLine)->currTime - (*timeLine)->startTime);
	free(*timeLine);
	*timeLine = 0;
}
unsigned short getPrevFrameDuration
(globalTimeLine_t *timeLine)
{
	return timeLine->prevFrameDuration;
}
unsigned long getCurrentTime
(globalTimeLine_t *timeLine)
{
	return timeLine->currTime;;
}
unsigned long getElapsedTime
(globalTimeLine_t *timeLine)
{
	return timeLine->elapsedTime;
}
void updateGlobalTimeLine
(globalTimeLine_t *timeLine)
{
	timeLine->prevFrameDuration = SDL_GetTicks() - timeLine->currTime;
	timeLine->currTime = SDL_GetTicks();
	timeLine->elapsedTime += timeLine->prevFrameDuration;
}
