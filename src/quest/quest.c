#include "quest.h"
#include "objective.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Quest quest[] = {};
unsigned char numQuests;
unsigned char QuestID;

unsigned char getQuest(void)
{
	return QuestID;
}
unsigned char bindQuest(unsigned char id)
{
	QuestID = id;
}
void loadQuests(FILE *saveFile)
{
	numQuests = sizeof(quest) / sizeof(Quest);
	//load quests from savefile
	unsigned char id = 0;
	for(;id < numQuests; id++) {
		QUEST.objective = malloc(sizeof(Objective) * 255);
		QUEST.progress = QUEST_INACTIVE;//TODO: get quest status from file
		bindQuest(id);
		
		unsigned char ob = 2;
		for(;ob < 255; ob++){
			//get objective from file
			//QUEST.objective[ob]
			
			//setIsObjectiveComplete(str); // set quest objectve from file
		}
		
		char *questName = 0;//TODO: get Quest Name from file
		QUEST.name = malloc(strlen(questName));
		strcpy(QUEST.name, questName);
	}
}
void saveQuests(FILE *saveFile)
{
	unsigned char id = 0;
	for(;id < numQuests; id++) {
		//quest[id].progress = QUEST_COMPLETED;//TODO: write to file
		
		//TODO: write to file
		//strcpy(quest[id].name, questName);
	}
}
void resetQuests(void)
{
	unsigned char id = 0;
	for(;id < numQuests; id++) {
		bindQuest(id);
		QUEST.progress = QUEST_INACTIVE;
		
		free(QUEST.name);
		QUEST.name = 0;
	}
}
void updateQuests(void)
{
	unsigned char questID = 0;
	for(; questID < numQuests; questID++){
		bindQuest(questID);
		if(isQuestActive()){
			if(OBJECTIVE.isObjectiveComplete()){
				OBJECTIVE.finishObjective();
				QUEST.progress++;
				OBJECTIVE.initObjective();
			}
		}
	}
}
void startQuest(void)
{
	QUEST.progress = QUEST_ACTIVE;
	OBJECTIVE.initObjective();
}
char isQuestCompleted()
{
	return QUEST.progress == QUEST_COMPLETED;
}
char isQuestInactive()
{
	return QUEST.progress == QUEST_INACTIVE;
}
char isQuestActive()
{
	return QUEST.progress >= QUEST_ACTIVE; // Return true if status is more than QUEST_ACTIVE
}
