#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int setHp;
    int stage;
    const int hp = 1000;
    cin >> stage;
    // 1, 2, 4, 7, 11, 16, 22
    int stageSet = (stage - 1) / 200 + 1;
    int temp = 0;
    int defaultHP = 0;
    for(int i = 1; i <= stageSet; ++i)
    {
        if(i == stageSet)
            defaultHP += (i + temp) * 1000 * (stage - (i-1) * 200);
        else
            defaultHP += (i + temp) * 1000 * 200;
        cout << i << " + " << temp << " " <<defaultHP << endl;

        ++temp;
    }
    cout << defaultHP << endl;
    return 0;
}