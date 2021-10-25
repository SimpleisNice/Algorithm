#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;

int basicBoard[200][200];
int checkBoard[200][200][31];

int moveX[] = { 0, 0, -1, 1 };
int moveY[] = { -1, 1, 0, 0 };
int hourseMoveX[] = { -1,1,-2,2,-2,2,-1,1 };
int hourseMoveY[] = { -2,-2,-1,-1,1,1,2,2 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, w, h;
	cin >> k >> w >> h;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> basicBoard[i][j];

			for (int t = 0; t <= k; ++t)
			{
				checkBoard[i][j][t] = INT_MAX;
			}
		}
	}

	queue<tuple<int, int, int>> tempQ;
	tempQ.push(make_tuple(0, 0, 0));
	checkBoard[0][0][0] = 0;
	while (!tempQ.empty())
	{
		int x, y, hourseMove;
		tie(x, y, hourseMove) = tempQ.front();
		int moveCount = checkBoard[x][y][hourseMove];
		tempQ.pop();

		if (hourseMove < k)
			for (int i = 0; i < 8; ++i)
			{
				int tempX = x + hourseMoveX[i];
				int tempY = y + hourseMoveY[i];

				if (tempX < 0 || tempX >= h || tempY < 0 || tempY >= w)
					continue;
				if (basicBoard[tempX][tempY] == 1)
					continue;
				if (checkBoard[tempX][tempY][hourseMove + 1] > moveCount + 1)
				{
					checkBoard[tempX][tempY][hourseMove + 1] = moveCount + 1;
					tempQ.push(make_tuple(tempX, tempY, hourseMove + 1));
				}
			}
		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + moveX[i];
			int tempY = y + moveY[i];

			if (tempX < 0 || tempX >= h || tempY < 0 || tempY >= w)
				continue;
			if (basicBoard[tempX][tempY] == 1)
				continue;
			if (checkBoard[tempX][tempY][hourseMove] > moveCount + 1)
			{
				checkBoard[tempX][tempY][hourseMove] = moveCount + 1;
				tempQ.push(make_tuple(tempX, tempY, hourseMove));
			}
		}
	}

	int minMove = INT_MAX;
	for (int i = 0; i <= k; ++i)
	{
		minMove = min(minMove, checkBoard[h - 1][w - 1][i]);
	}
	if (minMove == INT_MAX)
		cout << -1 << "\n";
	else
		cout << minMove << "\n";
	return 0;
}