#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

#define SUB_LENGTH 4

string flipString(const string& str, unsigned int index)
{
	char curChar = str.at(index);
	string result;
	result.append(1, curChar);
	
	if (curChar == 'x')
	{
		string subStr[SUB_LENGTH];
		unsigned int subIndex = index + 1;
		for (unsigned int i = 0; i < SUB_LENGTH; i++)
		{
			if (subIndex < str.length())
			{
				subStr[i] = flipString(str, subIndex);
				subIndex += subStr[i].length();
			}
		}
				
		for (unsigned int i = 0; i < SUB_LENGTH; i++)
		{
			const unsigned int reverseIndex = (i + 2) % SUB_LENGTH;
			result.append(subStr[reverseIndex]);
		}			
	}
	
	return result;
}


int main(void)
{
	int C = 0;
	cin >> C;
	getchar(); //¡ŸπŸ≤ﬁ

	for (int i = 0; i < C; i++)
	{
		string str;
		getline(cin, str);
		cout << flipString(str, 0) << '\n';
	}

	return 0;
}