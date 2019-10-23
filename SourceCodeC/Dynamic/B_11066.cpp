#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int d[501][501];
int totalSum;
int n;
void Go(int k)
{
    if(k > n) return;
    
    Go(k + 1);

    int sum = 0;
    for(int i=k; i<=n; ++k)
    {

    }
    for(int i=1; i<=k; ++i)
    {
        sum += d[i][1];
    }
    d[1][k] = sum;
    sum = 0;

    for(int j=k+1; j<=n; ++j)
    {
        sum += d[j][1];
    }
    d[k+1][n] = sum;
    sum = d[1][k] + d[k+1][n];

    if(sum < d[1][n])
        d[1][n] = sum;
        
}
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        totalSum = 0;
        d[1][n] = INT_MAX;

        for(int i=1; i<=n; ++i)
        {
            cin >> d[i][1];
            totalSum += d[i][1];
        }     
        Go(1);

        cout << '\n' << d[1][n] + totalSum << '\n';   
        memset(d, 0, sizeof(d));
    }
    return 0;
}