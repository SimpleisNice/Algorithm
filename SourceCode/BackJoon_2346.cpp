#include <iostream>
#include <list>

using namespace std;
int main(void)
{
	int N;
	list<pair<int, int>> tempList;
	list<pair<int, int>>::iterator tempPos;
	// 풍선의 개수 및 범위
	do {
		cin >> N;
	} while (N < 1 || N > 1000);

	// 풍선에 들어갈 종이의 값 확인
	for (int i = 0; i < N; i++)
	{
		int temp;
		// 풍선에 들어갈 종이의 값의 범위
		do {
			cin >> temp;
		} while (temp < -N || temp > N);

		tempList.push_back({ i + 1, temp });
	}

	// 풍선내부의 종이 확인 및 종이에 따른 터트림
	tempPos = tempList.begin();
	while(1)
	{
		fprintf(stderr, "%d ", tempPos->first);
		int checkNum = tempPos->second;
		list<pair<int, int>>::iterator temp = tempPos;

		if (tempList.size() == 1)
			break;
		if (checkNum > 0)
			for (int i = 0; i < checkNum; ++i)
			{
				++tempPos;
				if (tempPos == tempList.end())
					tempPos = tempList.begin();

			}
		else
			for (int i = 0; i < -(checkNum); ++i)
			{
				if (tempPos == tempList.begin())
					tempPos = tempList.end();
				--tempPos;
			}
		tempList.erase(temp);
	}
    cout << endl;
	return 0;
}