#include <iostream>
#include <climits>
using namespace std;

int N[100001];
int d[100001];
int main(void)
{
    int T;

    scanf("%d", &T);

    for(int i = 1; i <= T; ++i)
    {
        scanf("%d", &N[i]);
    }

    d[1] = N[1];
    for(int i = 2; i <= T; ++i)
    {
        d[i] = N[i];
        if(d[i] < d[i - 1] + N[i])
        {
            d[i] = d[i - 1] + N[i];
        }
    }

    int max = INT_MIN;

    for(int i = 1; i <= T; ++i)
    {
        if(max < d[i])
            max = d[i];
    }

    printf("%d\n", max);
    return 0;
}