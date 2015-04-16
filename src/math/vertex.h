
#ifndef _VERTEX_
#define _VERTEX_

#define widthPos 4
#define widthTex 2

typedef struct _Matrix_t Matrix_t;
typedef struct _Vec3_t Vec3_t;

typedef struct _Vertex_t{
	Matrix_t *Pos;
	Matrix_t *Tex;
	Vec3_t *Norm;
} Vertex_t;

void genVertex(Vertex_t **);
void freeVertex(Vertex_t **);

#endif
