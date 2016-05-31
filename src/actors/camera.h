
#ifndef CAMERA
#define CAMERA

#define CAMERA_NAME "CAMERA"
float cameraPitch;
float cameraYaw;
float cameraRoll; // I don't expect ever using roll, but it is here if I do...

void genFrustum(void);
unsigned char genCamera(void);
void UpdateCamera(unsigned short);

#endif /* CAMERA */
