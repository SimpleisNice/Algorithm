#include <iostream>
#include <algorithm>

using namespace std;

char board[50][50];
int moveX[] = { 1, 0 };
int moveY[] = { 0, 1 };

int getColumn(const int n, int pos)
{
	char item = board[0][pos];
	int tempCount = 1;
	int maxCount = 1;
	for (int i = 1; i < n; ++i)
	{
		if (board[i][pos] == item)
		{
			++tempCount;
		}
		else
		{
			maxCount = max(maxCount, tempCount);
			tempCount = 1;
			item = board[i][pos];
		}
	}
	return max(maxCount, tempCount);
}
int getRow(const int n, int pos)
{
	char item = board[pos][0];
	int tempCount = 1;
	int maxCount = 1;
	for (int i = 1; i < n; ++i)
	{
		if (board[pos][i] == item)
		{
			++tempCount;
		}
		else
		{
			maxCount = max(maxCount, tempCount);
			tempCount = 1;
			item = board[pos][i];
		}
	}
	return max(maxCount, tempCount);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int maxCount = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> board[i];
	}
	for (int i = 0; i < n; ++i)
	{
		int tempColumn = getColumn(n, i);
		int tempRow = getRow(n, i);
		maxCount = max(max(maxCount, tempColumn), tempRow);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				int tempX = i + moveX[k];
				int tempY = j + moveY[k];
				if (tempX > n - 1 || tempY > n - 1)
					continue;

				swap(board[tempX][tempY], board[i][j]);
				if (moveX[k] == 0)
				{
					int tempColumn = getColumn(n, tempY);
					int tempColumn2 = getColumn(n, j);
					int tempRow = getRow(n, i);
					maxCount = max(max(max(tempColumn, tempColumn2), tempRow), maxCount);
				}
				else
				{
					int tempColumn = getColumn(n, tempY);
					int tempRow = getRow(n, tempX);
					int tempRow2 = getRow(n, i);
					maxCount = max(max(max(tempColumn, tempRow), tempRow2), maxCount);
				}
				swap(board[tempX][tempY], board[i][j]);
			}
		}
	}
	cout << maxCount << "\n";
	return 0;
}