#include <iostream>
#include <algorithm>

using namespace std;

int marbles[11];
bool checkMarble[11];
int n = 0;
int maxValue = 0;
void getMaxMarble(int sum, int cnt)
{
	if (cnt == n - 2)
	{
		maxValue = max(maxValue, sum);
		return;
	}
	for (int i = 2; i <= n - 1; ++i)
	{
		if (!checkMarble[i])
		{
			int tempA = 0;
			int tempB = 0;
			checkMarble[i] = true;
			for (int j = i - 1; j >= 1; --j)
			{
				if (!checkMarble[j])
				{
					tempA = marbles[j];
					break;
				}
			}
			for (int j = i + 1; j <= n; ++j)
			{
				if (!checkMarble[j])
				{
					tempB = marbles[j];
					break;
				}
			}
			getMaxMarble(sum + tempA * tempB, cnt + 1);
			checkMarble[i] = false;
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> marbles[i];
	}
	getMaxMarble(0, 0);
	cout << maxValue << '\n';
	return 0;
}
