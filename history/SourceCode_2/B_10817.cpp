#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> tempVector(3);
    for(int i = 0; i < 3; ++i)
    {
        cin >> tempVector[i];
    }

    sort(tempVector.begin(), tempVector.end());

    cout << tempVector[1];
    return 0;
}