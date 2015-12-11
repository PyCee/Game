
#include "gMath.h"

#include "matrix.h"
#include <math.h>

void mathInit
()
{
	
}
unsigned long Larger(unsigned long num1, unsigned long num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}
unsigned long Smaller(unsigned long num1, unsigned long num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}
// returns remainder of dividend / divisor
unsigned long Mod(unsigned long dividend, unsigned long divisor)
{
	if (dividend > divisor)
		return Mod(dividend - divisor, divisor);
	if (dividend < 0)
		return Mod(dividend + divisor, divisor);
	return dividend;
}

// returns quotient of dividend / divisor
unsigned long Div(unsigned long dividend, unsigned long divisor)
{
	return (unsigned long) (dividend / divisor);
}
unsigned long Factorial(unsigned char fac)
{
	if (fac == 0)
		return 0;
	if (fac == 1)
		return 1;
	return fac * Factorial(fac - 1);
}
