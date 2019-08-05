#include <iostream>
#include <climits>
using namespace std;

int A[1001];
int d[1001];
int main(void)
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
    }

    for(int i = 1; i <= N; ++i)
    {
        d[i] = 1;
        for(int j = i; j >= 1; --j)
        {
            if(A[i] < A[j])
            {
                if(d[i] < d[j] + 1)
                {
                    d[i] = d[j] + 1;
                }
            }
        }
    }

    int max = 0; 

    for(int i = 1; i <= N; ++i)
    {
        if(max < d[i])
            max = d[i];
    }

    printf("%d\n", max);
    return 0;
}