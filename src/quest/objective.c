#include "objective.h"
#include "quest.h"
#include <string.h>
#include <stdio.h>

static const unsigned char *lookupObjectiveFunctionsStr[] = {
	"Inactive"
};
static char (*lookupObjectiveFunctions[]) (void) = {
	isObjectiveComplete_Inactive
};
void setIsFinished(char *lookup)
{
	unsigned char index = 0;
	for(; index < (sizeof(lookupObjectiveFunctionsStr)); index++){
		if(!strcmp(lookup, lookupObjectiveFunctionsStr[index])){
			OBJECTIVE.isObjectiveComplete = lookupObjectiveFunctions[index];
			break;
		} else if(index == ((sizeof(lookupObjectiveFunctionsStr) / 8) - 1))
			printf("\'%s\' is not a valid quest objective function.\n", lookup);
	}
}
char  isObjectiveComplete_Inactive(void)
{
	return 0;
}
