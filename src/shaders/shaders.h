
#ifndef _SHADERS_
#define _SHADERS_

#include <SDL2/SDL_opengl.h>

GLint TextureLoc;

GLint WorldSpaceLoc;
GLint ViewSpaceLoc;
GLint ClipSpaceLoc;
GLint CameraPositionLoc;

GLuint shaderProgram;
GLuint shaderVertex;
#define SHADER_VERT_PATH "../src/shaders/vertex.vert"
GLuint shaderFragment;
#define SHADER_FRAG_PATH "../src/shaders/fragment.frag"

GLuint loadShaderFromFile( const unsigned char *, GLenum);
void genShaders(void);

#endif /* _SHADERS */
