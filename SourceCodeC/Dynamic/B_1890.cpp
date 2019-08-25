#include <iostream>

using namespace std;

int map[101][101];
int movCount = 0;

int N;

void Go(const int xPos, const int yPos)
{	
	if (xPos > N || yPos > N)
		return;
	if (map[xPos][yPos] == 0)
	{
		++movCount;
		return;
	}

	Go(xPos + map[xPos][yPos], yPos);
	Go(xPos, yPos + map[xPos][yPos]);
}
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> map[i][j];
		}
	}
	Go(1, 1);
	cout << movCount << '\n';
}