
#include "physicsComponent.h"

#include "../actors.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "physics/vector.h"
#include "../math/quaternion.h"

void genPhysicsComponent() {
	POS = genVec3(0.0, 0.0, 0.0);
	
	vec3 *vel = malloc(sizeof(vec3));
	vec3 *acc = malloc(sizeof(vec3));
	vec3 *jrk = malloc(sizeof(vec3));
	*vel = genVec3(0.0, 0.0, 0.0);
	*acc = genVec3(0.0, 0.0, 0.0);
	*jrk = genVec3(0.0, 0.0, 0.0);
	bindVel(vel, 1, 0.0);
	bindAcc(acc, 1, 0.0);
	bindJrk(jrk, 1, 0.0);
	
	unsigned char index;
	for(index = 1; index < VEL_QTY; index++){
		VEL[index] = 0;
		VEL_MULT[index] = 0;
		VEL_YAW[index] = 0;
	}
	for(index = 1; index < ACC_QTY; index++){
		ACC[index] = 0;
		ACC_MULT[index] = 0;
		ACC_YAW[index] = 0;
	}
	for(index = 1; index < JRK_QTY; index++){
		JRK[index] = 0;
		JRK_MULT[index] = 0;
		JRK_YAW[index] = 0;
	}
	
	vec3 *grav = malloc(sizeof(vec3));
	*grav = genVec3(0.0, ACC_GRAVITY, 0.0);
	bindAcc(grav, -1.0, 0.0);
}
void freePhysicsComponent() {
	// Don't free vectors since they were not dynamically allocated
}

void updatePhysicsComponent(unsigned short deltaMS)// TODO: make this function more organized. Data structure for ______(JRK, ACC, VEL...)
{
	unsigned char index;
	for(index = 0; index < JRK_QTY; index++){
		if(JRK[index])
			*ACC[0] = addVec3(*ACC[0], scaleVec3(rotateVec3(*JRK[index], j, JRK_YAW[index]), JRK_MULT[index] * deltaMS));
	}
	
	for(index = 0; index < ACC_QTY; index++){
		if(ACC[index])
			*VEL[0] = addVec3(*VEL[0], scaleVec3(rotateVec3(*ACC[index], j, ACC_YAW[index]), ACC_MULT[index] * deltaMS));
	}
	for(index = 0; index < VEL_QTY; index++){
		if(VEL[index])
			POS = addVec3(POS, scaleVec3(rotateVec3(*VEL[index], j, VEL_YAW[index]), VEL_MULT[index] * deltaMS));
	}
}
unsigned char getOpenVel(void)
{
	unsigned char index;
	for(index = 0; index < VEL_QTY; index++)
		if(VEL[index] == 0)
			return index;
	printf("ERROR::Attempting to getOpenVel when Vel is full.\n");
	return VEL_QTY;
}
unsigned char getOpenAcc(void)
{
	unsigned char index;
	for(index = 0; index < ACC_QTY; index++)
		if(ACC[index] == 0)
			return index;
	printf("ERROR::Attempting to getOpenAcc when Acc is full.\n");
	return ACC_QTY;
}
unsigned char getOpenJrk(void)
{
	unsigned char index;
	for(index = 0; index < JRK_QTY; index++)
		if(JRK[index] == 0)
			return index;
	printf("ERROR::Attempting to getOpenJrk when Jrk is full.\n");
	return JRK_QTY;
}
unsigned char bindVel(vec3 *vel, float mult, float yaw)
{
	unsigned char index = getOpenVel();
	VEL[index] = vel;
	VEL_MULT[index] = mult;
	VEL_YAW[index] = yaw;
	return index;
}
unsigned char bindAcc(vec3 *acc, float mult, float yaw)
{
	unsigned char index = getOpenAcc();
	ACC[index] = acc;
	ACC_MULT[index] = mult;
	ACC_YAW[index] = yaw;
	return index;
}
unsigned char bindJrk(vec3 *jrk, float mult, float yaw)
{
	unsigned char index = getOpenJrk();
	JRK[index] = jrk;
	JRK_MULT[index] = mult;
	JRK_YAW[index] = yaw;
	return index;
}
void unBindVel(unsigned char index)
{
	VEL[index] = 0;
	VEL_MULT[index] = 0;
	VEL_YAW[index] = 0;
}
void unBindAcc(unsigned char index)
{
	ACC[index] = 0;
	ACC_MULT[index] = 0;
	ACC_YAW[index] = 0;
}
void unBindJrk(unsigned char index)
{
	JRK[index] = 0;
	JRK_MULT[index] = 0;
	JRK_YAW[index] = 0;
}
