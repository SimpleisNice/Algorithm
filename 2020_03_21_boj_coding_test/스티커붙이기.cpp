#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> stickerSize;

int noteBook[100][100];
int stickerShape[100][4][10][10];
int n, m, stickerCount;

void setShape(int index)
{
	int x = stickerSize[index].first;
	int y = stickerSize[index].second;

	int rotation = 1;
	while (rotation != 4)
	{
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				stickerShape[index][rotation][j][i] = stickerShape[index][rotation - 1][x - 1 - i][j];
			}
		}
		int tempPosX = x;
		x = y;
		y = tempPosX;

		++rotation;
	}
}

bool checkSticker(int index, int rotation, int x, int y)
{
	int tempX = 0;
	while (tempX + x <= n)
	{
		int tempY = 0;
		bool isOk = false;

		while (tempY + y <= m)
		{
			bool posCheck = false;
			for (int i = 0; i < x; ++i)
			{
				for (int j = 0; j < y; ++j)
				{
					if (noteBook[i + tempX][j + tempY] == 1 && stickerShape[index][rotation][i][j] == 1)
					{
						posCheck = true;
						break;
					}
				}
				if (posCheck)
					break;
			}
			if (!posCheck)
			{
				isOk = true;
				break;
			}
			++tempY;
		}
		if (isOk)
		{
			for (int i = 0; i < x; ++i)
			{
				for (int j = 0; j < y; ++j)
				{
					if(stickerShape[index][rotation][i][j] == 1)
						noteBook[i + tempX][j + tempY] = 1;
				}
			}
			return true;
		}
		++tempX;
	}
	return false;
}
void attachSticker(int index)
{
	int x = stickerSize[index].first;
	int y = stickerSize[index].second;

	int rotation = 0;

	while (rotation != 4)
	{
		if (checkSticker(index, rotation, x, y))
			break;
		int tempX = x;
		x = y;
		y = tempX;
		++rotation;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> stickerCount;
	stickerSize.resize(stickerCount);

	for (int i = 0; i < stickerCount; ++i)
	{
		int x, y;
		cin >> x >> y;
		stickerSize[i].first = x;
		stickerSize[i].second = y;

		for (int j = 0; j < x; ++j)
		{
			for (int k = 0; k < y; ++k)
			{
				cin >> stickerShape[i][0][j][k];
			}
		}
	}

	for (int i = 0; i < stickerCount; ++i)
	{
		setShape(i);
	}

	for (int i = 0; i < stickerCount; ++i)
	{
		attachSticker(i);
	}

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (noteBook[i][j] == 1)
				++count;
		}
	}

	cout << count << "\n";
	return 0;
}