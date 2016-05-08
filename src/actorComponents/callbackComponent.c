#include "callbackComponent.h"
#include "callback/callbackController.h"
#include "callback/timeout.h"
#include "callback/nearTest.h"
#include "../actors.h"
#include <stdlib.h>
#include <stdio.h>

void genCallbackComponent(void)
{
	CALLBACKS = 0;
	NUM_CALLBACKS = 0;
}
void freeCallbackComponent(void)
{
	unsigned char index;
	for(index = 0; index < NUM_CALLBACKS; index++)
		if(CALLBACKS[index])
			freeCallbackController(CALLBACKS[index]);
}
void updateCallbackComponent(unsigned short deltaMS)
{
	
	unsigned char index;
	for(index = 0; index < NUM_CALLBACKS; index++)
		if(CALLBACKS[index])
			checkCallbackController(CALLBACKS[index]);
}
unsigned char nextFreeCallbackController(void)
{
	unsigned char index;
	while(index < NUM_CALLBACKS){
		if(CALLBACKS[index] == 0)
			return index;
		index++;
	}
	return NUM_CALLBACKS;
}
void enableCallbackController(callbackController *call)
{
	unsigned char next;
	if(NUM_CALLBACKS == 0){
		NUM_CALLBACKS = 1;
		next = 0;
		CALLBACKS = malloc(sizeof(callbackController *) * NUM_CALLBACKS);
	} else if(nextFreeCallbackController() == NUM_CALLBACKS){
		NUM_CALLBACKS += 1;
		next = NUM_CALLBACKS - 1;
		CALLBACKS = realloc(CALLBACKS, sizeof(callbackController *) * NUM_CALLBACKS);
	}
	CALLBACKS[next] = call;
}
