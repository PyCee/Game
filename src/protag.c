
#include "character.h"
#include "protag.h"

#include <SDL2/SDL_opengl.h>

void genProtag
(Character_t **protag)
{
	(*protag) = malloc(sizeof(Character_t));
	Character_t *_protag = *protag;
	_protag->Update = UpdateProtag;
	_protag->Control = 1;
	_protag->physics.Terrain = 0;
	_protag->physics.Height = 0.2;
	_protag->physics.Width = 0.2;
	_protag->physics.Length = 0.2;
	_protag->physics.Pos.X = -1 * 0.75;
	_protag->physics.Pos.Y = -1 * 0.75;
	_protag->physics.Pos.Z = -1 * 0.75;
	_protag->physics.Vel.X = 0.0;
	_protag->physics.Vel.Y = 0.0;
	_protag->physics.Vel.Z = 0.0;
	(*protag)->physics.Acc.X = 0.0;
	_protag->physics.Acc.Y = 0.0;
	_protag->physics.Acc.Z = 0.0;
	_protag->physics.Jerk.X = 0.0;
	_protag->physics.Jerk.Y = 0.0;
	_protag->physics.Jerk.Z = 0.0;
}
void UpdateProtag
(Character_t *protag, uint64_t deltaMS)
{
	if(protag->physics.Pos.Y < -1.0){
		protag->physics.Pos.Y += 2;
	}
	if(protag->physics.Pos.X < -1.0){
		protag->physics.Pos.X += 2;
	}
	if(protag->physics.Pos.X > 1.0){
		protag->physics.Pos.X -= 2;
	}
	
	glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_POLYGON);
 			glVertex2f(protag->physics.Pos.X, protag->physics.Pos.Y);
 			glVertex2f(protag->physics.Pos.X + protag->physics.Width, protag->physics.Pos.Y);
 			glVertex2f(protag->physics.Pos.X + protag->physics.Width, protag->physics.Pos.Y + protag->physics.Height);
 			glVertex2f(protag->physics.Pos.X, protag->physics.Pos.Y + protag->physics.Height);
		glEnd();
  	
  	// next 2 draws are for the image of wrapint around the screen. take out later.
		glBegin(GL_POLYGON);
 			glVertex2f(2+protag->physics.Pos.X, protag->physics.Pos.Y);
 			glVertex2f(2+protag->physics.Pos.X + protag->physics.Width, protag->physics.Pos.Y);
 			glVertex2f(2+protag->physics.Pos.X + protag->physics.Width, protag->physics.Pos.Y + protag->physics.Height);
 			glVertex2f(2+protag->physics.Pos.X, protag->physics.Pos.Y + protag->physics.Height);
		glEnd();
		glBegin(GL_POLYGON);
 			glVertex2f(-2+protag->physics.Pos.X, protag->physics.Pos.Y);
 			glVertex2f(-2+protag->physics.Pos.X + protag->physics.Width, protag->physics.Pos.Y);
 			glVertex2f(-2+protag->physics.Pos.X + protag->physics.Width, protag->physics.Pos.Y + protag->physics.Height);
 			glVertex2f(-2+protag->physics.Pos.X, protag->physics.Pos.Y + protag->physics.Height);
		glEnd();
}
void Jump
(Character_t *protag)
{
	if(protag->Control == 1){
		protag->physics.Vel.Y += 0.002;
	}
}
void setLeftTrue
(Character_t *protag)
{
	protag->physics.Vel.X += -0.0008;
}
void setLeftFalse
(Character_t *protag)
{
	protag->physics.Vel.X += 0.0008;
}
void setRightTrue
(Character_t *protag)
{
	protag->physics.Vel.X += 0.0008;
}
void setRightFalse
(Character_t *protag)
{
	protag->physics.Vel.X += -0.0008;
}
void setForwardTrue
(Character_t *protag)
{
	protag->physics.Vel.Z = 0.0008;
}
void setForwardFalse
(Character_t *protag)
{
	protag->physics.Vel.Z += -0.0008;
}
void setBackwardTrue
(Character_t *protag)
{
	protag->physics.Vel.Z += -0.0008;
}
void setBackwardFalse
(Character_t *protag)
{
	protag->physics.Vel.Z += 0.0008;
}
