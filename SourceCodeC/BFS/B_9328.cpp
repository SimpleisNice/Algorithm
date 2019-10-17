#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <cstring>
#include <map>
using namespace std;

char buildingMap[101][101];
bool moveCheck[101][101];

int movX[] = { 0,0,-1,1 };
int movY[] = { -1,1,0,0 };

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int h, w;
		cin >> h >> w;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> buildingMap[i][j];
			}
		}

		set<char> tempSet;
		string tempKey;
		cin >> tempKey;
		if(tempKey != "0")
			for (int i = 0; i < tempKey.length(); ++i)
			{
				tempSet.insert(tempKey[i]);
			}
		map<char, pair<int, int>> sampleM;
		queue<pair<int, int>> tempQ;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				{
					if (buildingMap[i][j] == '.')    tempQ.push(make_pair(i, j));
					else if(buildingMap[i][j] >= 'A' && buildingMap[i][j] <= 'Z')	sampleM[buildingMap[i][j]] = make_pair(i, j);
                    					else if(tempSet.find((char)(buildingMap[i][j] - 32)) != tempSet.end())  tempQ.push(make_pair(i, j));
				}
			}
		}
		int docCount = 0;
		int tempCount = 0;


		while (!tempQ.empty())
		{
			queue<pair<int, int>> sampleQ;
			sampleQ.push(make_pair(tempQ.front().first, tempQ.front().second));
			tempQ.pop();
			
			while (!sampleQ.empty())
			{
				int x = sampleQ.front().first;
				int y = sampleQ.front().second;
				moveCheck[x][y] = true;
				sampleQ.pop();

				for (int i = 0; i < 4; ++i)
				{
					int tempX = x + movX[i];
					int tempY = y + movY[i];

					if (tempX >= 0 && tempX < h && tempY >= 0 && tempY < w)
					{
						if (buildingMap[tempX][tempY] == '*')	continue;
						if (moveCheck[tempX][tempY])	continue;

						if (buildingMap[tempX][tempY] == '.')
						{
							sampleQ.push(make_pair(tempX, tempY));
						}
						else if (buildingMap[tempX][tempY] >= 'a' && buildingMap[tempX][tempY] <= 'z')
						{
;							sampleQ.push(make_pair(tempX, tempY));
							tempSet.insert(buildingMap[tempX][tempY]);

							auto it = sampleM.find((char)(buildingMap[tempX][tempY] - 32));

							if (it != sampleM.end())
							{
								sampleQ.push(make_pair(it->second.first, it->second.second));
							}
						}
						else if (buildingMap[tempX][tempY] == '$')
						{
							sampleQ.push(make_pair(tempX, tempY));
							++tempCount;
						}
						else
						{
							auto it = tempSet.find((char)(buildingMap[tempX][tempY] + 32));
							if (it != tempSet.end())
							{
								sampleQ.push(make_pair(tempX, tempY));
							}
							else
							{
								sampleM[buildingMap[tempX][tempY]] = make_pair(tempX, tempY);
							}
						}
						moveCheck[tempX][tempY] = true;
					}
				}
			}
			memset(moveCheck, false, sizeof(moveCheck[0][0]) * 101 * 101);

			if (docCount < tempCount)
				docCount = tempCount;
		}
		cout << docCount << '\n';
	}
	return 0;
}