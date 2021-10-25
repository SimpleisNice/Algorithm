#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> tempV(N);


	for (int i = 0; i < N; ++i)
	{
		cin >> tempV[i];
	}

	sort(tempV.begin(), tempV.end());


	for (int i = 0; i < N; ++i)
	{
		cout << tempV[i] << '\n';
	}
	return 0;
}