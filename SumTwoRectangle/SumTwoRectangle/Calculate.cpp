#include <cmath>
#include "Calculate.h"
#include "Rectangle.h"

int Calculate::multiplication(const int val1, const int val2)
{
	if (val1 <= 0 || val2 <= 0)
		return INVALID_DATA;

	double multiply = static_cast<double>(val1) * val2;
	if (multiply > MAX_INT)
		return INVALID_DATA;

	return static_cast<int>(multiply);
}

int Calculate::addition(const int val1, const int val2)
{
	if (val1 <= 0 || val2 <= 0)
		return INVALID_DATA;

	double sum = static_cast<double>(val1) + val2;
	if (sum > MAX_INT)
		return INVALID_DATA;

	return static_cast<int>(sum);
}

int Calculate::additionAndSubtraction(const int val1, const int val2, const int val3)
{
	if (val1 <= 0 || val2 <= 0 || val3 <= 0)
		return INVALID_DATA;

	double calculateResult = static_cast<double>(val1) + val2 - val3;
	if (calculateResult > MAX_INT || calculateResult < MIN_INT)
		return INVALID_DATA;

	return static_cast<int>(calculateResult);
}

Rectangle Calculate::intersectRectangle(Rectangle rect1, Rectangle rect2)
{
	const int left = static_cast<int>(std::fmax(rect1.getLeft(), rect2.getLeft()));
	const int top = static_cast<int>(std::fmin(rect1.getTop(), rect2.getTop()));
	const int right = static_cast<int>(std::fmin(rect1.getRight(), rect2.getRight()));
	const int bottom = static_cast<int>(std::fmax(rect1.getBottom(), rect2.getBottom()));

	Rectangle newRect(bottom, left, top, right);
	return newRect;
}

int Calculate::additionRectangle(Rectangle rect1, Rectangle rect2)
{
	const int rectArea1 = rect1.area();
	const int rectArea2 = rect2.area();

	int sumArea = INVALID_DATA;
	Rectangle intersect = Calculate::intersectRectangle(rect1, rect2);
	if (intersect.isValid()) //intersect or include
	{
		const int intersectArea = intersect.area();
		sumArea = Calculate::additionAndSubtraction(rectArea1, rectArea2, intersectArea);
	}
	else //seperate
		sumArea = Calculate::addition(rectArea1, rectArea2);

	return sumArea;
}
