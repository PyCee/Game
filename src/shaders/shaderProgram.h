#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include <SDL2/SDL_opengl.h>

typedef struct shaderProgram {
	GLuint *program, *vertex, *fragment;
	unsigned char *vertexSourcePath, *fragmentSourcePath;
} shaderProgram;

void freeShaderProgram(shaderProgram *);
shaderProgram genShaderProgramVertFrag(const unsigned char *, const unsigned char *);

#endif /* SHADER_PROGRAM */
