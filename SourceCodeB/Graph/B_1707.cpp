#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;


vector<int> tempV[200001];
bool useCheck[20001];
int colorCheck[20001];      //1,2

string BFS()
{
	int tempN = 1;
	//bfs
	queue<int> tempQ;

	tempQ.push(1);
	useCheck[1] = true;
	colorCheck[1] = tempN++;

	while (!tempQ.empty())
	{
		int tempNum = tempQ.front();
		tempQ.pop();

		for (int i = 0; i < tempV[tempNum].size(); ++i)
		{
			int temp = tempV[tempNum][i];
			if (useCheck[temp])
			{
				if (colorCheck[temp] == colorCheck[tempNum])
				{
					return "NO\n";
				}
				continue;
			}

			useCheck[temp] = true;
			colorCheck[temp] = tempN;
			tempQ.push(temp);
		}
		tempN = tempN == 1 ? 2 : 1;
	}
	return "YES\n";
}
int main(void)
{
	int K, V, E;

	cin >> K;

	while (K--)
	{
		cin >> V >> E;


		for (int i = 0; i < E; ++i)
		{
			int tempA, tempB;
			cin >> tempA >> tempB;

			tempV[tempA].push_back(tempB);
			tempV[tempB].push_back(tempA);
		}

		for (int i = 0; i < E; i++)
		{
			sort(tempV[i].begin(), tempV[i].end());
		}

		cout << BFS();

		for (int i = 0; i < E; ++i)
		{
			tempV[i].clear();
		}
		memset(useCheck, false, V);
		memset(colorCheck, 0, V);
	}

	return 0;
}