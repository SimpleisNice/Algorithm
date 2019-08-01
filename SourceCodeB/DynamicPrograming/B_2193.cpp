#include <iostream>

using namespace std;

int d[91] = {0,};
int main(void)
{
    int N;
    scanf("%d", &N);


    d[1] = 1;
    d[2] = 1;
    for(int i = 3; i <= N; i++)
    {
        d[i] = d[i - 1] + d[i - 2];
    }

    printf("%d\n", d[N]);
}