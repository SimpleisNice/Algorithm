#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int triangle[100][100];
int setInfo[100][100];
int n;
void getMax(int x, int y, int sum)
{
    if (x == n || y > x)
        return;
    if(setInfo[x][y] > sum + triangle[x][y])
        return;

    setInfo[x][y] = sum + triangle[x][y];
    getMax(x + 1, y, setInfo[x][y]);
    getMax(x + 1, y + 1, setInfo[x][y]);
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;

    while (c--)
    {
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                cin >> triangle[i][j];
            }
        }
        getMax(0, 0, 0);

        int maxValue = 0;
        for(int i=0; i<n; ++i)
        {
            maxValue = max(maxValue, setInfo[n-1][i]);
                    
        }
        cout << maxValue << '\n';
        memset(setInfo, 0, sizeof(setInfo));
    }
    return 0;
}