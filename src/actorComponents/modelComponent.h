
#ifndef _MODEL_COMPONENT_
#define _MODEL_COMPONENT_

#include "model/mesh.h"
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags

typedef struct _ModelComponent {
	Mesh *meshes;
	unsigned int numMeshes;
	unsigned char *dir;
} ModelComponent;

Mesh *loadModelFromFile(const unsigned char *);

#endif /* _MODEL_COMPONENT_ */
