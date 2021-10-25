#include <iostream>
#include <algorithm>

using namespace std;

int getInfo[1500000][2];
int setInfo[1500000];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> getInfo[i][0] >> getInfo[i][1];
    }

    int tempValue = 0;
    for(int i=0; i<= n; ++i)
    {
        tempValue = max(tempValue, setInfo[i]);
        if(i + getInfo[i][0] > n) continue;
        setInfo[i + getInfo[i][0]] = max(setInfo[i + getInfo[i][0]], tempValue + getInfo[i][1]);
    }

    cout << tempValue << '\n';
    return 0;
}