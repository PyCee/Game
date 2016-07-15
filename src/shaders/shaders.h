
#ifndef SHADERS
#define SHADERS

#include <SDL2/SDL_opengl.h>

#define SHADER_BACKBUFFER_VERT_PATH "../src/shaders/backBuffer/backBufferVertex.vert"
#define SHADER_BACKBUFFER_FRAG_PATH "../src/shaders/backBuffer/backBufferFragment.frag"
extern struct shaderProgram *frameBufferShader;
extern GLuint FBS_TextureLoc;

#define SHADER_STANDARD_VERT_PATH "../src/shaders/vertex.vert"
#define SHADER_STANDARD_FRAG_PATH "../src/shaders/fragment.frag"
extern struct shaderProgram *standardModelShader;
extern GLuint SMS_WorldSpaceLoc;
extern GLuint SMS_ViewSpaceLoc;
extern GLuint SMS_ClipSpaceLoc;
extern GLuint SMS_CameraPositionLoc;
extern GLuint SMS_TextureLoc;

void genShaders(void);

#endif /* SHADERS */
