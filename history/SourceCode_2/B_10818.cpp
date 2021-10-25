#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num;
    cin >> num;
    vector<int> tempVector(num);

    for(int i = 0; i < num; ++i)
    {
        cin >> tempVector[i];
    }

    sort(tempVector.begin(), tempVector.end());

    cout << tempVector[0] << " " << tempVector[num - 1];
    return 0;
}