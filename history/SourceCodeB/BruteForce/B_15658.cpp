#include <iostream>
#include <climits>

using namespace std;

int tempMax = INT_MIN;
int tempMin = INT_MAX;

int tempValue[12];
int	tempOp[4];

void GetCirculation(int N, int sum, int index, int op1, int op2, int op3, int op4)
{
	if(index == N)
	{
		if(tempMax < sum)
			tempMax = sum;
		if(tempMin > sum)
			tempMin = sum;
		return;
	}

	if(op1)
	{
		GetCirculation(N, sum + tempValue[index], index + 1, op1 -1, op2, op3, op4);
	}
	if(op2)
	{
		GetCirculation(N, sum - tempValue[index], index + 1, op1, op2 -1, op3, op4);
	}
	if(op3)
	{ 
		GetCirculation(N, sum * tempValue[index], index + 1, op1, op2, op3 - 1, op4);
	}
	if(op4)
	{
		GetCirculation(N, sum / tempValue[index], index + 1, op1, op2, op3, op4 -1);
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);

	cin.tie(0);

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cin >> tempValue[i];
	}
	for(int i =0 ; i< 4; ++i)
	{
		cin >> tempOp[i];
	}

	GetCirculation(N, tempValue[0], 1, tempOp[0], tempOp[1], tempOp[2], tempOp[3]);

	cout << tempMax << '\n' << tempMin <<'\n';
	return 0;
}