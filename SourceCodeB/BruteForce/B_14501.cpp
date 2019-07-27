#include <iostream>
using namespace std;

int dayInfo[16];
int payInfo[16];
int tempN;
int max = 0;
void GetReward(int day, int sum)
{

	if (dayInfo[day] - 1 <= tempN)
		GetReward(day + 1, payInfo[day] );
	if (dayInfo[day] + day - 1 <= tempN)
		GetReward(dayInfo[day] + day, sum + payInfo[day]);
	if (day + 1 <= tempN && dayInfo[day + 1] + day - 1 <= tempN)
		GetReward(dayInfo[day + 1] + day, sum + payInfo[day]);
	if (day >= tempN)
	{
		max = max < sum ? sum : max;
		return;
	}
}
int main(void)
{
	cin >> tempN;

	for (int i = 1; i <= tempN; i++)
	{
		cin >> dayInfo[i] >> payInfo[i];
	}
	GetReward(1, 0);

	cout << max << '\n';
	return 0;
}