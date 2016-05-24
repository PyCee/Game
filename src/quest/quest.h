#ifndef QUEST
#define QUEST

#include <stdio.h>

#define QUEST_COMPLETED 0
#define QUEST_INACTIVE QUEST_COMPLETED + 1
#define QUEST_ACTIVE QUEST_INACTIVE + 1 // an active quest can have any progress value more than or equal to QUEST_ACTIVE
#define ACTIVE_QUEST questList[getQuest()]
#define QUEST_OBJECTIVE ACTIVE_QUEST.objectiveList[getObjective()]
#define QUEST_PROGRESS ACTIVE_QUEST.progress
#define QUEST_NAME ACTIVE_QUEST.questName
#define QUEST_NEXT_OBJECTIVE ACTIVE_QUEST.nextObjective

struct objective;

typedef struct quest{
	unsigned char *questName;
	struct objective *objectiveList;
	unsigned char progress;
	unsigned char numObjectives;
	unsigned char nextObjective;
} quest;

extern quest *questList;

unsigned char getQuest(void);
void bindQuest(unsigned char);
unsigned char getObjective(void);
void bindObjective(unsigned char);

unsigned char addQuest(unsigned char *);
unsigned char addObjective(struct objective);
void setProgress(unsigned char);
void setNextQuest(unsigned char);
void loadQuests(FILE *);
void saveQuests(FILE *);
void resetQuests(void);
void updateQuests(void);
void startQuest(void);

char isQuestCompleted();
char isQuestInactive();
char isQuestActive();

#endif /* QUEST */
