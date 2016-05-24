#include "quest.h"
#include "objective.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

quest *questList;
unsigned char numQuests;
unsigned char QuestID;
unsigned char ObjectiveID;

unsigned char getQuest(void)
{
	return QuestID;
}
void bindQuest(unsigned char id)
{
	QuestID = id;
}
unsigned char getObjective(void)
{
	return ObjectiveID;
}
void bindObjective(unsigned char id)
{
	ObjectiveID = id;
}
unsigned char addQuest(unsigned char *qName)
{
	bindQuest(numQuests);
	numQuests += 1;
	if(numQuests == 0)
		questList = malloc(sizeof(quest));
	else
		questList = realloc(questList, sizeof(quest) * numQuests);
	QUEST_NAME = malloc(sizeof(qName));
	strcpy(QUEST_NAME, qName);
	return numQuests;
}
unsigned char addObjective(objective obj)
{
	return 0;
}
void setProgress(unsigned char prog)
{
	QUEST_PROGRESS = prog;
}
void setNextQuest(unsigned char next)
{
	QUEST_NEXT_OBJECTIVE = next;
}
void loadQuests(FILE *saveFile)
{
	numQuests = 0;//TODO: count quests.
	//load quests from savefile
	unsigned char id;
	for(id = 0; id < numQuests; id++) {
		ACTIVE_QUEST.objectiveList = malloc(sizeof(objective) * numQuests);
		QUEST_PROGRESS = QUEST_INACTIVE;//TODO: get quest status from save file.
		bindQuest(id);
		
		unsigned char ob;
		for(ob = 0; ob < 2; ob++){
			bindObjective(ob);
			setIsFinished("Inactive");
		}
		for(ob = 2; ob < 255; ob++){
			bindObjective(ob);
			//get objective from file
			//QUEST.objective[ob]
			
			//setIsObjectiveComplete(str); // set quest objectve from file
		}
		
		char *questName = 0;//TODO: get Quest Name from file
		QUEST_NAME = malloc(strlen(questName));
		strcpy(QUEST_NAME, questName);
	}
}
void saveQuests(FILE *saveFile)
{
	unsigned char id;
	for(id = 2; id < numQuests; id++) {
		//quest[id].progress = QUEST_COMPLETED;//TODO: write to file
		
		//strcpy(quest[id].name, questName);
	}
}
void resetQuests(void)
{
	unsigned char id;
	for(id = 0; id < numQuests; id++) {
		bindQuest(id);
		QUEST_PROGRESS = QUEST_INACTIVE;
		
		free(QUEST_NAME);
		QUEST_NAME = 0;
	}
}
void updateQuests(void)
{
	unsigned char questID;
	for(questID = 0; questID < numQuests; questID++){
		bindQuest(questID);
		if(isQuestActive())
			if(QUEST_OBJECTIVE.isObjectiveComplete()){
				QUEST_OBJECTIVE.finishObjective();
				QUEST_PROGRESS = QUEST_NEXT_OBJECTIVE;
				QUEST_OBJECTIVE.initObjective();
			}
	}
}
void startQuest(void)
{
	QUEST_PROGRESS = QUEST_ACTIVE;
	QUEST_OBJECTIVE.initObjective();
}
char isQuestCompleted()
{
	return QUEST_PROGRESS == QUEST_COMPLETED;
}
char isQuestInactive()
{
	return QUEST_PROGRESS == QUEST_INACTIVE;
}
char isQuestActive()
{
	return QUEST_PROGRESS >= QUEST_ACTIVE; // Return true if status is more than QUEST_ACTIVE
}
