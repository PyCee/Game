
#ifndef _VECTOR_
#define _VECTOR_

typedef struct _Matrix_t Vec2_t;
typedef struct _Matrix_t Vec3_t;

void genVec2(Vec2_t *);
void genVec3(Vec3_t *);

void freeVec2(Vec2_t *);
void freeVec3(Vec3_t *);

void PrintVec2(Vec2_t);
void PrintVec3(Vec3_t);

F64 *getVecXPtr(struct _Matrix_t *);
F64 *getVecYPtr(struct _Matrix_t *);
F64 *getVecZPtr(struct _Matrix_t *);
F64 getVecX(struct _Matrix_t);
F64 getVecY(struct _Matrix_t);
F64 getVecZ(struct _Matrix_t);
#endif
