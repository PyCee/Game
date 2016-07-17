#ifndef BACK_BUFFER
#define BACK_BUFFER

#include <SDL2/SDL_opengl.h>

extern GLuint backBuffer, backBufferTexture, backBufferDepthStencil;

void genBackBuffer(void);
void bringForthBackBuffer(void);

#endif /* BACK_BUFFER */
