#ifndef ACTOR_LIST
#define ACTOR_LIST

typedef struct actorList{
	int *list;
	int numActors;
} actorList;

actorList genActorList(void);
void freeActorList(actorList *);
void addActorListID(actorList *, int);
void removeActorListIndex(actorList *, int);
void removeActorListID(actorList *, int);

#endif /* ACTOR_LIST */
