
#include "meth.h"

// finds the largest number that divides both parameters
uint64_t Euclid(uint64_t num1, uint64_t num2)
{
	uint64_t dividend = Smaller(num1, num2);
	uint64_t divisor = Larger(num1, num2);
	uint64_t quotient = Div(divisor, dividend);
	uint64_t remainder = Mod(divisor, dividend);
	
	if (dividend == divisor)
		return dividend;
	
	if (remainder == 0)
			return dividend;
	else
		return Euclid(remainder, dividend);
}
// d = q * a + r
// divisor = quotient * dividend + remainder

char Euclida(uint64_t num1, uint64_t num2,
			uint64_t targetRemainder, uint64_t *assignDividend,
			uint64_t *assignDivisor, uint64_t *assignQuotient)
{
	uint64_t dividend = Smaller(num1, num2);
	uint64_t divisor = Larger(num1, num2);
	uint64_t quotient = Div(divisor, dividend);
	uint64_t remainder = Mod(divisor, dividend);
	
	if (dividend == divisor)
		return dividend;
	if (remainder == targetRemainder)
	{
		(*assignDividend) = dividend;
		(*assignDivisor) = 1;
		(*assignQuotient) = quotient;
		return 1;
	} else if (remainder == 0)
		return 0;
	else
		return Euclida(remainder, dividend, targetRemainder, assignDividend, assignDivisor, assignQuotient);
}
