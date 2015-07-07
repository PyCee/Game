
#include "dataTypes.h"
#include "gruel.h"

#include "dyn_actors.h"

#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "math/vector.h"
#include "globalBinds.h"

U8 genGruel
(void)
{
	U8 actorID = AddActor();
	Dyn_Actors.identifier[actorID].ActorName = GRUEL_NAME;
	assignAIUpdate(actorID, UpdateGruel);
	Dyn_Actors.collisions[actorID].Height = 0.2;
	Dyn_Actors.collisions[actorID].Width = 0.2;
	Dyn_Actors.collisions[actorID].Length = 0.2;
	*getPosXPtr(actorID) = 1 * 0.4;
	*getPosYPtr(actorID) = -1 * 1.0;
	*getPosZPtr(actorID) = 1 * 1.0;
	return actorID;
}
void UpdateGruel
(U8 actorID, U16 deltaMS)
{
	/*Vec3_t *_Pos = gruel->physics->Pos;
	
	glColor3f(0.0f, 0.5f, 0.5f);
		glBegin(GL_POLYGON);
 			glVertex2f(_Pos->X / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + gruel->physics->Width) / _Pos->Z, _Pos->Y / _Pos->Z);
 			glVertex2f((_Pos->X + gruel->physics->Width) / _Pos->Z, (_Pos->Y + gruel->physics->Height) / _Pos->Z);
 			glVertex2f(_Pos->X / _Pos->Z, (_Pos->Y + gruel->physics->Height) / _Pos->Z);
		glEnd();
		*/
}
