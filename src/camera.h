
#ifndef _CAMERA_
#define _CAMERA_

typedef struct _Actor_t Actor_t;

typedef struct _Actor_t Camera_t;

void genCamera(Camera_t **);
void freeCamera(Camera_t **);
void CameraPitch(Camera_t *, F64);
void CameraYaw(Camera_t *, F64);
void CameraRoll(Camera_t *, F64);

#endif
