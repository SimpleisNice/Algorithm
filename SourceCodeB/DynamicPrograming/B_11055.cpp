#include <iostream>
#include <vector>

using namespace std;


int A[1001];
int d[1001];

void LIS(int N)
{
    for(int i = 1; i <= N; ++i)
    {
        d[i] = A[i];

        for(int j = i; j >= 1; --j)
        {
            if(A[i] > A[j])
            {
                if(d[i] < d[j] + A[i])
                {
                    d[i] = d[j] + A[i];
                }
            }
        }
    }
}
int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
    }
    LIS(N);

    int max = 0;
    for(int i = 1; i <= N; ++i)
    {
        if(max < d[i])
            max = d[i];
    }

    printf("%d\n", max);
    return 0;
}