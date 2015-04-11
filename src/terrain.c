
#include "terrain.h"

#include "character.h"

void genTerrain
(Character_t **terrain)
{
	(*terrain) = malloc(sizeof(Character_t));
	(*terrain)->Update = UpdateTerrain;
	(*terrain)->Control = 0;
	(*terrain)->physics.Terrain = 1;
	(*terrain)->physics.Height = 0.2;
	(*terrain)->physics.Width = 2.0;
	(*terrain)->physics.Length = 0.2;
	(*terrain)->physics.Pos.X = -1 * 1.0;
	(*terrain)->physics.Pos.Y = -1 * 1.0;
	(*terrain)->physics.Pos.Z = -1 * 1.0;
	(*terrain)->physics.Vel.X = 0.0;
	(*terrain)->physics.Vel.Y = 0.0;
	(*terrain)->physics.Vel.Z = 0.0;
	(*terrain)->physics.Acc.X = 0.0;
	(*terrain)->physics.Acc.Y = 0.0;
	(*terrain)->physics.Acc.Z = 0.0;
	(*terrain)->physics.Jerk.X = 0.0;
	(*terrain)->physics.Jerk.Y = 0.0;
	(*terrain)->physics.Jerk.Z = 0.0;
}
void UpdateTerrain
(Character_t *terrain, uint64_t deltaMS)
{
}
