
#include "physicsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "physics/vector.h"

void genPhysicsComponent() {
	physics[getActor()].Pos = genVec3(0, 0, 0);
	physics[getActor()].Vel = genVec3(0, 0, 0);
	physics[getActor()].Acc = genVec3(0, 0, 0);
	physics[getActor()].Jrk = genVec3(0, 0, 0);
}
void freePhysicsComponent() {
	// Don't free vectors since they were not dynamically allocated
}

void updatePhysicsComponent(unsigned short deltaMS) {
	setAcc(
			genVec3(getAcc().vec[0] + deltaMS * getJrk().vec[0] * 1,
					getAcc().vec[1] + deltaMS * getJrk().vec[1] * 1,
					getAcc().vec[2] + deltaMS * getJrk().vec[2] * 1));
	setVel(
			genVec3(getVel().vec[0] + deltaMS * getAcc().vec[0] * 1,
					getVel().vec[1]
							+ deltaMS * (getAcc().vec[1] - ACC_GRAVITY) * 1,
					getVel().vec[2] + deltaMS * getAcc().vec[2] * 1));
	setPos(
			genVec3(getPos().vec[0] + deltaMS * getVel().vec[0] * 1,
					getPos().vec[1] + deltaMS * getVel().vec[1] * 1,
					getPos().vec[2] + deltaMS * getVel().vec[2] * 1));
}
void setSpeed(unsigned char speed) {
	physics[getActor()].speed = speed;
}
void setPos(vec3 pos) {
	physics[getActor()].Pos = pos;
}
void setVel(vec3 vel) {
	physics[getActor()].Vel = vel;
}
void setAcc(vec3 acc) {
	physics[getActor()].Acc = acc;
}
void setJrk(vec3 jrk) {
	physics[getActor()].Jrk = jrk;
}

vec3 getPos(void) {
	return physics[getActor()].Pos;
}
vec3 getVel(void) {
	return physics[getActor()].Vel;
}
vec3 getAcc(void) {
	return physics[getActor()].Acc;
}
vec3 getJrk(void) {
	return physics[getActor()].Jrk;
}
