#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include <SDL2/SDL_opengl.h>

typedef struct shader_program {
	GLuint *program, *vertex, *fragment;
	unsigned char *vertex_src_path, *fragment_src_path;
} shader_program;

void free_shader_program(shader_program *);
shader_program gen_shader_program_vert_frag(const unsigned char *, const unsigned char *);

#endif /* SHADER_PROGRAM */
