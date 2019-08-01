#include <iostream>
#define mod 1000000000

using namespace std;


int d[101][10] ={0,};

void GetCount(int N)
{
    for(int i = 1; i <= 9; ++i)
    {
        d[1][i] = 1;
    }

    for(int i = 2; i <= N; ++i)
    {
        for(int j = 0; j <= 9; ++j)
        {
            if(j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
            if(j + 1 < 10) d[i][j] += d[i - 1][j + 1];

            d[i][j] %= mod;
        }
    }
    long long temp = 0;

    for(int i = 0; i <= 9; ++i)
    {
        temp += d[N][i];
    }
    cout << (temp % mod) << '\n';
}

int main(void)
{
    int N;
    cin >> N;

    GetCount(N);
    return 0;
}