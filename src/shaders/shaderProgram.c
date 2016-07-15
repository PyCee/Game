#include "shaderProgram.h"
#include "../fileSupport/loadFiles.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

extern char IAMALIVE;

static GLuint loadShaderFromFile(const unsigned char *, GLenum);
static void testShaderProgram(GLuint, GLenum);

void freeShaderProgram(shaderProgram *shader)
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
	if(shader->vertexSourcePath){
		free(shader->vertexSourcePath);
		shader->vertexSourcePath = 0;
	}
	if(shader->fragmentSourcePath){
		free(shader->fragmentSourcePath);
		shader->fragmentSourcePath = 0;
	}
}
shaderProgram genShaderProgramVertFrag(const unsigned char *vertPath, const unsigned char *fragPath)
{
	shaderProgram shader;
	shader.program = malloc(sizeof(GLuint));
	shader.vertex = malloc(sizeof(GLuint));
	shader.fragment = malloc(sizeof(GLuint));
	shader.vertexSourcePath = malloc(sizeof(unsigned char) * strlen(vertPath));
	shader.fragmentSourcePath = malloc(sizeof(unsigned char) * strlen(fragPath));
	strcpy(shader.vertexSourcePath, vertPath);
	strcpy(shader.fragmentSourcePath, fragPath);
	
	printf("Loading Vertex Shader %s\n", vertPath);
	*shader.vertex = loadShaderFromFile(vertPath, GL_VERTEX_SHADER);
	printf("Vertex Shader Loaded.\nLoading Fragment Shader %s\n", fragPath);
	*shader.fragment = loadShaderFromFile(fragPath, GL_FRAGMENT_SHADER);
	printf("Vertex Shader Loaded.\nCreating Shader Program.\n");
	*shader.program = glCreateProgram();
	printf("Shader Program Created.\nshaderProgram Attaching Shaders.\n");
	glAttachShader(*shader.program, *shader.vertex);
	glAttachShader(*shader.program, *shader.fragment);
	printf("Shader Program Shaders Attached.\n");
	return shader;
}
static GLuint loadShaderFromFile(const unsigned char *path, const GLenum shaderType)
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
static void testShaderProgram(GLuint program, GLenum test)
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
