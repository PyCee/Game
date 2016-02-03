
#ifndef _MESH_
#define _MESH_

#include <SDL2/SDL_opengl.h>
#include "vertex.h"
#include "texture.h"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

typedef struct _Mesh {
	Vertex *vertices;
	unsigned int numVertices;
	Texture *textures;
	unsigned int numTextures;
	GLuint *indices;
	unsigned int numIndices;
	GLuint VBO, VAO, EBO;
} Mesh;

void setupMesh(Mesh *);
void processMesh(struct aiMesh *, const struct aiScene *, unsigned int);

#endif /* _MESH_ */
