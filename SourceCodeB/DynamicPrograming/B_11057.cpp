#include <iostream>
#define mod 10007
using namespace std;

int d[1001][10] = {0 ,};
void GetResult(int num)
{
    for(int i = 0; i <= 9; ++i)
    {
        d[1][i] = 1;
    }

    for(int i = 2; i <= num; ++i)
    {
        for(int j = 0; j <= 9; ++j)
        {
            for(int k = 0; k <= j; ++k)
            {
                d[i][j] += d[i -1][k];
                d[i][j] %= mod;
            }
        }
    }

    long long tempSum = 0;
    for(int i = 0; i <= 9; ++i)
    {
        tempSum += d[num][i];
    }

    cout << (tempSum % mod) << '\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    GetResult(N);
    return 0;
}