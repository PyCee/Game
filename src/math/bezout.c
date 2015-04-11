
#include "meth.h"

char Bezout(uint64_t num1, uint64_t num2, uint64_t targetRemainder,
			uint64_t *assignDividend, uint64_t *assignDivisor)
{
	uint64_t dividend, divisor, quotient;
	
	if(Euclida(num1, num2, targetRemainder, &dividend, &divisor, &quotient) == 0)
		return 0;
	printf("after 'Euclida'\n");
	
	if (dividend == Larger(num1, num2))
		assignDividend += 1;
	else if (dividend == Smaller(num1, num2))
		assignDividend += quotient;
	else{
	printf("before 'Bezout'\n");
		Bezout(num1, num2, dividend, assignDividend, assignDivisor);
		}
	
	if (divisor == Larger(num1, num2))
		assignDivisor += 1;
	else if (divisor == Smaller(num1, num2))
		assignDivisor += quotient;
	else{
	printf("before 'Bezout'\n");
		Bezout(num1, num2, divisor, assignDividend, assignDivisor);
		}
		
	return 1;
}
