
#include "actors.h"

#include <stdlib.h>
#include <stdio.h>
#include "actorComponents/physics/vector.h"
#include "actorComponents/physics/physicsAttributeController.h"
#include "actorSelection.h"
#include <strings.h>

#include "actorComponents/identifierComponent.h"
#include "actorComponents/callbackComponent.h"
#include "actorComponents/timeLineComponent.h"
#include "actorComponents/audioComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "actorComponents/AIComponent.h"
#include "actorComponents/lightingComponent.h"
#include "actorComponents/modelComponent.h"
#include "actorComponents/renderComponent.h"

unsigned char ActiveActor[MAX_ACTOR_COUNT]; // Tells whether an Actor is active or not
unsigned char allActorsPaused;

void initActorComponents(void){
	identifier = malloc(MAX_ACTOR_COUNT * sizeof(IdentifierComponent));
	callback = malloc(MAX_ACTOR_COUNT * sizeof(CallbackComponent));
	timeLine = malloc(MAX_ACTOR_COUNT * sizeof(TimeLineComponent));
	audio = malloc(MAX_ACTOR_COUNT * sizeof(AudioComponent));
	direction = malloc(MAX_ACTOR_COUNT * sizeof(DirectionComponent));
	physics = malloc(MAX_ACTOR_COUNT * sizeof(PhysicsComponent));
	collisions = malloc(MAX_ACTOR_COUNT * sizeof(CollisionsComponent));
	AI = malloc(MAX_ACTOR_COUNT * sizeof(AIComponent));
	lighting = malloc(MAX_ACTOR_COUNT * sizeof(LightingComponent));
	model = malloc(MAX_ACTOR_COUNT * sizeof(ModelComponent));
	render = malloc(MAX_ACTOR_COUNT * sizeof(RenderComponent));
	
	initDirectionComponent();
	initRender();
	allActorsPaused = 0;
}
static void bindFirstInactiveActor(void) {
	unsigned char actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (!ActiveActor[getActor()])
			return;
		actorID++;
	}
	printf(
			"ERROR::getFirstInactiveActor(void) called after ActiveActors array was filled::\
			First Inactive Actor: %d::MAX_ACTOR_COUNT: %d\n",
			actorID, MAX_ACTOR_COUNT);
	// TODO: What Should I Return Here? For An Invalid actorID.
}
unsigned char addActor(void) {
	bindFirstInactiveActor();
	ActiveActor[getActor()] = 1;
	printf("Adding ActorID: %d\n", getActor());
	return getActor();
}
static void genActor(void) {
	if (ActiveActor[getActor()])
		return;
	printf("Gening Actor %d\n", getActor());
	genIdentifierComponent();
	genCallbackComponent();
	genTimeLineComponent();
	genAudioComponent();
	genDirectionComponent();
	genPhysicsComponent();
	genCollisionsComponent();
	genAIComponent();
	genLightingComponent();
	genRenderComponent();
}
void freeActor(void) {
	if (!ActiveActor[getActor()])
		return;
	printf("Freeing Actor %d\n", getActor());
	freeRenderComponent();
	freeModelComponent();
	freeLightingComponent();
	freeAIComponent();
	freeCollisionsComponent();
	freePhysicsComponent();
	freeDirectionComponent();
	freeAudioComponent();
	freeTimeLineComponent();
	freeCallbackComponent();
	freeIdentifierComponent();
	ActiveActor[getActor()] = 0;
}
void genAllActors(void) {
	unsigned char actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		ActiveActor[getActor()] = 0;
		genActor();
		actorID++;
	}
}
void freeAllActors(void) {
	unsigned char actorID = 0;
	unsigned char actorCount = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			actorCount++;
		freeActor();
		actorID++;
	}
	printf("Freed %i \n", actorCount);
}
void updateActors(void) {
	unsigned char actorID = 0;
	unsigned short localTime[MAX_ACTOR_COUNT];
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			localTime[getActor()] = updateTimeLineComponent();
		actorID++;
	}
	printf("Updating Batch: \"Callback\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			updateCallbackComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Callback\" Updated\nUpdating Batch: \"Audio\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			updateAudioComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Audio\" Updated\nUpdating Batch: \"Direction\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()]){
			updateDirectionComponent(localTime[actorID]);
		}
		actorID++;
	}
	printf("Batch: \"Direction\" Updated\nUpdating Batch: \"Physics\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()]){
			if (strcmp(TYPE, "dynamic") == 0){
				updatePhysicsComponent(localTime[actorID]);
			}
		}
		actorID++;
	}
	printf("Batch: \"Physics\" Updated\nUpdating Batch: \"Collisions\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			updateCollisionsComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Collisions\" Updated\nUpdating Batch: \"AI\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			updateAIComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"AI\" Updated\nUpdating Batch: \"Lighting\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			updateLightingComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Lighting\" Updated\nUpdating Batch: \"Rendering\"\n");
	actorID = 0;
	while (actorID < MAX_ACTOR_COUNT) {
		bindActor(actorID);
		if (ActiveActor[getActor()])
			updateRenderComponent(localTime[actorID]);
		actorID++;
	}
	printf("All Batches Updated\n");
}
void UselessFunction
(void)
{
}
void toggleAllPause(void)
{
	printf("Toggle pause called.\n");
	unsigned char actorID = 0;
	if(allActorsPaused){
		while (actorID < MAX_ACTOR_COUNT) {
			bindActor(actorID);
			unpauseTimeLine();
			actorID++;
		}
		allActorsPaused = 0;
	}
	else{
		while (actorID < MAX_ACTOR_COUNT) {
			bindActor(actorID);
			pauseTimeLine();
			actorID++;
		}
		allActorsPaused = 1;
	}
}
void printActor(void)
{
	printf("\nPrinting Actor Number: %hhu\n", getActor());
	printf("Name: %s\n", NAME);
	printf("Type: %s\n", TYPE);
	printf("Data File: %s\n", identifier[getActor()].originFile);
	printf("Position:");
	printVec3(*POSITION);
	printf("Forward:");
	printVec3(*FORWARD);
	printf("Actor %hhu Finished Printing\n\n", getActor());
}
