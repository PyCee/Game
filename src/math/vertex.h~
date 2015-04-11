
#ifndef _VERTEX_
#define _VERTEX_

#define X_ Pos[0]
#define Y_ Pos[1]
#define Z_ Pos[2]

#define Nx_ Norm[0]
#define Ny_ Norm[1]
#define Nz_ Norm[2]

#define U_ Tex[0]
#define V_ Tex[1]

#define widthPos 3
#define widthNorm 3
#define widthTex 2

typedef struct _Matrix_t Matrix_t;

typedef struct _Vertex_t{
	Matrix_t *Pos;
	Matrix_t *Norm;
	Matrix_t *Tex;
} Vertex_t;

void genVertex(Vertex_t **);
void freeVertex(Vertex_t **);

#endif
