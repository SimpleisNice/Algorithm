#include <iostream>

using namespace std;

long d[91][2];
int main(void)
{
    int N;
    scanf("%d", &N);


    d[1][0] = 0; d[1][1] = 1;
    d[2][0] = 1; d[2][1] = 0;

    for(int i = 3; i <= N; ++i)
    {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }


    printf("%ld\n", d[N][0] + d[N][1]);
}