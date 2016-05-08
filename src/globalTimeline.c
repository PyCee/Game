
#include "globalTimeline.h"

#include <stdio.h>
#include <stdlib.h>

globalTimeline genGlobalTimeline(void)
{
	globalTimeline timeline;
	timeline.startTime = SDL_GetTicks();
	timeline.currTime = SDL_GetTicks();
	timeline.elapsedTime = 0;
	timeline.prevFrameDuration = 0;
	return timeline;
}
void freeGlobalTimeline(globalTimeline *timeline)
{
	printf("Elapsed Time: %lu milliseconds\n", timeline->currTime - timeline->startTime);
}
unsigned short getPrevFrameDuration(globalTimeline timeline)
{
	return timeline.prevFrameDuration;
}
unsigned long getCurrentTime(globalTimeline timeline)
{
	return timeline.currTime;;
}
unsigned long getElapsedTime(globalTimeline timeline)
{
	return timeline.elapsedTime;
}
void updateGlobalTimeline(globalTimeline *timeline)
{
	timeline->prevFrameDuration = SDL_GetTicks() - timeline->currTime;
	timeline->currTime = SDL_GetTicks();
	timeline->elapsedTime += timeline->prevFrameDuration;
}
