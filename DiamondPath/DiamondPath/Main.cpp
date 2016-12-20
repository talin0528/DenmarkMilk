#include <iostream>
using std::cin;
using std::cout;

#define MAX_LENGTH 101

void getInput(int arr[][MAX_LENGTH], const int n)
{
	int maxRow = 2 * n - 1;
	for(int i = 0; i < maxRow; i++)
	{
		if(i < n)
		{
			for(int j = 0; j <= i; j++)
				cin>>arr[i][j];
		}
		else
		{
			for(int j = 0; j < maxRow - i; j++)
				cin>>arr[i][j];
		}
	}
}

void findMaxDiamondPath(int arr[][MAX_LENGTH], const int n, const int curRow, const int curCol, int sum, int& max)
{
	sum += arr[curRow][curCol];

	int maxRow = 2 * n - 1;	
	if(curRow+1 == maxRow)
	{
		if(max < sum)
			max = sum;
		return;
	}

	if(curRow < n - 1)
	{
		findMaxDiamondPath(arr, n, curRow+1, curCol, sum, max);
		
		if(curCol <= curRow)
			findMaxDiamondPath(arr, n, curRow+1, curCol+1, sum, max);
	}
	else
	{
		if(curCol == 0)
		{
			findMaxDiamondPath(arr, n, curRow+1, curCol, sum, max);
		}
		else if(curCol == maxRow - curRow - 1)
		{
			findMaxDiamondPath(arr, n, curRow+1, curCol-1, sum, max);
		}
		else
		{
			if(curCol < maxRow - curRow - 1)
				findMaxDiamondPath(arr, n, curRow+1, curCol, sum, max);

			if(curCol > 0)
				findMaxDiamondPath(arr, n, curRow+1, curCol-1, sum, max);
		}
	}
}

int main()
{
	int c;
	cin>>c;

	for(int i = 0; i < c; i++)
	{
		int n;
		cin>>n;

		int arr[MAX_LENGTH * 2 - 1][MAX_LENGTH] = { 0 };
		getInput(arr, n);

		int maxSum = 0; 
		findMaxDiamondPath(arr, n, 0, 0, 0, maxSum);
		cout<<maxSum<<'\n';
	}
	
	return 0;
}