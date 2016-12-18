#include "Rectangle.h"
#include "Calculate.h"

const int Rectangle::area()
{
	const int width = getWidth();
	const int height = getHeight();

	const int multiply = Calculate::multiplication(width, height);
	return multiply;
}
