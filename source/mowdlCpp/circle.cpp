#include "circle.h"

#define PI 3.14

double circle::getRadius() const
{
	return radius;
}

double circle::getArea() const
{
	return(PI * radius * radius);
}

void circle::setRadius(double value)
{
	radius = value;
}