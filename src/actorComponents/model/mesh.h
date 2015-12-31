
#ifndef _MESH_
#define _MESH_

#include <SDL2/SDL_opengl.h>
#include "vertex.h"
#include "texture.h"

typedef struct _Mesh {
	Vertex *vertices;
	unsigned int numVertices;
	Texture *textures;
	GLuint *indices;
	unsigned int numIndices;
	GLuint VBO, VAO, EBO;
} Mesh;

void setupMesh(Mesh *);

#endif /* _MESH_ */
