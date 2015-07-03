
#ifndef _DRAW_
#define _DRAW_

//TODO: Draw far to near

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

void draw();


GLuint VAO;
GLuint VBO;

static GLuint shaderProgram;
static GLuint shaderVertex;
#define SHADER_VERT_PATH "src/shaders/vertex.vert"
static GLuint shaderFragment;
#define SHADER_FRAG_PATH "src/shaders/fragment.frag"

#endif
