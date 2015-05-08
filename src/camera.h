
#ifndef _CAMERA_
#define _CAMERA_

typedef struct _Vec3_t Vec3_t;

typedef struct _Camera_t
{
	Vec3_t *Pos;
	Vec3_t *Norm;
} Camera_t;

void genCamera(Camera_t **);
void freeCamera(Camera_t **);
void CameraPitch(Camera_t *, double);
void CameraYaw(Camera_t *, double);
void CameraRoll(Camera_t *, double);

#endif
