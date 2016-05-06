#include "callback.h"

#include <stdlib.h>


void updateCallbacks(void)
{
	unsigned char index;
	for(index = 0; index < 10; index ++)
		if(callbacks[index])
			checkCallback(callbacks[index]);
}
unsigned char nextFreeCallback(void)
{
	
	unsigned char index;
	for(index = 0; index < 10; index ++)
		if(callbacks[index])
			return index;
	return 0;
}
void enableCallback(callback *call)
{
	callbacks[nextFreeCallback()] = call;
}
void freeCallbacks(void)
{
	unsigned char index;
	for(index = 0; index < 10; index ++)
		if(callbacks[index])
			freeCallback(callbacks[index]);
}
callback genCallback(char (*should)(callback), void (*complete)(callback), unsigned char *chars, unsigned char numChar, float *floats, unsigned char numFloat, int *ints, unsigned char numInt)
{
	callback call;
	call.shouldCallback = should;
	call.completeCallback = complete;
	call.numChar = numChar;
	call._uchar = malloc(sizeof(unsigned char) * numChar);
	unsigned char index;
	for(index = 0; index < numChar; index++){
		call._uchar[index] = chars[index];
	}
	call.numFloat = numFloat;
	call._float = malloc(sizeof(float) * numFloat);
	for(index = 0; index < numFloat; index++){
		call._float[index] = floats[index];
	}
	call.numInt = numInt;
	call._int = malloc(sizeof(short) * numInt);
	for(index = 0; index < numInt; index++){
		call._int[index] = ints[index];
	}
	return call;
}
void freeCallback(callback *call)
{
	free(call->_uchar);
	free(call->_float);
	free(call->_int);
}
void checkCallback(callback *call)
{
	if(call->shouldCallback(*call))
		call->completeCallback(*call);
}
