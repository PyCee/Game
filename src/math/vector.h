
#ifndef _VECTOR_
#define _VECTOR_

typedef struct _Vec3_t
{
	double X;
	double Y;
	double Z;
} Vec3_t;
typedef struct _Vec2_t
{
	double X;
	double Y;
} Vec2_t;

void genVec3(Vec3_t **);
void genVec2(Vec2_t **);
void freeVec3(Vec3_t **);
void freeVec2(Vec2_t **);
void NormalizeVec3(Vec3_t *);
void NormalizeVec2(Vec2_t *);

#endif
