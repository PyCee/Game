#ifndef OBJECTIVE
#define OBJECTIVE

typedef struct objective{
	void (*initObjective)(void);
	void (*finishObjective)(void);
	char (*isObjectiveComplete)(void);
	char *objectiveName;
	char *description;
} objective;

void setIsObjectiveComplete(char *);

char isObjectiveComplete_Inactive(void);

#endif /* OBJECTIVE */
