
#ifndef _DRAW_
#define _DRAW_

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

void draw();


GLuint VAO;
GLuint VBO;

static GLuint shaderProgram;
static GLuint shaderVertex;
#define SHADER_PATH_VERT "shaders\\vertex.vert";
static GLuint shaderFragment;
#define SHADER_PATH_FRAG "shaders\\fragment.frag";

#endif
