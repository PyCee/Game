
#ifndef _SHADERS_
#define _SHADERS_

#include <SDL2/SDL_opengl.h>

GLint TextureLoc;

GLint ActorPlacementLoc;
GLint WorldPlacementLoc;
GLint CameraPlacementLoc;
GLint ProjectionLoc;

GLuint shaderProgram;
GLuint shaderVertex;
#define SHADER_VERT_PATH "../src/shaders/vertex.vert"
GLuint shaderFragment;
#define SHADER_FRAG_PATH "../src/shaders/fragment.frag"

GLuint loadShaderFromFile( const unsigned char *, GLenum);
void genShaders(void);

#endif /* _SHADERS */
