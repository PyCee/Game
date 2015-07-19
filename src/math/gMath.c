
#include "../dataTypes.h"
#include "gMath.h"

#include "matrix.h"

#include <math.h>

void mathInit
()
{
	
}
U64 Larger(U64 num1, U64 num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}
U64 Smaller(U64 num1, U64 num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}
// returns remainder of dividend / divisor
U64 Mod(U64 dividend, U64 divisor)
{
	if (dividend > divisor)
		return Mod(dividend - divisor, divisor);
	if (dividend < 0)
		return Mod(dividend + divisor, divisor);
	return dividend;
}

// returns quotient of dividend / divisor
U64 Div(U64 dividend, U64 divisor)
{
	return (U64) (dividend / divisor);
}
U64 Factorial(U8 fac)
{
	if (fac == 0)
		return 0;
	if (fac == 1)
		return 1;
	return fac * Factorial(fac - 1);
}
