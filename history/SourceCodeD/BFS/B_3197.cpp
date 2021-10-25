#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int moveX[] = { 0,0,-1,1 };
int moveY[] = { -1,1,0,0 };
char lakeMap[1500][1500];
int checkMap[1500][1500];
bool swanMap[1500][1500];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int r, c;
	cin >> r >> c;
	queue<pair<pair<int, int>, int>> tempQ;
	vector<pair<int, int>> swan;
	deque<pair<pair<int, int>, int>> swanPos;
	for (int i = 0; i < r; ++i) {
		cin >> lakeMap[i];
		for (int j = 0; j < c; ++j) {
			if (lakeMap[i][j] != 'X')
				tempQ.push(make_pair(make_pair(i, j), 0));
			if (lakeMap[i][j] == 'L')
				swan.push_back(make_pair(i, j));
		}
	}

	while (!tempQ.empty())
	{
		int x = tempQ.front().first.first;
		int y = tempQ.front().first.second;
		int dayCnt = tempQ.front().second;
		tempQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + moveX[i];
			int tempY = y + moveY[i];

			if (tempX < 0 || tempX > r - 1 || tempY < 0 || tempY > c - 1)
				continue;
			if (lakeMap[tempX][tempY] == '.')
				continue;
			if (checkMap[tempX][tempY] == 0 || checkMap[tempX][tempY] > dayCnt + 1)
			{
				checkMap[tempX][tempY] = dayCnt + 1;
				tempQ.push(make_pair(make_pair(tempX, tempY), checkMap[tempX][tempY]));
			}
		}
	}

	swanPos.push_back(make_pair(make_pair(swan[0].first, swan[0].second), 0));
	int minDay = 0;
	while (!swanPos.empty())
	{
		int x = swanPos.front().first.first;
		int y = swanPos.front().first.second;
		int dayCnt = swanPos.front().second;

		if (swanMap[swan[1].first][swan[1].second])
		{
			minDay = dayCnt;
			break;
		}
		swanPos.pop_front();

		for (int i = 0; i < 4; ++i)
		{
			int tempX = x + moveX[i];
			int tempY = y + moveY[i];

			if (tempX < 0 || tempX > r - 1 || tempY < 0 || tempY > c - 1)
				continue;
			if (!swanMap[tempX][tempY] && checkMap[tempX][tempY] <= dayCnt)
			{
				swanMap[tempX][tempY] = true;
				swanPos.push_front(make_pair(make_pair(tempX, tempY), dayCnt));
			}
			else if (!swanMap[tempX][tempY] && checkMap[tempX][tempY] == dayCnt + 1)
			{
				swanMap[tempX][tempY] = true;
				swanPos.push_back(make_pair(make_pair(tempX, tempY), dayCnt + 1));
			}
		}
	}
	cout << minDay << "\n";
	return 0;
}

