
#ifndef _MODEL_COMPONENT_
#define _MODEL_COMPONENT_

#include "model/mesh.h"
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags

typedef struct ModelComponent {
	Mesh *meshes;
	unsigned int numMeshes;
	unsigned char *directory;
} ModelComponent;

Mesh *loadModelFromFile(const unsigned char *);
void freeModelComponent(void);

#endif /* _MODEL_COMPONENT_ */
