#include "endGame.h"
#include "callback.h"

#include <stdio.h>

extern unsigned char IAMALIVE;

void endGame(struct callback call)
{
	printf("ending because of callback\n");
	IAMALIVE = 0;
}
