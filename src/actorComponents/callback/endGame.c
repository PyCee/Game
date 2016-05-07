#include "endGame.h"
#include "callbackController.h"

#include <stdio.h>

extern unsigned char IAMALIVE;

void endGame(callbackController call)
{
	printf("ending because of callback\n");
	IAMALIVE = 0;
}
