#include <iostream>
using namespace std;

int d[100001];
int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; ++i)
    {
        d[i] = i;

        for(int j = 1; j*j <= i; ++j)
        {
            if(d[i] > d[i - j * j] + 1)
                d[i] = d[i - j * j] + 1;
        }
    }
    printf("%d\n", d[N]);
    return 0;
}