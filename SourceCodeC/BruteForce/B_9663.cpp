#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int map[225];
vector<int> mapV;
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	int totalCount = 0;
	cin >> N;
	mapV.resize(N * N );

	for (int i = 0; i < N; ++i)
	{
		mapV[i] = 1;
	}


	do
	{
		int queen;
		bool checkQueen = false;
		for (int i = 0; i < N; ++i)
		{
			queen = 0;
			for (int j = N * i; j < N * i + N; ++j)
			{
				if (mapV[j] == 1)
				{
					++queen;
					if (queen == 2)
					{
						checkQueen = true;
						break;
					}
				}
			}
			if (checkQueen)
			{
				break;
			}
		}
		if (checkQueen)
		{
			continue;
		}
		// ｜
		for (int i = 0; i < N; ++i)
		{
			queen = 0;
			for (int j = i; j <= i + N * (N - 1); j += N)
			{
				if (mapV[j] == 1)
				{
					++queen;
					if (queen == 2)
					{
						checkQueen = true;
						break;
					}
				}
			}
			if (checkQueen)
			{
				break;
			}
		}
		if (checkQueen)
		{
			continue;
		}

		// /
		if (N != 1)
		{
			int temp = 2;
			for (int i = 1; i < N; ++i)
			{
				queen = 0;
				for (int j = 0; j < temp; ++j)
				{
					if (mapV[i + (N - 1) * j] == 1)
					{
						++queen;
						if (queen == 2)
						{
							checkQueen = true;
							break;
						}
					}

				}
				if (checkQueen)
				{
					continue;
				}
				++temp;
			}
			if (checkQueen)
			{
				continue;
			}
			temp = N - 1;
			for (int i = N * 2 - 1; i < N * N - 1; i += N)
			{
				int queue = 0;
				for (int j = 0; j < temp; ++j)
				{
					if (mapV[i + (N - 1) * j] == 1)
					{
						++queen;
						if (queen == 2)
						{
							checkQueen = true;
							break;
						}
					}
				}
				if (checkQueen)
				{
					continue;
				}
				--temp;
			}
			if (checkQueen)
			{
				continue;
			}


			// '\'
			temp = 2;
			for (int i = N - 2; i >= 0; --i)
			{
				for (int j = 0; j < temp; ++j)
				{
					if (mapV[i + (N + 1) * j] == 1)
					{
						++queen;
						if (queen == 2)
						{
							checkQueen = true;
							break;
						}
					}
				}
				if (checkQueen)
				{
					continue;
				}
				++temp;
			}
			if (checkQueen)
			{
				continue;
			}

			temp = N - 1;
			for (int i = N; i < N * (N - 1); i += N)
			{
				for (int j = 0; j < temp; ++j)
				{
					if (mapV[i + (N + 1) * j] == 1)
					{
						++queen;
						if (queen == 2)
						{
							checkQueen = true;
							break;
						}
					}
				}
				if (checkQueen)
				{
					continue;
				}
				--temp;
			}
			if (checkQueen)
			{
				continue;
			}
		}
		++totalCount;
	} while (prev_permutation(mapV.begin(), mapV.end()));

	cout << totalCount << '\n';
}