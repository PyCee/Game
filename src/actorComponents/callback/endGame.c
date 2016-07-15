#include "endGame.h"
#include "callbackController.h"

#include <stdio.h>

extern unsigned char IAMALIVE;

void endGame(callbackController call)
{
	IAMALIVE = 0;
}
