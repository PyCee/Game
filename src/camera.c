
#include "camera.h"

#include <stdlib.h>


void genCamera
(Camera_t **camera)
{
	*camera = malloc(sizeof(Camera_t));
	Camera_t *_camera = *camera;
	genVec3(&(_camera->Pos));
	genVec3(&(_camera->Norm));
}
void freeCamera
(Camera_t **camera)
{
	Camera_t *_camera = *camera;
	freeVec3(&(_camera->Pos));
	freeVec3(&(_camera->Norm));
	free(_camera);
	*camera = 0;
}
void CameraPitch
(Camera_t *camera, double angle)
{
	
}
void CameraYaw
(Camera_t *camera, double angle)
{
	
}
void CameraRoll
(Camera_t *camera, double angle)
{
	
}
