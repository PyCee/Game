#ifndef _RENDER_COMPONENT_
#define _RENDER_COMPONENT_

#include "../actorSelection.h"
#include <SDL2/SDL_opengl.h>

#define MAX_X 10
#define MIN_X 1
#define RANGE_X MAX_X - MIN_X
#define MAX_Y 10
#define MIN_Y 1
#define RANGE_Y MAX_Y - MIN_Y
#define MAX_Z 10
#define MIN_Z 0
#define RANGE_Z MAX_Z - MIN_Z

typedef struct _RenderComponent_t {

	GLuint BoundingBoxVBO;
	F32 BoundingBoxVerticies[24];
	U8 render;
} RenderComponent_t;

U16 BoundingBoxIndices[36];
GLuint BoundingBoxIBO;

GLint ActorWorldPositionLoc;
GLint ActorRotateVectorLoc;
GLint ActorRotateAngleLoc;

GLint ActorPlacementLoc;
GLint WorldPlacementLoc;
GLint CameraPlacementLoc;

void initRender(void);
void genRenderComponent();
void freeRenderComponent();
void updateRenderComponent(U16);

#endif /* _RENDER_COMPONENT_ */
