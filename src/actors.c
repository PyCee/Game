
#include "actors.h"

#include <stdlib.h>
#include <stdio.h>
#include "actorComponents/physics/vector.h"
#include "actorComponents/physics/physicsAttributeController.h"
#include "actorSelection.h"
#include <strings.h>

#include "actorComponents/identifierComponent.h"
#include "actorComponents/callbackComponent.h"
#include "actorComponents/timelineComponent.h"
#include "actorComponents/audioComponent.h"
#include "actorComponents/directionComponent.h"
#include "actorComponents/physicsComponent.h"
#include "actorComponents/collisionsComponent.h"
#include "actorComponents/AIComponent.h"
#include "actorComponents/lightingComponent.h"
#include "actorComponents/modelComponent.h"
#include "actorComponents/renderComponent.h"

unsigned char numActors;
unsigned char allActorsPaused;
static void genActor(void);

void initActorComponents(void)
{
	initDirectionComponent();
	initRender();
	allActorsPaused = 0;
}
static unsigned char nextFreeActor(void)
{
	unsigned char actorID = 0;
	
	while (actorID < numActors) {
		if(!identifier[actorID])
			return actorID;
		actorID++;
	}
	return numActors;
}
unsigned char addActor(void)
{
	unsigned char next;
	if(numActors == 0){
		numActors = 1;
		next = 0;
		identifier = malloc(sizeof(IdentifierComponent *));
		callback = malloc(sizeof(CallbackComponent *));
		localTimeline = malloc(sizeof(TimelineComponent *));
		audio = malloc(sizeof(AudioComponent *));
		direction = malloc(sizeof(DirectionComponent *));
		physics = malloc(sizeof(PhysicsComponent *));
		collisions = malloc(sizeof(CollisionsComponent *));
		ai = malloc(sizeof(AIComponent *));
		lighting = malloc(sizeof(LightingComponent *));
		model = malloc(sizeof(ModelComponent *));
		render = malloc(sizeof(RenderComponent *));
	} else if(nextFreeActor() == numActors){
		numActors += 1;
		next = numActors - 1;
		identifier = realloc(identifier, sizeof(IdentifierComponent *) * numActors);
		callback = realloc(callback, sizeof(CallbackComponent *) * numActors);
		localTimeline = realloc(localTimeline, sizeof(TimelineComponent *) * numActors);
		audio = realloc(audio, sizeof(AudioComponent *) * numActors);
		direction = realloc(direction, sizeof(DirectionComponent *) * numActors);
		physics = realloc(physics, sizeof(PhysicsComponent *) * numActors);
		collisions = realloc(collisions, sizeof(CollisionsComponent *) * numActors);
		ai = realloc(ai, sizeof(AIComponent *));
		lighting = realloc(lighting, sizeof(LightingComponent *) * numActors);
		model = realloc(model, sizeof(ModelComponent *) * numActors);
		render = realloc(render, sizeof(RenderComponent *) * numActors);
	}
	bindActor(next);
	identifier[next] = malloc(sizeof(IdentifierComponent));
	callback[next] = malloc(sizeof(CallbackComponent));
	localTimeline[next] = malloc(sizeof(TimelineComponent));
	audio[next] = malloc(sizeof(AudioComponent));
	direction[next] = malloc(sizeof(DirectionComponent));
	physics[next] = malloc(sizeof(PhysicsComponent));
	collisions[next] = malloc(sizeof(CollisionsComponent));
	ai[next] = malloc(sizeof(AIComponent));
	lighting[next] = malloc(sizeof(LightingComponent));
	model[next] = malloc(sizeof(ModelComponent));
	render[next] = malloc(sizeof(RenderComponent));
	genActor();
	
	printf("Added ActorID: %d\n", next);
	return next;
}
static void genActor(void)
{
	printf("Gening Actor %d\n", getActor());
	genIdentifierComponent();
	genCallbackComponent();
	genTimelineComponent();
	genAudioComponent();
	genDirectionComponent();
	genPhysicsComponent();
	genCollisionsComponent();
	genAIComponent();
	genLightingComponent();
	genRenderComponent();
}
void freeActor(void)
{
	if (!identifier[getActor()])
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
	freeTimelineComponent();
	freeCallbackComponent();
	freeIdentifierComponent();
	identifier[getActor()] = 0;
	printf("Freed Actor %d\n", getActor());
}
void freeAllActors(void) {
	unsigned char actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			freeActor();
		actorID++;
	}
	printf("Freed %i \n", numActors);
}
void updateActors(void) {
	unsigned char actorID = 0;
	unsigned short localTime[numActors];
	while (actorID < numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			localTime[getActor()] = updateTimelineComponent();
		actorID++;
	}
	printf("Updating Batch: \"Callback\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			updateCallbackComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Callback\" Updated\nUpdating Batch: \"Audio\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			updateAudioComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Audio\" Updated\nUpdating Batch: \"Direction\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()]){
			updateDirectionComponent(localTime[actorID]);
		}
		actorID++;
	}
	printf("Batch: \"Direction\" Updated\nUpdating Batch: \"Physics\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()]){
			if (strcmp(TYPE, "dynamic") == 0){
				updatePhysicsComponent(localTime[actorID]);
			}
		}
		actorID++;
	}
	printf("Batch: \"Physics\" Updated\nUpdating Batch: \"Collisions\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateCollisionsComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Collisions\" Updated\nUpdating Batch: \"AI\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateAIComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"AI\" Updated\nUpdating Batch: \"Lighting\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateLightingComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Lighting\" Updated\nUpdating Batch: \"Rendering\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
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
		while (actorID < numActors) {
			bindActor(actorID);
			if(identifier[getActor()])
				unpauseTimeline();
			actorID++;
		}
		allActorsPaused = 0;
	}
	else{
		while (actorID < numActors) {
			bindActor(actorID);
			if(identifier[getActor()])
				pauseTimeline();
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
	printf("Data File: %s\n", ORIGIN_FILE);
	printf("Position:");
	printVec3(*POSITION);
	printf("Forward:");
	printVec3(*FORWARD);
	printf("Actor %hhu Finished Printing\n\n", getActor());
}
