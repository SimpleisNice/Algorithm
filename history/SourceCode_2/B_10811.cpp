#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    vector<int> tempVector;
    int n,m;

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        tempVector.push_back(i);
    }

    for(int k = 0; k < m; ++k)
    {
        int i,j;
        cin >> i >> j;
        reverse(tempVector.begin() + i - 1, tempVector.begin() + j);
    }

    for(int i = 0; i < n; ++i)
    {
        cout << tempVector[i] << " ";
    }
    return 0;
}