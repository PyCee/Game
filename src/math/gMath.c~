
#include "gMath.h"

#include "matrix.h"

#include <math.h>

void mathInit
()
{
	
}
uint64_t Larger(uint64_t num1, uint64_t num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}
uint64_t Smaller(uint64_t num1, uint64_t num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}
// returns remainder of dividend / divisor
uint64_t Mod(uint64_t dividend, uint64_t divisor)
{
	if (dividend > divisor)
		return Mod(dividend - divisor, divisor);
	if (dividend < 0)
		return Mod(dividend + divisor, divisor);
	return dividend;
}

// returns quotient of dividend / divisor
uint64_t Div(uint64_t dividend, uint64_t divisor)
{
	return (uint64_t) (dividend / divisor);
}
double Exponant(double base, unsigned char exponant)
{
	if (exponant == 0)
		return 1;
	if (exponant == 1)
		return base;
	return base * Exponant(base, exponant - 1);
}
uint64_t Factorial(unsigned char fac)
{
	if (fac == 0)
		return 0;
	if (fac == 1)
		return 1;
	return fac * Factorial(fac - 1);
}
double degRad(double deg)
{
	return deg * PI / 180;
}
double radDeg(double rad)
{
	return rad * 180 / PI;
}
double PythagoreanTheoremDim2
(double X, double Y)
{
	return sqrt(Exponant(X, 2) + Exponant(Y, 2));
}
double PythagoreanTheoremDim3
(double X, double Y, double Z)
{
	return sqrt(Exponant(X, 2) + Exponant(Y, 2) + Exponant(Z, 2));
}
