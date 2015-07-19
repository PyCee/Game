
#ifndef _NORMAL_
#define _NORMAL_

typedef struct _Vector_t Normal_t;

void genNormal(Normal_t *);
void freeNormal(Normal_t *);

void NormalizeNormal(Normal_t *);

void PrintNormal(Normal_t);
#endif
