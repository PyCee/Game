
#ifndef _WORLD_
#define _WORLD_


typedef struct _World_t{
	F64 Height;
	F64 Width;
	F64 Length;
} World_t;

void genWorld(World_t **);
void freeWorld(World_t **);

#endif /* _WORLD_ */
