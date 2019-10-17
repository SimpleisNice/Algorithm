#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <climits>
using namespace std;

char prison[101][101];
int checkMap[101][101][2] = { 0, };	// move, door
bool moveMap[101][101];


int posX[] = { 0,0,-1,1 };
int posY[] = { -1,1,0,0 };

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int h, w, sum = 0;
		cin >> h >> w;

		vector<pair<int, int>> criminals;
		map<pair<int, int>, int> tempM;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> prison[i][j];

				if (prison[i][j] == '$')    criminals.push_back(make_pair(i, j));
			}
		}

		while (!criminals.empty())
		{
			queue<pair<int, int>> tempQ;
			vector<pair<int, int>> tempV;

			tempQ.push(make_pair(criminals.back().first, criminals.back().second));
			checkMap[criminals.back().first][criminals.back().second][0] = 0;
			checkMap[criminals.back().first][criminals.back().second][1] = 0;

			moveMap[criminals.back().first][criminals.back().second] = true;
			criminals.pop_back();

			while (!tempQ.empty())
			{
				int tempX = tempQ.front().first;
				int tempY = tempQ.front().second;
				tempQ.pop();

				for (int i = 0; i < 4; ++i)
				{
					int x = tempX + posX[i];
					int y = tempY + posY[i];

					if (x < 0 || x >= h || y < 0 || y >= w)  continue;
					if (prison[x][y] == '*')    continue;

					if ((prison[x][y] == '.' || prison[x][y] == '$') && moveMap[x][y] == false)
					{
						checkMap[x][y][0] = checkMap[tempX][tempY][0] + 1;
						checkMap[x][y][1] = checkMap[tempX][tempY][1];
						moveMap[x][y] = true;
						if (x == 0 || x == h - 1 || y == 0 || y == w - 1)
						{	
							if (tempM.count(make_pair(x, y)) == 0)
								tempM.insert(make_pair(make_pair(x, y), checkMap[x][y][1]));
							else
								tempM[make_pair(x, y)] += checkMap[x][y][1];
							continue;
						}
						tempQ.push(make_pair(x, y));
					}
					else if (prison[x][y] == '#' && moveMap[x][y] == false)
					{
						if (checkMap[x][y][1] != 0 && checkMap[x][y][1] <= checkMap[tempX][tempY][1] + 1)
						{	
							if(checkMap[x][y][0] == checkMap[tempX][tempY][0] + 1)
								checkMap[x][y][1] = checkMap[tempX][tempY][1];
							else
								checkMap[x][y][1] = checkMap[tempX][tempY][1] + 1;
						}
						else
						{	
							if(checkMap[x][y][0] == checkMap[tempX][tempY][0] + 1)
								checkMap[x][y][1] = checkMap[tempX][tempY][1];
							else
								checkMap[x][y][1] = checkMap[tempX][tempY][1] + 1;
						}
						checkMap[x][y][0] = checkMap[tempX][tempY][0] + 1;
						moveMap[x][y] = true;
						if (x == 0 || x == h - 1 || y == 0 || y == w - 1)
						{
							if (tempM.count(make_pair(x, y)) == 0)
								tempM.insert(make_pair(make_pair(x, y), checkMap[x][y][1]));
							else
								tempM[make_pair(x, y)] += checkMap[x][y][1];
							continue;
						}
						tempQ.push(make_pair(x, y));
					}
				}
			}
			
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cout << checkMap[i][j][1];
			}
			cout << '\n';
		}
		cout <<'\n';
			memset(moveMap, false, sizeof(moveMap[0][0]) * 101 * 101);
		}
		sum = INT_MAX;
		for (auto it = tempM.begin(); it != tempM.end(); ++it)
		{
			if (sum > it->second)
				sum = it->second;
		}
		memset(checkMap, 0, sizeof(checkMap[0][0][0]) * 101 * 101 * 2);
		cout << sum << '\n';
	}

	return 0;
}