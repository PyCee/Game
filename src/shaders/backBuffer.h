#ifndef BACK_BUFFER
#define BACK_BUFFER

#define FRAME_BUFFER_VERTEX_LOC "../src/shaders/backBuffer/backBufferVertex.vert"
#define FRAME_BUFFER_FRAGMANT_LOC "../src/shaders/backBuffer/backBufferFragment.frag"

#include <SDL2/SDL_opengl.h>

extern GLuint backBuffer, backBufferTexture, backBufferDepthStencil;

void genBackBuffer(void);
void bringForthBackBuffer(void);

#endif /* BACK_BUFFER */
