#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> tempStr(4);

    for(int i = 0; i < 4; ++i)
    {
        cin >> tempStr[i];
    }

    string tempA = tempStr[0] + tempStr[1];
    string tempB = tempStr[2] + tempStr[3];
    long long sum = stoll(tempA) + stoll(tempB);

    cout << sum << '\n';
    return 0;
}