#ifndef ROTATION_CONTROLLER
#define ROTATION_CONTROLLER

struct vec3;

typedef struct rotationController{
	float yaw, pitch, roll;
} rotationController;

rotationController getRotationToVec3(struct vec3);

#endif /* ROTATION_CONTROLLER */
