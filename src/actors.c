
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
#include "actorComponents/AIComponent.h"
#include "actorComponents/lightingComponent.h"
#include "actorComponents/modelComponent.h"
#include "actorComponents/renderComponent.h"

#include "actorComponents/physics/octree.h"
#include "actorComponents/physics/checkOctree.h"

unsigned char numActors;
unsigned char allActorsPaused;


IdentifierComponent **identifier;
TimelineComponent **localTimeline;
CallbackComponent **callback;
AudioComponent **audio;
DirectionComponent **direction;
PhysicsComponent **physics;
AIComponent **ai;
LightingComponent **lighting;
ModelComponent **model;
RenderComponent **render;

static void genActor(void);

void initActorComponents(void)
{
	initDirectionComponent();
	initRender();
	initPhysics();
	allActorsPaused = 0;
	numActors = 0;
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
	printf("addActor: %d\n", numActors);
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
		ai = malloc(sizeof(AIComponent *));
		lighting = malloc(sizeof(LightingComponent *));
		model = malloc(sizeof(ModelComponent *));
		render = malloc(sizeof(RenderComponent *));
	} else if(nextFreeActor() == numActors){
		next = numActors;
		numActors += 1;
		identifier = realloc(identifier, sizeof(IdentifierComponent *) * numActors);
		callback = realloc(callback, sizeof(CallbackComponent *) * numActors);
		localTimeline = realloc(localTimeline, sizeof(TimelineComponent *) * numActors);
		audio = realloc(audio, sizeof(AudioComponent *) * numActors);
		direction = realloc(direction, sizeof(DirectionComponent *) * numActors);
		physics = realloc(physics, sizeof(PhysicsComponent *) * numActors);
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
	freePhysicsComponent();
	freeDirectionComponent();
	freeAudioComponent();
	freeTimelineComponent();
	freeCallbackComponent();
	freeIdentifierComponent();
	identifier[getActor()] = 0;
	printf("Freed Actor %d\n", getActor());
}
void freeAllActors(void)
{
	unsigned char actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			freeActor();
		actorID++;
	}
	printf("Freed %i Actors\n", numActors);
}
void updateActors(void)
{
	unsigned char actorID = 0;
	unsigned short localTime[numActors];
	while (actorID < numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			localTime[getActor()] = updateTimelineComponent();
		actorID++;
	}
	unsigned short deltaTime = SDL_GetTicks();
	printf("Updating Batch: \"Callback\"\n");
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			updateCallbackComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Callback\" Updated. Took %hu milliseconds\nUpdating Batch: \"Audio\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			updateAudioComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Audio\" Updated. Took %hu milliseconds\nUpdating Batch: \"Direction\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()]){
			updateDirectionComponent(localTime[actorID]);
		}
		actorID++;
	}
	printf("Batch: \"Direction\" Updated. Took %hu milliseconds\nUpdating Batch: \"Physics\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()]){
			updatePhysicsComponent(localTime[actorID]);
		}
		actorID++;
	}
	printf("Batch: \"Physics\" Updated. Took %hu milliseconds\nUpdating Batch: \"AI\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateAIComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"AI\" Updated. Took %hu milliseconds\nUpdating Batch: \"Lighting\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateLightingComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Lighting\" Updated. Took %hu milliseconds\nUpdating Batch: \"Rendering\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateRenderComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Rendering\" Updated. Took %hu milliseconds\nAll Batches Updated\n", SDL_GetTicks() - deltaTime);
}
void UselessFunction(void){}
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
	printf("Containing Octree ID: %hu\n", CONTAINING_OCTREE_NODE->octreeNodeID);
	printf("Actor %hhu Finished Printing\n\n", getActor());
}
