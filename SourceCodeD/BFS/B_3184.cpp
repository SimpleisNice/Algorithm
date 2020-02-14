#include <iostream>
#include <queue>
using namespace std;

char groundMap[250][250];
int splitMap[250][250];

int moveX[] = { 0, 0, -1, 1 };
int moveY[] = { -1, 1, 0, 0 };

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int R, C;
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		cin >> groundMap[i];
	}

	int setPoint = 1;
	int totalWolf = 0;
	int totalSheep = 0;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			int wolf = 0;
			int sheep = 0;
			if (groundMap[i][j] != '#' && splitMap[i][j] == 0)
			{
				queue<pair<int, int>> tempQ;
				tempQ.push(make_pair(i, j));
				splitMap[i][j] = setPoint;

				if (groundMap[i][j] == 'o')
					++sheep;
				else if (groundMap[i][j] == 'v')
					++wolf;

				while (!tempQ.empty())
				{
					int x = tempQ.front().first;
					int y = tempQ.front().second;
					tempQ.pop();

					for (int k = 0; k < 4; ++k)
					{
						int tempX = x + moveX[k];
						int tempY = y + moveY[k];

						if (tempX < 0 || tempX >= R || tempY < 0 || tempY >= C)
							continue;
						if (groundMap[tempX][tempY] == '#' || splitMap[tempX][tempY] != 0)
							continue;
						if (groundMap[tempX][tempY] == 'o')
							++sheep;
						else if (groundMap[tempX][tempY] == 'v')
							++wolf;

						splitMap[tempX][tempY] = setPoint;
						tempQ.push(make_pair(tempX, tempY));
					}
				}
				++setPoint;
				if (sheep > wolf)
					totalSheep += sheep;
				else if (sheep <= wolf)
					totalWolf += wolf;
			}
		}
	}
	cout << totalSheep << " " << totalWolf << '\n';
	return 0;
}