// 가장 긴 증가하는 부분 수열
#include <iostream>
using namespace std;
int A[1001];
int d[1001];
int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		d[i] = 1;
		for (int j = i - 1; j >= 1; --j)
		{
			if (A[i] > A[j])
			{
				if (d[i] <= d[j])
					d[i] = d[j] + 1;
			}
		}
	}
	int tempMax = 0;

	for (int i = 1; i <= N; ++i)
	{
		if (tempMax < d[i])
			tempMax = d[i];
	}

	printf("%d\n", tempMax);
	return 0;
}