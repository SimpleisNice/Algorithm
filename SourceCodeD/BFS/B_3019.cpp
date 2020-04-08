#include <iostream>

using namespace std;

int blocks[7][4][4][2] = {
	{{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	 {{0, 0}, {1, 0}, {2, 0}, {3, 0}}},

	{{{0, 0}, {0, 1}, {1, 0}, {1, 1}}},

	{{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	 {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
	 {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	 {{0, 1}, {1, 0}, {1, 1}, {2, 0}}},

	{{{0, 1}, {0, 2}, {1, 0}, {1, 1}},
	 {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	 {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
	 {{0, 0}, {1, 0}, {1, 1}, {2, 1}}},

	{{{0, 1}, {1, 0}, {1, 1}, {1, 2}},
	 {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
	 {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	 {{0, 1}, {1, 0}, {1, 1}, {2, 0}}},

	{{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	 {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
	 {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	 {{0, 1}, {1, 1}, {2, 0}, {2, 1}}},

	{{{0, 2}, {1, 0}, {1, 1}, {1, 2}},
	 {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	 {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
	 {{0, 0}, {0, 1}, {1, 1}, {2, 1}}}
};

int blockMap[105][105];
int turnBlock[7] = { 2,1,2,2,4,4,4 };
int findPos(int c, int blockLine)
{
	int totalCount = 0;
	for (int i = 0; i < turnBlock[c]; ++i)
	{
		int posY = 0;
		while (true)
		{
			int tempIndex = 0;
			if (posY < blockLine)
			{
				while (true)
				{
					if (tempIndex > 100)
						break;
					bool blockCheck = true;
					for (int j = 0; j < 4; ++j)
					{
						int tempX = tempIndex + blocks[c][i][j][0];
						int tempY = posY + blocks[c][i][j][1];

						if (tempX >= 104 || tempY > blockLine - 1 || blockMap[tempX][tempY] == 1)
						{
							blockCheck = false;
							break;
						}
					}
					if (blockCheck)
					{
						bool setCheck = true;
						for (int j = 0; j < 4; ++j)
						{
							int tempX = tempIndex + blocks[c][i][j][0];
							int tempY = posY + blocks[c][i][j][1];
							blockMap[tempX][tempY] = 2;
						}

						for (int j = 0; j < 4; ++j)
						{
							int tempX = tempIndex + blocks[c][i][j][0];
							int tempY = posY + blocks[c][i][j][1];
							if (tempX - 1 >= 0)
							{
								if (blockMap[tempX - 1][tempY] == 0)
								{
									setCheck = false;
								}
							}
						}

						if (setCheck)
							++totalCount;
						for (int j = 0; j < 4; ++j)
						{
							int tempX = tempIndex + blocks[c][i][j][0];
							int tempY = posY + blocks[c][i][j][1];
							blockMap[tempX][tempY] = 0;
						}
						break;
					}
					++tempIndex;
				}
			}
			else
				break;

			++posY;
		}
	}
	return totalCount;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int p, c;
	cin >> p >> c;

	for (int i = 0; i < p; ++i)
	{
		int tempHeight;
		cin >> tempHeight;

		for (int j = 0; j < tempHeight; ++j)
		{
			blockMap[j][i] = 1;
		}
	}
	cout << findPos(c - 1, p) << "\n";

	return 0;
}