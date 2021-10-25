#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int setItems[6][3];
int attackCheck[61][61][61];
int attackCount = INT_MAX;

void makeItems()
{
	vector<int> tempNum = { 1,3,9 };
	int index = 0;
	do
	{
		setItems[index][0] = tempNum[0];
		setItems[index][1] = tempNum[1];
		setItems[index][2] = tempNum[2];
		++index;
	} while (next_permutation(tempNum.begin(), tempNum.end()));
}

void getAttackCount(vector<int> scv, int count)
{
	int sum = scv[0] + scv[1] + scv[2];
	if (sum == 0)
	{
		attackCount = min(attackCount, count);
		return;
	}

	vector<int> tempV(3);
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			tempV[j] = scv[j] - setItems[i][j] > 0 ? scv[j] - setItems[i][j] : 0;
		}
		if (attackCheck[tempV[0]][tempV[1]][tempV[2]] == 0 || attackCheck[tempV[0]][tempV[1]][tempV[2]] > count + 1)
		{
			attackCheck[tempV[0]][tempV[1]][tempV[2]] = count + 1;
			getAttackCount(tempV, count + 1);
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	makeItems();
	vector<int> scv(3);
	for (int i = 0; i < n; ++i)
	{
		cin >> scv[i];
	}
	for (int i = n; i < 3; ++i)
	{
		scv[i] = 0;
	}
	attackCheck[scv[0]][scv[1]][scv[2]] = true;
	getAttackCount(scv, 0);

	cout << attackCheck[0][0][0] << '\n';
	return 0;
}