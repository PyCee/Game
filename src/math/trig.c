
#include "../dataTypes.h"
#include "gMath.h"

#include <stdio.h>
#include <math.h>
/*
double sin
(double radians)
{
	char mult = 1;
	unsigned char currPrecision = 0;
	double answer;
	while (currPrecision < TRIG_PRECISION)
	{
		answer += mult * (Exponant(radians, currPrecision * 2 + 3) / Factorial(currPrecision * 2 + 3));
		mult = mult * -1;
		currPrecision++;
	}
	return answer;
}
double cos
(double radians)
{
	return sin(radians - PI / 2 );
}
double tan
(double radians)
{
	return sin(radians) / cos(radians);
}
double csc
(double radians)
{
	return 1 / sin(radians);
}
double sec
(double radians)
{
	return 1 / cos(radians);
}
double cot
(double radians)
{
	return 1 / tan(radians);
}
double arcsin
(double unit)
{
	unsigned char currPrecision = 0;
	double answer = unit;
	while (currPrecision < TRIG_PRECISION)
	{
		double fraction = 1;
		unsigned char numerator = 3;
		while (numerator < currPrecision * 2 + 3)
		{
			fraction = fraction * numerator;
			numerator += 2;
		}
		unsigned char denominator = 2;
		while (denominator < currPrecision * 2 + 3)
		{
			fraction = fraction / denominator;
			denominator += 2;
		}
		answer += fraction * Exponant(unit, currPrecision * 2 + 3) / (currPrecision * 2 + 3);
		currPrecision++;
	}
	return answer;
}

double arccos
(double unit)
{
	return arcsin(sqrt(1 - Exponant(unit, 2)));
}
/*
double arctan(double);
double arccsc(double);
double arcsec(double);
double arccot(double);
*/
