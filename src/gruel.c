
#include "gruel.h"

#include "actor.h"

#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "math/vector.h"
#include "globalBinds.h"

void genGruel
(Actor_t **gruel)
{
	genActor(gruel);
	Actor_t *_gruel = *gruel;
	_gruel->Update = UpdateGruel;
	_gruel->Control = 1;
	_gruel->physics->Terrain = 0;
	_gruel->physics->Height = 0.3;
	_gruel->physics->Width = 0.3;
	_gruel->physics->Length = 0.3;
	_gruel->physics->Pos->X = 1 * 0.4;
	_gruel->physics->Pos->Y = -1 * 0.4;
	_gruel->physics->Pos->Z = 1;
}
void freeGruel
(Actor_t **gruel)
{
	Actor_t *_gruel = *gruel;
	freeActor(gruel);
	*gruel = 0;
}
void UpdateGruel
(Actor_t *gruel, uint64_t deltaMS)
{
	Vec3_t *_Pos = gruel->physics->Pos;
	
	glColor3f(0.0f, 0.5f, 0.5f);
		glBegin(GL_POLYGON);
 			glVertex2f(_Pos->X / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + gruel->physics->Width) / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + gruel->physics->Width) / _Pos->Z, (_Pos->Y + gruel->physics->Height) / _Pos->Z);
 			glVertex2f(_Pos->X / _Pos->Z, (_Pos->Y + gruel->physics->Height) / _Pos->Z);
		glEnd();
}
