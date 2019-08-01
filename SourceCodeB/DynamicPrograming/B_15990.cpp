#include <iostream>
#define mod 1000000009
using namespace std;

int d[100001][4];

void GetCount(int tempN)
{
    d[1][1] = 1; d[1][2] = 0; d[1][3] = 0;
    d[2][1] = 0; d[2][2] = 1; d[2][3] = 0;
    d[3][1] = 1; d[3][2] = 1; d[3][3] = 1;

    for(int i = 4; i <= tempN; ++i)
    {
        d[i][1] = (d[i -1][2] + d[i -1][3]) % mod;
        d[i][2] = (d[i -2][1] + d[i -2][3]) % mod;
        d[i][3] = (d[i -3][1] + d[i -3][2]) % mod;
    }

    long long sum = 0;
    for(int i = 1; i <= 3; ++i)
    {
        sum += d[tempN][i];
    }

    cout << (sum % mod) << '\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempNum;
    cin >> tempNum;
    while(tempNum--)
    {
        int N;
        cin >> N;
    
        GetCount(N);
    }
    return 0;
}