
#ifndef _G_MATH_
#define _G_MATH_

#include <stdint.h>

#define PI 3.14159265358979323846
#define TRIG_PRECISION 9

typedef struct _Matrix_t Matrix_t;

void mathInit();

/*
double sin(double);
double cos(double);
double tan(double);
double csc(double);
double sec(double);
double cot(double);
double arcsin(double);
double arccos(double);
double arctan(double);
double arccsc(double);
double arcsec(double);
double arccot(double);
*/

// around space
Matrix_t *Transform(Matrix_t, F64, F64, F64);

// Rotations are in Radians, and counter-clockwise
// around X axis
Matrix_t *Pitch(Matrix_t, F64);
// around Y axis
Matrix_t *Yaw(Matrix_t, F64);
// around Z axis
Matrix_t *Roll(Matrix_t, F64);

F64 PythagoreanTheoremDim2(F64, F64);
F64 PythagoreanTheoremDim3(F64, F64, F64);
U64 Larger(U64, U64);
U64 Smaller(U64, U64);
U64 Mod(U64, U64);
U64 Div(U64, U64);
F64 Exponant(F64, U8);
U64 Factorial(U8);
F64 degRad(F64);
F64 radDeg(F64);

U64 PascelsTri(U64, U64);

#endif
