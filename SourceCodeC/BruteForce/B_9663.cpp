#include <iostream>
#include <algorithm>
#include <vector>

int xPos[] = {0, 0, -1, 1, -1, 1, -1, 1};
int yPos[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int map[15][15];
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	vector<int> tempMap(N * N);

	for(int i = 0; i < N; ++i)
	{
		tempMap[i] = 1;
	}

	do
	{
		// set map
		for(int i = 0; i < N * N; ++i)
		{
			int x, y;
			if(tempMap[i] == 1)
			{
				x = i / N;
				y = i % N;
			}
		}	
		// set check
	}while(prev_permutation(tempMap.begin(), tempMap.end()));
	return 0;
}