
#include "terrain.h"

#include "character.h"

void genTerrain
(Character_t **terrain)
{
	genCharacter(terrain);
	Character_t *_terrain = *terrain;
	_terrain->Update = UpdateTerrain;
	_terrain->Control = 0;
	_terrain->physics->Terrain = 1;
	_terrain->physics->Height = 0.2;
	_terrain->physics->Width = 10.0;
	_terrain->physics->Length = 0.2;
	_terrain->physics->Pos->X = -1 * 1.0;
	_terrain->physics->Pos->Y = -1 * 1.0;
	_terrain->physics->Pos->Z = -1 * 1.0;
}
void UpdateTerrain
(Character_t *terrain, uint64_t deltaMS)
{
}
