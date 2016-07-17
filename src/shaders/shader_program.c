#include "shader_program.h"
#include "../fileSupport/loadFiles.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

extern char IAMALIVE;

static GLuint load_shader_from_file(const unsigned char *, GLenum);
static void test_shader_program(GLuint, GLenum);

void free_shader_program(shader_program *shader)
{
	if(shader->program){
		//freeProgram
	}
	if(shader->vertex){
		//freeShader
	}
	if(shader->fragment){
		//freeShader
	}
	if(shader->vertex_src_path){
		free(shader->vertex_src_path);
		shader->vertex_src_path = 0;
	}
	if(shader->fragment_src_path){
		free(shader->fragment_src_path);
		shader->fragment_src_path = 0;
	}
}
shader_program gen_shader_program_vert_frag(const unsigned char *vert_path, const unsigned char *frag_path)
{
	shader_program shader;
	shader.program = malloc(sizeof(GLuint));
	shader.vertex = malloc(sizeof(GLuint));
	shader.fragment = malloc(sizeof(GLuint));
	shader.vertex_src_path = malloc(sizeof(unsigned char) * strlen(vert_path));
	shader.fragment_src_path = malloc(sizeof(unsigned char) * strlen(frag_path));
	strcpy(shader.vertex_src_path, vert_path);
	strcpy(shader.fragment_src_path, frag_path);
	
	printf("Loading Vertex Shader %s\n", vert_path);
	*shader.vertex = load_shader_from_file(vert_path, GL_VERTEX_SHADER);
	printf("Vertex Shader Loaded.\nLoading Fragment Shader %s\n", frag_path);
	*shader.fragment = load_shader_from_file(frag_path, GL_FRAGMENT_SHADER);
	printf("Vertex Shader Loaded.\nCreating Shader Program.\n");
	*shader.program = glCreateProgram();
	printf("Shader Program Created.\nshaderProgram Attaching Shaders.\n");
	glAttachShader(*shader.program, *shader.vertex);
	glAttachShader(*shader.program, *shader.fragment);
	printf("Shader Program Shaders Attached.\n");
	return shader;
}
static GLuint load_shader_from_file(const unsigned char *path, const GLenum shaderType)
{
	const GLchar * shaderSource[1];
	unsigned char *fileSource = readFile(path);
	shaderSource[0] = fileSource;
	GLuint length[1];
	GLuint result;

	FILE *source;
	if ((source = fopen(path, "r")) == NULL)
		return 0;
	fseek(source, 0, SEEK_END);
	length[0] = ftell(source);
	fseek(source, 0, SEEK_SET);
	fclose(source);
	
	GLuint shader = glCreateShader(shaderType);
	printf("Shader Gened.\nShader Linking.\n");
	glShaderSource(shader, 1, shaderSource, length);
	printf("Shader Linked.\nShader Compiling.\n");
	glCompileShader(shader);
	
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shader, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "ERROR::Compiling Shader Type %d: '%s'\n", shaderType, InfoLog);
		
		IAMALIVE = 0; // Ends game so error may be fixed.
	}
	free(fileSource);
	return shader;
}
static void test_shader_program(GLuint program, GLenum test)
{
	GLint Success;
	glGetProgramiv(program, test, &Success);
	if (Success == 0) {
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(program, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "ERROR::'%s'\n", ErrorLog);
		IAMALIVE = 0;
	}
}
