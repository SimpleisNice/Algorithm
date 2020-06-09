#include <iostream>
#include <queue>

using namespace std;

char sightMap[100][100];
bool sightCheck[100][100][2];
int moveX[] = { 0, 0, -1, 1 };
int moveY[] = { -1, 1, 0, 0 };
struct People {
	int red;
	int blue;
	int green;
};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int mapSize;
	People peopleA = { 0,0,0 }, peopleB = { 0,0,0 };

	cin >> mapSize;

	for (int i = 0; i < mapSize; ++i)
	{
		cin >> sightMap[i];
	}

	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			if (sightCheck[i][j][0])
				continue;

			if (sightMap[i][j] == 'R')
				++peopleA.red;
			else if (sightMap[i][j] == 'G')
				++peopleA.green;
			else if (sightMap[i][j] == 'B')
				++peopleA.blue;

			queue<pair<int, int>> tempQ;
			tempQ.push({ i, j });
			sightCheck[i][j][0] = true;

			while (!tempQ.empty())
			{
				int x = tempQ.front().first;
				int y = tempQ.front().second;
				tempQ.pop();

				for (int k = 0; k < 4; ++k)
				{
					int tempX = x + moveX[k];
					int tempY = y + moveY[k];

					if (tempX < 0 || tempX > mapSize - 1 || tempY < 0 || tempY > mapSize - 1)
						continue;
					if (sightCheck[tempX][tempY][0] || sightMap[x][y] != sightMap[tempX][tempY])
						continue;

					tempQ.push({ tempX, tempY });
					sightCheck[tempX][tempY][0] = true;
				}
			}
		}
	}

	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			if (sightCheck[i][j][1] || sightMap[i][j] == 'B')
				continue;

			
			++peopleB.red;

			queue<pair<int, int>> tempQ;
			tempQ.push({ i, j });
			sightCheck[i][j][1] = true;

			while (!tempQ.empty())
			{
				int x = tempQ.front().first;
				int y = tempQ.front().second;
				tempQ.pop();

				for (int k = 0; k < 4; ++k)
				{
					int tempX = x + moveX[k];
					int tempY = y + moveY[k];

					if (tempX < 0 || tempX > mapSize - 1 || tempY < 0 || tempY > mapSize - 1)
						continue;
					if (sightCheck[tempX][tempY][1] || sightMap[tempX][tempY] == 'B')
						continue;
					tempQ.push({ tempX, tempY });
					sightCheck[tempX][tempY][1] = true;
				}
			}
		}
	}
	int resultA = peopleA.red + peopleA.blue + peopleA.green;
	int resultB = peopleB.red + peopleA.blue;

	cout << resultA << " " << resultB << "\n";
	return 0;
}