
#include "protag.h"

#include "actor.h"

#include <stdint.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "math/vector.h"
#include "globalBinds.h"

void genProtag
(Actor_t **protag)
{
	genActor(protag);
	Actor_t *_protag = *protag;
	_protag->Update = UpdateProtag;
	_protag->Control = 1;
	_protag->physics->Terrain = 0;
	_protag->physics->Height = 0.2;
	_protag->physics->Width = 0.2;
	_protag->physics->Length = 0.2;
	_protag->physics->Pos->X = -1 * 0.75;
	_protag->physics->Pos->Y = -1 * 0.75;
	_protag->physics->Pos->Z = 1;
}
void freeProtag
(Actor_t **protag)
{
	Actor_t *_protag = *protag;
	freeActor(protag);
	*protag = 0;
}
void UpdateProtag
(Actor_t *protag, uint64_t deltaMS)
{
	Vec3_t *_Pos = protag->physics->Pos;
	
	glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
 			glVertex2f(_Pos->X / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + protag->physics->Width) / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + protag->physics->Width) / _Pos->Z, (_Pos->Y + protag->physics->Height) / _Pos->Z);
 			glVertex2f(_Pos->X / _Pos->Z, (_Pos->Y + protag->physics->Height) / _Pos->Z);
		glEnd();
}
void Jump
(void)
{
	if(GetControlledActor()->Control == 1){
		GetControlledActor()->physics->Vel->Y += 0.002;
	}
}
void ControlledActorForward
(void)
{
	GetControlledActor()->physics->Vel->Z += 1 * SPEED_FORWARD;
}
void ControlledActorLeft
(void)
{
	GetControlledActor()->physics->Vel->X += -1 * SPEED_FORWARD;
}
void ControlledActorBackward
(void)
{
	GetControlledActor()->physics->Vel->Z += -1 * SPEED_FORWARD;
}
void ControlledActorRight
(void)
{
	GetControlledActor()->physics->Vel->X += 1 * SPEED_FORWARD;
}
