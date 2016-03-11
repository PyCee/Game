#ifndef _QUEST_
#define _QUEST_

#include <stdio.h>

#define QUEST_COMPLETED 0
#define QUEST_INACTIVE 1
#define QUEST_ACTIVE 2 // an active quest can have any progress value more than or equal to QUEST_ACTIVE
#define QUEST quest[getQuest()]
#define OBJECTIVE QUEST.objective[QUEST.progress]

typedef struct Quest{
	unsigned char *name;
	struct Objective *objective;
	unsigned char progress;
} Quest;

extern Quest quest[];

unsigned char getQuest(void);
unsigned char bindQuest(unsigned char);

void loadQuests(FILE *);
void saveQuests(FILE *);
void resetQuests(void);
void updateQuests(void);
void startQuest(void);

char isQuestCompleted();
char isQuestInactive();
char isQuestActive();

#endif /* _QUEST_ */
