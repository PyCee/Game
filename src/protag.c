
#include "protag.h"

#include "actor.h"

#include <stdint.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "math/vector.h"

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
	_protag->physics->Vel->X = 0.0;
	_protag->physics->Vel->Y = 0.0;
	_protag->physics->Vel->Z = 0.0;
	_protag->physics->Acc->X = 0.0;
	_protag->physics->Acc->Y = 0.0;
	_protag->physics->Acc->Z = 0.0;
	_protag->physics->Jrk->X = 0.0;
	_protag->physics->Jrk->Y = 0.0;
	_protag->physics->Jrk->Z = 0.0;
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
	if(protag->physics->Pos->Y < -1.0){
		protag->physics->Pos->Y += 2;
	}
	if(protag->physics->Pos->X < _Pos->Z*-1.0){
		protag->physics->Pos->X += _Pos->Z*2;
	}
	if(protag->physics->Pos->X > _Pos->Z*1.0){
		protag->physics->Pos->X -= _Pos->Z*2;
	}
	
	glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
 			glVertex2f(_Pos->X / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + protag->physics->Width) / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + protag->physics->Width) / _Pos->Z, (_Pos->Y + protag->physics->Height) / _Pos->Z);
 			glVertex2f(_Pos->X / _Pos->Z, (_Pos->Y + protag->physics->Height) / _Pos->Z);
		glEnd();
}
void Jump
(Actor_t *protag)
{
	if(protag->Control == 1){
		protag->physics->Vel->Y += 0.002;
	}
}
void setLeftTrue
(Actor_t *protag)
{
	protag->physics->Vel->X += -0.0008;
}
void setLeftFalse
(Actor_t *protag)
{
	protag->physics->Vel->X += 0.0008;
}
void setRightTrue
(Actor_t *protag)
{
	protag->physics->Vel->X += 0.0008;
}
void setRightFalse
(Actor_t *protag)
{
	protag->physics->Vel->X += -0.0008;
}
void setForwardTrue
(Actor_t *protag)
{
	protag->physics->Vel->Z = 0.0008;
}
void setForwardFalse
(Actor_t *protag)
{
	protag->physics->Vel->Z += -0.0008;
}
void setBackwardTrue
(Actor_t *protag)
{
	protag->physics->Vel->Z += -0.0008;
}
void setBackwardFalse
(Actor_t *protag)
{
	protag->physics->Vel->Z += 0.0008;
}
