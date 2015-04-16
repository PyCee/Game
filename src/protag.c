
#include "character.h"
#include "protag.h"

#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "math/vector.h"

void genProtag
(Character_t **protag)
{
	genCharacter(protag);
	Character_t *_protag = *protag;
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
(Character_t **protag)
{
	Character_t *_protag = *protag;
	freeCharacter(protag);
	*protag = 0;
}
void UpdateProtag
(Character_t *protag, uint64_t deltaMS)
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
(Character_t *protag)
{
	if(protag->Control == 1){
		protag->physics->Vel->Y += 0.002;
	}
}
void setLeftTrue
(Character_t *protag)
{
	protag->physics->Vel->X += -0.0008;
}
void setLeftFalse
(Character_t *protag)
{
	protag->physics->Vel->X += 0.0008;
}
void setRightTrue
(Character_t *protag)
{
	protag->physics->Vel->X += 0.0008;
}
void setRightFalse
(Character_t *protag)
{
	protag->physics->Vel->X += -0.0008;
}
void setForwardTrue
(Character_t *protag)
{
	protag->physics->Vel->Z = 0.0008;
}
void setForwardFalse
(Character_t *protag)
{
	protag->physics->Vel->Z += -0.0008;
}
void setBackwardTrue
(Character_t *protag)
{
	protag->physics->Vel->Z += -0.0008;
}
void setBackwardFalse
(Character_t *protag)
{
	protag->physics->Vel->Z += 0.0008;
}
