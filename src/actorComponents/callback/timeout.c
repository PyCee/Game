#include "timeout.h"
#include "callbackController.h"
#include "../../globalTimeline.h"
#include "../../actorSelection.h"

#include <stdio.h>

callbackController genTimeout(void (*complete)(callbackController), int time)
{
	callbackController call;
	int times[] = {time};
	call = genCallbackController(shouldTimeout, complete);
	callbackControllerElement(&call, &times, 1, CALLBACK_INT);
	return call;
}

char shouldTimeout(callbackController call)
{
	printf("timeout test\n");
	call._int[TIMEOUT_REMAINING] -= getPrevFrameDuration(*getGlobalTimeline());
	if(call._int[TIMEOUT_REMAINING] <= 0)
		return 1;
	return 0;
}
