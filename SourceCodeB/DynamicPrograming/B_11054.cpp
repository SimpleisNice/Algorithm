#include <iostream>

using namespace std;
int A[1001];
int d[1001][2];
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
        d[i][0] = 1;
        for(int j = i; j >= 1; --j)
        {
            if(A[i] > A[j] && d[i][0] < d[j][0] + 1)
            {
                d[i][0] = d[j][0] + 1;
            }
        }
    }
        
    for(int i = N; i >= 1; --i)
    {
        d[i][1] = 1;
        for(int j = i; j <= N; ++j)
        {
            if(A[i] > A[j] && d[i][1] < d[j][1] + 1)
            {
                d[i][1] = d[j][1] + 1;
            }
        }
    }

    int max = 0;

    for(int i = 1; i <=N; ++i)
    {
        if(max < d[i][0] + d[i][1])
            max = d[i][0] + d[i][1];
    }

    printf("%d\n", max -1);
    return 0;
}