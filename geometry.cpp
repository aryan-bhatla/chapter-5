#include "matlib.h"

double area(double radius)

{
	double x = PI * (radius * radius);
	return x;
}

double circumference(double radius)
{
	double y = 2 * PI * radius; 
	return y; 
}

double diameter(double radius)
{
	double z = 2 * radius; 
	return z; 
}