
#include "buzz.h"

#include "../actors.h"
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../actorSelection.h"
#include "../actorComponents/physics/physicsAttributeController.h"
#include "../actorComponents/physics/vector.h"
#include "../actorComponents/physics/collisionTypes/collisionCapsule.h"
#include "../actorComponents/physics/collisionTypes/collisionPoint.h"
#include "../actorComponents/physics/collisionController.h"
#include "../math/quaternion.h"

#include "../actorComponents/directionComponent.h"
#include "../actorComponents/AIComponent.h"
#include "../actorComponents/physicsComponent.h"
#include "../actorComponents/physics/applyImpulses.h"
#include "../actorComponents/callback/callbackController.h"
#include "../actorComponents/callback/distanceCheck.h"
#include "../actorComponents/callback/timeout.h"

static void startBuzzMove(callbackController);
static void endBuzzMove(callbackController);

void UpdateBuzz(unsigned short deltaMS)
{
	callbackController temp;
	switch(AI_STATE){
	case BUZZ_AI_STATE_INIT:
		*VELOCITY = genVec3(0.0, 0.0, 0.0);
		*GRAVITY = genVec3(0.0, 0.0, 0.0);
		startBuzzMove(temp);
		break;
	case BUZZ_AI_STATE_IDLE:
		break;
	case BUZZ_AI_STATE_MOVE:
		break;
	default:
		break;
	}
}
static void startBuzzMove(callbackController call)
{
	float randX = (float)rand()/(float)(RAND_MAX/12) - 6;
	float randY = (float)rand()/(float)(RAND_MAX/3 - 1);
	float randZ = -(float)rand()/(float)(RAND_MAX/12);
	*AI_MOVE_TARGET = genVec3(randX, randY, randZ);
	
	*AI_CONTROLLED_MOVEMENT = scaleVec3(normalizeVec3(subtractVec3Vec3(*AI_MOVE_TARGET, *POSITION)), SPEED);
	callbackController *move = malloc(sizeof(callbackController));
	*move = genDistanceCheck(endBuzzMove, 0, AI_MOVE_TARGET);
	enableCallbackController(move);
	AI_STATE = BUZZ_AI_STATE_MOVE;
	*MOVEMENT = *AI_CONTROLLED_MOVEMENT;
	VIEWSTATE = VIEWSTATE_MOVE;
}
static void endBuzzMove(callbackController call)
{
	*POSITION = *AI_MOVE_TARGET;
	*AI_CONTROLLED_MOVEMENT = genVec3(0.0, 0.0, 0.0);
	callbackController *idle = malloc(sizeof(callbackController));
	*idle = genTimeout(startBuzzMove, (float)rand()/(float)(RAND_MAX/5000) + 2000);
	enableCallbackController(idle);
	AI_STATE = BUZZ_AI_STATE_IDLE;
	VIEWSTATE = VIEWSTATE_FREE_ROAM;
}
