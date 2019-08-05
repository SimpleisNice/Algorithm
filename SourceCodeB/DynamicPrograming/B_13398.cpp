#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int d[100001][2];
int main(void)
{
	int N;
	int tempMax = INT_MIN;
	scanf("%d", &N);

	vector<int> tempV(N + 1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &tempV[i]);
	}


	d[1][0] = tempV[1];
    d[N][1] = tempV[N];
    if(N > 1)
	{
        for (int i = 2; i <= N; ++i)
	    {
            d[i][0] = max(d[i-1][0] + tempV[i], tempV[i]);
            d[N + 1 - i][1] = max(d[N + 2 - i][1] + tempV[N + 1 - i], tempV[N + 1 - i]);
	    }

        for(int i = 1; i <= N; ++i)
        {
            if(tempMax < d[i][0])
                tempMax = d[i][0];
        }
        for(int i = 2; i <= N-1; ++i)
        {
            if(tempMax < d[i-1][0] + d[i + 1][1])
                tempMax = d[i-1][0] + d[i + 1][1];
        }
    }
    else
        tempMax = d[1][0];
	printf("%d\n", tempMax);
}