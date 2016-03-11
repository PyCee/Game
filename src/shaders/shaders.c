
#include "shaders.h"
#include "../fileSupport/loadFiles.h"
#include <SDL2/SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../math/matrix.h"
#include <math.h>
extern unsigned char IAMALIVE;
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
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindAttribLocation(shaderProgram, 0, "localPosition");
	glBindAttribLocation(shaderProgram, 1, "normal");
	glBindAttribLocation(shaderProgram, 2, "texCoords");

	printf("shaderProgram Shaders Attached.\nLinking shaderProgram.\n");
	glLinkProgram(shaderProgram);
	printf("Linked shaderProgram.\n");
	
	GLint Success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(shaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
		
		IAMALIVE = 0;
	}
	
	glValidateProgram(shaderProgram);
	glUseProgram(shaderProgram);
	
	TextureLoc = glGetUniformLocation(shaderProgram, "Texture");
	if (TextureLoc == -1) {
		printf("ERROR::TextureLoc Not Found\n");
	}
	
	ActorPlacementLoc = glGetUniformLocation(shaderProgram, "actorPlacement");
	if (ActorPlacementLoc == -1) {
		printf("ERROR::actorPlacementLoc Not Found\n");
	}
	WorldPlacementLoc = glGetUniformLocation(shaderProgram, "worldPlacement");
	if (WorldPlacementLoc == -1) {
		printf("ERROR::worldPlacementLoc Not Found\n");
	}
	CameraPlacementLoc = glGetUniformLocation(shaderProgram, "cameraPlacement");
	if (CameraPlacementLoc == -1) {
		printf("ERROR::cameraPlacementLoc Not Found\n");
	}
	ProjectionLoc = glGetUniformLocation(shaderProgram, "projection");
	if (ProjectionLoc == -1) {
		printf("ERROR::projectionLoc Not Found\n");
	}

	glEnable(GL_CULL_FACE); // enables face culling    
	glCullFace(GL_BACK); // tells OpenGL to cull back faces (the sane default setting)
	glFrontFace(GL_CCW); // tells OpenGL which faces are considered 'front' (use GL_CW or GL_CCW)
	//<CL>
	//glMatrixMode(GL_PROJECTION);
	float aspect = 16/9;
	float fov = 120 * (M_PI / 180);
	float near = 1;
	float far = 10;
	mat4 proj = genZeroMat4();
	/*float rig = 9/16;
	float lef = -1 * rig;
	float top = rig / aspect;
	float bot = -1 * top;
	proj.mat[0][0] = 2 * near / (rig - lef);
	proj.mat[0][2] = (rig + lef) / (rig - lef);
	proj.mat[1][1] = 2 * near / (top - bot);
	proj.mat[1][2] = (top + bot) / (top - bot);
	proj.mat[2][2] = -1 * ((far + near) / (far - near));
	proj.mat[2][3] = -1 * ((2 * near * far) / (far - near));
	proj.mat[3][2] = -1;*/
	//mat4 proj = genIdentityMat4();
	proj.mat[0][0] = 1 / tan(fov / 2);
	proj.mat[1][1] = 1 / tan(fov / 2);
	proj.mat[2][2] = 1 * far / (far - near);
	proj.mat[2][3] = 1 * 2 * (far * near) / (far - near);
	proj.mat[3][2] = -1;
	//proj = transposeMat4(proj);
	
	//glLoadIdentity();
	//glFrustum(lef, rig, bot, top, near, far);
	glUniformMatrix4fv(ProjectionLoc, 1, GL_TRUE,
				&proj.mat[0][0]);
	//</CL>
	
}
GLuint loadShaderFromFile( const unsigned char * path, GLenum shaderType )
{
	const GLchar * shaderSource[1];
	unsigned char *fileSource = readFile( path );
	shaderSource[0] = fileSource;
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
	free(fileSource);
	return shader;
}
