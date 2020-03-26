#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;

int gardenMap[50][50];
int gardenInfo[50][50][2];
int moveX[] = {0,0,-1,1};
int moveY[] = {-1,1, 0,0};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,m,g,r;
	cin >> n >> m >> g >> r;
	
	int useGround = 0;
	vector<pair<int,int>> useGroundInfo;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j)
		{
			cin >> gardenMap[i][j];
			if(gardenMap[i][j] == 2)
			{	
				++useGround;
				useGroundInfo.push_back(make_pair(i,j));
			}
		}
	}

	vector<int> setGround(useGround);
	for(int i=0; i<g; ++i)
	{
		setGround[i] = 2;
	}
	for(int i=g; i<g+r; ++i)
	{
		setGround[i] = 1;
	}
	int flowerCount = 0;
	do{
		int tempFlower = 0;
		queue<tuple<int,int,int> tempQ;
		for(int i=0; i<useGroun; ++i)
		{
			if(setGround[i] != 0)
			{
				tempQ.push(make_tuple(useGroundInfo[i].first, useGroundInfo[i].second, setGround[i]);
				gardenInfo[useGroundInfo[i].first][useGroundInfo[i].second][setGround[i]] = 1;
			}
		}
		while(tempQ.empty())
		{
			int x,y,color, count;
			tie(x,y,color) = tempQ.front();
			count = gardenInfo[x][y][color];
			tempQ.pop();

			if(count == -1)
				continue;
			for(int i=0; i<4; ++i)
			{
				int tempX = x + moveX[i];
				int tempY = y + moveY[i];
				int difColor = color % 2 + 1;
				if(tempX < 0 || tempX >= n || tempY < 0 || tempY >= m)
					continue;
				if(gardenMap[tempX][tempY] == 0 || gardenInfo[tempX][tempY][color] != 0)  
					continue;
				if(gardenInfo[tempX][tempY][color] == -1)
					continue;
				if(count + 1 == gardenInfo[tempX][tempY][difColor])
				{	
					gardenInfo[tempX][tempY][difColor] = gardenInfo[tempX][tempY][color] = -1;
					++tempFlower;
				}
				else{
					gardenInfo[tempX][tempY][color] = count + 1;
					tempQ.push(make_tuple(tempX, tempY, color));
				}
			}
			
		}
		flowerCount = max(flowerCount, tempFlower);
		memset(gardenInfo, 0, sizeof(gardenInfo));
	}while(prev_permutation(setGround.begin(), setGround.end()));

	cout << flowerCount << "\n";
	return 0;
}