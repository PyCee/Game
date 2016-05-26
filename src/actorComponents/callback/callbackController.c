#include "callbackController.h"

#include <stdlib.h>
#include <stdio.h>
#include "../physics/vector.h"

callbackController genCallbackController(char (*should)(callbackController), void (*complete)(callbackController))
{
	callbackController call;
	call.shouldCallback = should;
	call.completeCallback = complete;
	return call;
}
void freeCallbackController(callbackController *call)
{
	call->_vec3 = 0;
	call->_float = 0;
	call->_int = 0;
	call->_uchar = 0;
	call->shouldCallback = 0;
	call->completeCallback = 0;
}
unsigned char checkCallbackController(callbackController *call)
{
	if(call->shouldCallback(*call)){
		call->completeCallback(*call);
		return 1;
	}
	return 0;
}
void callbackControllerElement(callbackController *call, void *poi, unsigned char num, unsigned char type)
{
	unsigned char index;
	switch(type){
		case CALLBACK_VEC3:
			call->numVec3 = num;
			call->_vec3 = malloc(sizeof(vec3) * num);
			for(index = 0; index < num; index++)
				call->_vec3[index] = *(vec3 *)(poi + sizeof(vec3) * index);
			break;
		case CALLBACK_FLOAT:
			call->numFloat = num;
			call->_float = malloc(sizeof(float) * num);
			for(index = 0; index < num; index++)
				call->_float[index] = *(float *)(poi + sizeof(float) * index);
			break;
		case CALLBACK_INT:
			call->numInt = num;
			call->_int = malloc(sizeof(int) * num);
			for(index = 0; index < num; index++)
				call->_int[index] = *(int *)(poi + sizeof(int) * index);
			break;
		case CALLBACK_CHAR:
			call->numUChar = num;
			call->_uchar = malloc(sizeof(unsigned char) * num);
			for(index = 0; index < num; index++)
				call->_uchar[index] = *(unsigned char *)(poi + sizeof(unsigned char) * index);
			break;
		default:
			break;
	}
}
