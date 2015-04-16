
#include "globalBinds.h"

#include <stdio.h>
#include "character.h"


void BindCameraView
(Camera_t *camera)
{	cameraView = camera;	}
Camera_t *GetCameraView
()
{	return cameraView;	}
void UnbindCameraView
()
{	cameraView = 0;	}
void BindMapTerrain
(Character_t *terrain)
{	mapTerrain = terrain;	}
Character_t *GetMapTerrain
()
{	return mapTerrain;	}
void UnbindMapTerrain
()
{	mapTerrain = 0;	}
void BindControlledCharacter
(Character_t *character)
{	controlledCharacter = character;	}
Character_t *GetControlledCharacter
()
{	return controlledCharacter;	}
void UnbindControlledCharacter
()
{	controlledCharacter = 0;	}
