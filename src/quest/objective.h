#ifndef _OBJECTIVE_
#define _OBJECTIVE_

typedef struct Objective{
	void (*initObjective)(void);
	void (*finishObjective)(void);
	char (*isObjectiveComplete)(void);
	char *objectiveName;
	char *description;
} Objective;

void setIsObjectiveComplete(char *);

char isObjectiveComplete_Inactive(void);

#endif /* _OBJECTIVE_ */
