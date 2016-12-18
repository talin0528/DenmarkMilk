#pragma once

#define MAX_INT 2147483647.
#define MIN_INT -2147483648.
#define INVALID_DATA -1

class Rectangle;
class Calculate
{
public:
	static int multiplication(const int val1, const int val2);
	static int addition(const int val1, const int val2);
	static int additionAndSubtraction(const int val1, const int val2, const int val3);
	
	static Rectangle intersectRectangle(Rectangle rect1, Rectangle rect2);
	static int additionRectangle(Rectangle rect1, Rectangle rect2);
};