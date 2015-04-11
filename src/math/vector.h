
#ifndef _VECTOR_
#define _VECTOR_

typedef struct _Vecor3_t
{
	double X;
	double Y;
	double Z;
} Vec3_t;
typedef struct _Vecor2_t
{
	double X;
	double Y;
} Vec2_t;

double getVec2Magnitude(Vec2_t vector);
double getVec3Magnitude(Vec3_t vector);

#endif
