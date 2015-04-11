#include "character.h"

void Update(Character_t *character, uint64_t deltaMS)
{
	UpdatePhysics(&character->physics, deltaMS);
	character->Update(character, deltaMS);
}

void UselessUpdate(Character_t *character, uint64_t deltaMS)
{
}

void setBounds(Character_t *character, double width, double height)
{
	character->physics.Width = width;
	character->physics.Height = height;
}
char CheckBoundingBoxCollision(Character_t *characterOne, Character_t *characterTwo)
{
	if (characterOne->physics.Pos.X < characterTwo->physics.Pos.X + characterTwo->physics.Width &&
   characterOne->physics.Pos.X + characterOne->physics.Width > characterTwo->physics.Pos.X &&
   characterOne->physics.Pos.Y < characterTwo->physics.Pos.Y + characterTwo->physics.Height &&
   characterOne->physics.Pos.Y + characterOne->physics.Height > characterTwo->physics.Pos.Y/* &&
   characterOne->physics.Pos.Z < characterTwo->physics.Pos.Z + characterTwo->physics.Length &&
   characterOne->physics.Pos.Z + characterOne->physics.Length > characterTwo->physics.Pos.Z */)
    // collision detected!
  	return 1;
	return 0;
}

void Move(Character_t *character, double x, double y)
{
	character->physics.Pos.X += x;
	character->physics.Pos.Y += y;
}
void setPos(Character_t *character, double x, double y)
{
	character->physics.Pos.X = x;
	character->physics.Pos.Y = y;
}


