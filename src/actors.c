
#include "actors.h"

#include <stdlib.h>
#include <stdio.h>
#include "actorComponents/physics/vector.h"
#include "actorComponents/physics/physicsAttributeController.h"
#include "actorSelection.h"
#include "loadActorData.h"
#include "actorList.h"
#include <strings.h>
#include "shaders/backBuffer.h"
#include "shaders/geometry.h"
#include "shaders/shader_program.h"
#include "shaders/buffer_plane.h"
#include "shaders/deferred_lighting.h"

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

actorList actors;
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
	actors = genActorList();
}
unsigned int addActor(const unsigned char *loadFile)
{
	printf("Adding Actor: %d\n", actors.numActors);
	unsigned int next;
	if(actors.numActors == 0){
		addActorListID(&actors, 0);
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
	} else if(nextUnusedActorListID(actors) == actors.numActors){
		next = actors.numActors;
		addActorListID(&actors, actors.numActors);
		identifier = realloc(identifier, sizeof(IdentifierComponent *) * actors.numActors);
		callback = realloc(callback, sizeof(CallbackComponent *) * actors.numActors);
		localTimeline = realloc(localTimeline, sizeof(TimelineComponent *) * actors.numActors);
		audio = realloc(audio, sizeof(AudioComponent *) * actors.numActors);
		direction = realloc(direction, sizeof(DirectionComponent *) * actors.numActors);
		physics = realloc(physics, sizeof(PhysicsComponent *) * actors.numActors);
		ai = realloc(ai, sizeof(AIComponent *) * actors.numActors);
		lighting = realloc(lighting, sizeof(LightingComponent *) * actors.numActors);
		model = realloc(model, sizeof(ModelComponent *) * actors.numActors);
		render = realloc(render, sizeof(RenderComponent *) * actors.numActors);
	} else{
		next = nextUnusedActorListID(actors);
		addActorListID(&actors, next);
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
	loadActorData(loadFile);
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
	unsigned int actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			freeActor();
		actorID++;
	}
	printf("Freed %i Actors\n", actors.numActors);
}
void updateActors(void)
{
	unsigned int actorID = 0;
	unsigned short localTime[actors.numActors];
	for(actorID = 0; actorID < actors.numActors; actorID++){
		bindActor(actorID);
		if(identifier[getActor()])
			localTime[getActor()] = updateTimelineComponent();
	}
	unsigned short deltaTime = SDL_GetTicks();
	printf("Updating Batch: \"Callback\"\n");
	actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);// bindActor(actors.list[actorID) (and all repeats below)
		if(identifier[getActor()])
			updateCallbackComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Callback\" Updated. Took %hu milliseconds\nUpdating Batch: \"Audio\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if(identifier[getActor()])
			updateAudioComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Audio\" Updated. Took %hu milliseconds\nUpdating Batch: \"Direction\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if (identifier[getActor()]){
			updateDirectionComponent(localTime[actorID]);
		}
		actorID++;
	}
	printf("Batch: \"Direction\" Updated. Took %hu milliseconds\nUpdating Batch: \"Physics\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if (identifier[getActor()]){
			updatePhysicsComponent(localTime[actorID]);
		}
		actorID++;
	}
	printf("Batch: \"Physics\" Updated. Took %hu milliseconds\nUpdating Batch: \"AI\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateAIComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"AI\" Updated. Took %hu milliseconds\nUpdating Batch: \"Lighting\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	actorID = 0;
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateLightingComponent(localTime[actorID]);
		actorID++;
	}
	printf("Batch: \"Lighting\" Updated. Took %hu milliseconds\nUpdating Batch: \"Rendering\"\n", SDL_GetTicks() - deltaTime);
	deltaTime = SDL_GetTicks();
	
	unsigned short temp_deltaTime = SDL_GetTicks();
	actorID = 0;
	
	glFinish();
	
	//TODO discover why the draws are taking so long
	//TODO clean up the rendering below
	glBindFramebuffer(GL_FRAMEBUFFER, geometry_buffer);
	
	GLenum windowBuffClear[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2};
	glDrawBuffers(3, windowBuffClear);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glUseProgram(*geometry_shader->program);
	
	while (actorID < actors.numActors) {
		bindActor(actorID);
		if (identifier[getActor()])
			updateRenderComponent(localTime[actorID]);
		actorID++;
	}
	
	glFinish();
	printf("gbuffer Took %hu milliseconds\n", SDL_GetTicks() - temp_deltaTime);
	temp_deltaTime = SDL_GetTicks();
	
	glFinish();
	glBindFramebuffer(GL_FRAMEBUFFER, deferred_lighting_buffer);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(*deferred_lighting_shader->program);
	
	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, geometry_buffer_position_map);
	
	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, geometry_buffer_normal_map);
	
	glActiveTexture(GL_TEXTURE0 + 2);
	glBindTexture(GL_TEXTURE_2D, geometry_buffer_color_specularity_map);
	
	draw_buffer_plane();
	
	glFinish();
	printf("deferred shader Took %hu milliseconds\n", SDL_GetTicks() - temp_deltaTime);
	temp_deltaTime = SDL_GetTicks();
	
	glFinish();
	glBindFramebuffer(GL_FRAMEBUFFER, backBuffer);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(*buffer_plane_shader->program);
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, deferred_lighting_texture);
	
	draw_buffer_plane();
	
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	glFinish();
	printf("to backbuffer Took %hu milliseconds\n", SDL_GetTicks() - temp_deltaTime);
	temp_deltaTime = SDL_GetTicks();
	
	printf("Batch: \"Rendering\" Updated. Took %hu milliseconds\nAll Batches Updated\n", SDL_GetTicks() - deltaTime);
}
void UselessFunction(void){}
void toggleAllPause(void)
{
	printf("Toggle pause called.\n");
	unsigned char actorID = 0;
	if(allActorsPaused){
		while (actorID < actors.numActors) {
			bindActor(actorID);
			if(identifier[getActor()])
				unpauseTimeline();
			actorID++;
		}
		allActorsPaused = 0;
	}
	else{
		while (actorID < actors.numActors) {
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
