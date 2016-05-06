#include "timeout.h"
#include "callback.h"

#include <stdio.h>

callback genTimeout(int time, void (*complete)(callback))
{
	callback call;
	int times[] = {time};
	call = genCallback(shouldTimeout, complete, 0, 0, 0, 0, times, 1);
	
	return call;
}

char shouldTimeout(callback call)
{
	call._int[TIMEOUT_REMAINING] -= getPrevFrameDuration(getGlobalTimeLine());
	if(call._int[TIMEOUT_REMAINING] <= 0)
		return 1;
	return 0;
}
