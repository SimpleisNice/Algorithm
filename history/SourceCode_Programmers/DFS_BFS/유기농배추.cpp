#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int ground[50][50];
bool checkGround[50][50];

int moveX[] = { 0, 0, -1, 1 };
int moveY[] = { -1, 1, 0, 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--)
	{
		int m, n, k;
		cin >> m >> n >> k;

		queue<pair<int, int>> tempQ;

		for (int i = 0; i < k; ++i)
		{
			int tempX, tempY;
			cin >> tempX >> tempY;

			tempQ.push(make_pair(tempX, tempY));
			ground[tempX][tempY] = 1;
		}

		int needBug = 0;
		while (!tempQ.empty())
		{
			int posX = tempQ.front().first;
			int posY = tempQ.front().second;
			tempQ.pop();

			if (checkGround[posX][posY])
				continue;

			needBug++;

			queue<pair<int, int>> setBug;
			checkGround[posX][posY] = true;
			setBug.push(make_pair(posX, posY));

			while (!setBug.empty())
			{
				int x = setBug.front().first;
				int y = setBug.front().second;
				setBug.pop();

				for (int i = 0; i < 4; ++i)
				{
					int tempX = x + moveX[i];
					int tempY = y + moveY[i];

					if (tempX < 0 || tempX > m - 1 || tempY < 0 || tempY > n - 1)
						continue;
					if (checkGround[tempX][tempY])
						continue;
					if (ground[tempX][tempY] == 1) {
						checkGround[tempX][tempY] = true;
						setBug.push(make_pair(tempX, tempY));
					}
				}
			}
		}
		cout << needBug << "\n";
		memset(&checkGround[0][0], false, sizeof(checkGround));
		memset(&ground[0][0], 0, sizeof(ground));
	}
	return 0;
}