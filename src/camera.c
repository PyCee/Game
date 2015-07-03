
#include "dataTypes.h"
#include "camera.h"

#include <stdlib.h>
#include "math/gMath.h"
#include "actor.h"


void genCamera
(Camera_t **camera)
{
	genActor(camera);
	Camera_t *_camera = *camera;
}
void freeCamera
(Camera_t **camera)
{
	freeActor(camera);
	*camera = 0;
}
void CameraPitch
(Camera_t *camera, F64 angle)
{
	camera->direction = Pitch(camera->direction, degRad(angle));
	NormalizeNormal3(camera->direction);
}
void CameraYaw
(Camera_t *camera, F64 angle)
{
	camera->direction = Yaw(camera->direction, degRad(angle));
	NormalizeNormal3(camera->direction);
}
void CameraRoll
(Camera_t *camera, F64 angle)
{
	camera->direction = Roll(camera->direction, degRad(angle));
	NormalizeNormal3(camera->direction);
}
