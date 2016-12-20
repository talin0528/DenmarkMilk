#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::string;

int findWildCardNumber(string str)
{
	int count = 0;
	int strLen = str.length();
	for(int i = 0; i < strLen; i++)
	{
		char curChar = str.at(i);
		if(curChar == '?')
			count++;
	}

	return count;
}

void printCard(string str, const int num, const int wildCount)
{
	int strLen = str.length();
	int curIndex = wildCount - 1;
	for(int i = 0; i < strLen; i++)
	{
		char curChar = str.at(i);
		if(curChar == '?')
		{
			int curPos = pow(2, curIndex);
			int curNum = (curPos & num) > 0 ? 1 : 0;
			cout<<curNum;
			curIndex--;
		}
		else
		{
			cout<<curChar;
		}
	}

	cout<<' ';
}

int main()
{
	string str;
	getline(cin, str);

	int wildCount = findWildCardNumber(str);
	int totalCount = pow(2, wildCount);

	for(int i = 0; i < totalCount; i++)
		printCard(str, i, wildCount);
	cout<<'\n';

	return 0;
}