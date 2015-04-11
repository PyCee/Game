
#include "physics.h"
#include <math.h>


void UpdatePhysics
(Physics_t *physics, uint64_t deltaMS)
{
	if (physics->Terrain == 0){
	physics->Acc.X += physics->Jerk.X * deltaMS;
	physics->Acc.Y += physics->Jerk.Y * deltaMS;
	physics->Acc.Z += physics->Jerk.Z * deltaMS;
	
	physics->Vel.X += physics->Acc.X * deltaMS;
	physics->Vel.Y += (physics->Acc.Y - GRAVITY) * deltaMS;
	physics->Vel.Z += physics->Acc.Z * deltaMS;
	
	physics->Pos.X += physics->Vel.X * deltaMS;
	physics->Pos.Y += physics->Vel.Y * deltaMS;
	physics->Pos.Z += physics->Vel.Z * deltaMS;
	}
}
/*int Hit
(Character_t *characterOne, character_t *characterTwo)
{
	
	
	//example, assuming direct hit
	//TODO: make function work with angles.
	Physics_t *physicsOne = characterOne->physics;
	Physics_t *physicsTwo = characterTwo->physics;
	
	if (physicsOne->Terrain == 1 && physicsTwo->Terrain == 1){
		printf("WHY IS THIS HAPPENING?!?!?!?!?!?!?\n :::Terrain vs. Terrain\n");
	}else if (physicsOne->Terrain == 1){
		physicsTwo
		return 0;
	} else if (physicsTwo->Terrain == 1){
		
		return 0;
	}
	double NetForce = getForce(*physicsOne) - getForce(*physicsTwo);
	double total = physicsOne->AccX + physicsOne->AccY + physicsOne->AccZ;
	double Acc = NetForce / physicsOne->mass
	physicsOne->AccX += (physicsOne->AccX / total) * (Acc + (Acc * physicsOne->Bounciness));
	physicsOne->AccY += (physicsOne->AccY / total) * (Acc + (Acc * physicsOne->Bounciness));
	physicsOne->AccZ += (physicsOne->AccZ / total) * (Acc + (Acc * physicsOne->Bounciness));
	total = physicsOne->AccX + physicsOne->AccY + physicsOne->AccZ;
	Acc = NetForce / physicsTwo->mass
	physicsTwo->AccX += (physicsTwo->AccX / total) * (Acc + (Acc * physicsTwo->Bounciness));
	physicsTwo->AccY += (physicsTwo->AccY / total) * (Acc + (Acc * physicsTwo->Bounciness));
	physicsTwo->AccZ += (physicsTwo->AccZ / total) * (Acc + (Acc * physicsTwo->Bounciness));
	Hurt(characterOne, NetForce * (physicsOne->Bounciness * BOUNCY_DMG_REDUCTION));
	Hurt(characterTwo, NetForce * (physicsTwo->Bounciness * BOUNCY_DMG_REDUCTION));
	
	return 1;
}
*/
