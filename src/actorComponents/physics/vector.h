
#ifndef _VECTOR_
#define _VECTOR_

typedef struct _Vector_t{
	F32 point [3];
} Vector_t;

void 		genVector			(Vector_t *, F32, F32, F32);
void 		freeVector			(Vector_t *);

void 		copyVector			(Vector_t *, Vector_t);
Vector_t	* addVectors			(Vector_t, Vector_t);
Vector_t	* subtractVectors		(Vector_t, Vector_t);
Vector_t	* scaleVector			(Vector_t, F32);
F32		DotProduct			(Vector_t, Vector_t);
F32		CrossProduct			(Vector_t, Vector_t);

Vector_t	* TranslateVector		(Vector_t, Vector_t);
// rotate around X-axis
Vector_t 	* PitchVector			(Vector_t, F32);
// rotate around Y-axis
Vector_t 	* YawVector			(Vector_t, F32);
// rotate around Z-axis
Vector_t 	* RollVector			(Vector_t, F32);

void		PrintVector			(Vector_t);

void		setVectorX			(Vector_t *, F32);
void		setVectorY			(Vector_t *, F32);
void		setVectorZ			(Vector_t *, F32);
F32		getVectorX			(Vector_t);
F32		getVectorY			(Vector_t);
F32		getVectorZ			(Vector_t);


Vector_t i;
Vector_t j;
Vector_t k;

#endif
