
#ifndef _TEXTURE_
#define _TEXTURE_

#include <SDL2/SDL_opengl.h>

typedef struct _Texture {
	GLuint id;
	unsigned char *type;
} Texture;

Texture genTexture(GLuint, unsigned char *);

#endif /* _TEXTURE_ */
