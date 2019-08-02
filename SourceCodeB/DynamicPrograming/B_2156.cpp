#include <iostream>
#include <algorithm>
using namespace std;


int value[10001];
int d[10001][3];
int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &value[i]);
    }

    d[1][0] = 0;
    d[1][1] = value[1];
    d[1][2] = 0;

    d[2][0] = value[1];
    d[2][1] = value[2];
    d[2][2] = value[1] + value[2];


    for(int i = 3; i <= N; ++i)
    {
        d[i][0] = max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
        d[i][1] = d[i -1][0] + value[i];
        d[i][2] = d[i -1][1] + value[i];
    }

    int maxTemp = 0;

    for(int i = 0; i < 3; ++i)
    {
        if(maxTemp < d[N][i])
            maxTemp = d[N][i];
    }

    printf("%d\n", maxTemp);
    return 0;
}