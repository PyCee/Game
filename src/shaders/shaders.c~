
#include "../dataTypes.h"
#include "shaders.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//p#include "../main.c"
extern U8 IAMALIVE;
void genShaders(void)
{
	
	printf("Loading Vertex Shader.\n");
	shaderVertex = loadShaderFromFile(SHADER_VERT_PATH, GL_VERTEX_SHADER);
	printf("Vertex Shader Loaded.\nLoading Fragment Shader.\n");
	shaderFragment = loadShaderFromFile(SHADER_FRAG_PATH, GL_FRAGMENT_SHADER);
	printf("Vertex Shader Loaded.\n");

	shaderProgram = glCreateProgram();
	printf("shaderProgram Gened.\nshaderProgram Attaching Shaders.\n");
	glAttachShader(shaderProgram, shaderVertex);
	glAttachShader(shaderProgram, shaderFragment);
	
	glEnableVertexAttribArray(0);
	glBindAttribLocation(shaderProgram, 0, "localPosition");

	printf("shaderProgram Shaders Attached.\nLinking shaderProgram.\n");
	glLinkProgram(shaderProgram);
	printf("Linked shaderProgram.\n");
	
	GLint Success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		
		IAMALIVE = 0; // Ends game so error may be fixed.
	}
	
	glValidateProgram(shaderProgram);
	glUseProgram(shaderProgram);
	
	
}
// take file and load it into c-string
static U8 * loadShaderSource(const U8 * path)
{
	U8 * shaderSource;
	FILE *source;
	if ( (source = fopen( path, "r" ) ) == NULL )
		return 0;
	fseek( source,  0, SEEK_END );
	U32 length = ftell( source );
	fseek( source,  0, SEEK_SET );
	shaderSource = malloc( length );
	fread( shaderSource, length, 1, source );
	fclose( source );
	return shaderSource;
}
GLuint loadShaderFromFile( const U8 * path, GLenum shaderType )
{
	const GLchar * shaderSource[1];
	shaderSource[0] = loadShaderSource( path );
	GLuint length[1];
	GLuint result;

	FILE *source;
	if ( (source = fopen( path, "r" ) ) == NULL )
		return 0;
	fseek( source,  0, SEEK_END );
	length[0] = ftell( source );
	fseek( source,  0, SEEK_SET );
	fclose( source );
	
	
	GLuint shader = glCreateShader(shaderType);
	printf("shader Gened.\nshader Linking.\n");
	glShaderSource(shader, 1, shaderSource, length);
	printf("shader Linked.\nshader Compiling.\n");
	glCompileShader(shader);
	
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if ( !success ) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shader, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
		
		IAMALIVE = 0; // Ends game so error may be fixed.
	}

	return shader;
}
