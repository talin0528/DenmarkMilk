#pragma once



class Rectangle
{
public:
	Rectangle(int bottom, int left, int top, int right) : bottom(bottom), left(left), top(top), right(right) { }

	const int area();
	const int getBottom() const { return bottom; }
	const int getLeft() const { return left; }
	const int getTop() const { return top; }
	const int getRight() const { return right; }
	const int getWidth() const { return right - left; }
	const int getHeight() const { return top - bottom; }

	const bool isValid() const { return left < right && bottom < top; }

private:
	int bottom;
	int left;
	int top;
	int right;
};