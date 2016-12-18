#include <iostream>
#include "Rectangle.h"
#include "Calculate.h"

int solution(int k, int l, int m, int n, int p, int q, int r, int s)
{
	Rectangle rect1(k, l, m, n);
	Rectangle rect2(p, q, r, s);

	if (!rect1.isValid() || !rect2.isValid())
		return INVALID_DATA;

	const int sum = Calculate::additionRectangle(rect1, rect2);
	return sum;
}

int main()
{
	int k=-4, l=1, m=2, n=6, p=0, q=-1, r=4, s=3;
	//int k = -4, l = 1, m = 2, n = 6, p = -3, q = 2, r = 1, s = 5;
	//int k = 0, l = 0, m = 10, n = 10, p = -10, q = -10, r = 0, s = 0;
	//int k = -1147483648, l = -1147483648, m = 0, n = 0, p = -10, q = -10, r = 0, s = 0;

	std::cout << solution(k, l, m, n, p, q, r, s) << '\n';

	return 0;
}