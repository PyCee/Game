#include "actorList.h"

#include <stdlib.h>
#include <stdio.h>
static int actorListContainsID(actorList *, int);
actorList genActorList(void)
{
	actorList actList;
	actList.list = 0;
	actList.numActors = 0;
	return actList;
}
void freeActorList(actorList *actList)
{
	if(actList->list)
		free(actList->list);
	actList->list = 0;
}
void addActorListID(actorList *actList, int id)
{
	if(actorListContainsID(actList, id) == 1)
		return;
	if(actList->numActors == 0){
		actList->numActors = 1;
		actList->list = malloc(sizeof(int));
	} else{
		actList->numActors += 1;
		actList->list = realloc(actList->list, sizeof(int) * actList->numActors);
	}
	actList->list[actList->numActors - 1] = id;
}
void removeActorListIndex(actorList *actList, int index)
{
	if(actList->numActors <= index)
		return;
	actorList *removedActList = malloc(sizeof(actorList));
	*removedActList = genActorList();
	int ind;
	for(ind = 0; ind < index - 1; ind++)
		addActorListID(removedActList, actList->list[removedActList->numActors]);
	for(; ind < actList->numActors; ind++)
		addActorListID(removedActList, actList->list[removedActList->numActors + 1]);
	freeActorList(actList);
	*actList = *removedActList;
	free(removedActList);
}
void removeActorListID(actorList *actList, int id)
{
	int index = actorListContainsID(actList, id);
	if(index == -1)
		return;
	removeActorListIndex(actList, index);
}
int nextUnusedActorListID(actorList actList)
{
	int largestID = -1;
	int index = 0;
	while(index < actList.numActors){
		if(largestID + 1 == actList.list[index]){
			largestID++;
			index = 0;
		} else index++;
	}
	return largestID + 1;
}
static int actorListContainsID(actorList *actList, int id)
{
	int index;
	for(index = 0; index < actList->numActors; index++)
		if(actList->list[index] == id)
			return index;
	return -1;
}
