#include <iostream>
#define mod 1000000000
using namespace std;


long d[201][201];

int main(void)
{
    int N, K;

    scanf("%d %d", &N, &K);


    d[0][0] = 1L;
    for(int i = 1; i <= K; ++i)
    {
        for(int j = 0; j <= N; ++j)
        {
            for(int l = 0; l <= j; ++l)
            {
                d[i][j] += d[i - 1][j - l];
                d[i][j] %= mod;
            }
        }
    }

    printf("%d\n", d[K][N]);
}