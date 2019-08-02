// 스티커(9465)
#include <iostream>

using namespace std;

int d[100001][3];
int value[100001][2];

int main(void)
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int N;
        scanf("%d", &N);

        for(int i = 0; i <= 1; ++i)
        {
            for(int j = 1; j<= N; ++j)
            {
                scanf("%d", &value[j][i]);
            }
        }
        d[1][0] = 0;
        d[1][1] = value[1][0];
        d[1][2] = value[1][1];

        for(int i = 2; i <= N; i++)
        {
            d[i][0] = d[i-1][0] > d[i-1][1] ? 
                    d[i-1][0] > d[i-1][2] ? d[i-1][0] : d[i-1][2] :
                    d[i-1][1] > d[i-1][2] ? d[i-1][1] : d[i-1][2];

            d[i][1] = d[i-1][0] > d[i-1][2] ? d[i-1][0] : d[i-1][2];
            d[i][1] += value[i][0];

            d[i][2] = d[i-1][0] > d[i-1][1] ? d[i-1][0] : d[i-1][1];
            d[i][2] += value[i][1];
        }
        
        int max =   d[N][0] > d[N][1] ? 
                    d[N][0] > d[N][2] ? d[N][0] : d[N][2] :
                    d[N][1] > d[N][2] ? d[N][1] : d[N][2];

        printf("%d\n", max);
        
    }
    return 0;
}