
#ifndef _G_MATH_
#define _G_MATH_

#include <stdint.h>

#define PI 3.14159
#define TRIG_PRECISION 9

typedef struct _Matrix_t Matrix_t;
typedef struct _Vec3_t Vec3_t;

void mathInit();

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

// around space
Matrix_t *Transform(Matrix_t *, Vec3_t *);
// around X axis
Matrix_t *Pitch(Matrix_t *, double);
// around Z axis
Matrix_t *Yaw(Matrix_t *, double);
// around Y axis
Matrix_t *Rotate(Matrix_t *, double);

double PythagoreanTheoremDim2(double, double);
double PythagoreanTheoremDim3(double, double, double);
uint64_t Larger(uint64_t, uint64_t);
uint64_t Smaller(uint64_t, uint64_t);
uint64_t Mod(uint64_t, uint64_t);
uint64_t Div(uint64_t, uint64_t);
double Exponant(double, unsigned char);
uint64_t Factorial(unsigned char);
double degRad(double);
double radDeg(double);

uint64_t PascelsTri(uint64_t, uint64_t);

#endif
