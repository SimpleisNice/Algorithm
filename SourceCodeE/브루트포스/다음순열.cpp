#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> tempV(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> tempV[i];
    }
    if (next_permutation(tempV.begin(), tempV.end()))
    {
        for (vector<int>::iterator it = tempV.begin(); it != tempV.end(); ++it)
        {
            cout << *it << " ";
        }
    }
    else
    {
        cout << -1 << "\n";
    }
    return 0;
}