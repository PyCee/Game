
#include "vertex.h"

#include <stdlib.h>
#include "matrix.h"

void genVertex
(Vertex_t **vertex)
{
	*vertex = malloc(sizeof(Vertex_t));
	Vertex_t *_vertex = *vertex;
	genMatrix(&_vertex->Pos, 1, widthPos);
	genMatrix(&_vertex->Norm, 1, widthNorm);
	genMatrix(&_vertex->Tex, 1, widthTex);
}
void freeVertex
(Vertex_t **vertex)
{
	Vertex_t *_vertex = *vertex;
	freeMatrix(&_vertex->Pos);
	freeMatrix(&_vertex->Norm);
	freeMatrix(&_vertex->Tex);
	free(*vertex);
}
