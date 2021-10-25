#include <iostream>
#include <vector>

using namespace std;

const int CLOCKS = 16;
const int TEMP_NUM = 99999;
bool switchInfo[11][16] = {
    {true, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false},
    {false, false, false, true, false, false, false, true, false, true, false, true, false, false, false, false},
    {false, false, false, false, true, false, false, false, false, false, true, false, false, false, true, true},
    {true, false, false, false, true, true, true, true, false, false, false, false, false, false, false, false},
    {false, false, false, false, false, false, true, true, true, false, true, false, true, false, false, false},
    {true, false, true, false, false, false, false, false, false, false, false, false, false, false, true, true},
    {false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, true},
    {false, false, false, false, true, true, false, true, false, false, false, false, false, false, true, true},
    {false, true, true, true, true, true, false, false, false, false, false, false, false, false, false, false},
    {false, false, false, true, true, true, false, false, false, true, false, false, false, true, false, false}
};


void btnPush(vector<int> & tempV, int btnPos)
{
    for(int i=0; i<CLOCKS; ++i)
    {
        if(switchInfo[btnPos][i])
        {
            tempV[i] = tempV[i] + 3 == 15 ? 3 : tempV[i] + 3;
        }
    }
}

int getCount(vector<int> & tempV, int btnPos)
{
    if(btnPos == 10)
    {
        for(int i=0; i<CLOCKS; ++i)
        {
            if(tempV[i] != 12)
                return TEMP_NUM;
        }
        return 0;
    }

    int count = TEMP_NUM;
    for(int i=0; i<4; ++i) 
    {
        count = min(count, i + getCount(tempV, btnPos + 1));
        btnPush(tempV, btnPos);
    }
    return count;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;

    while(c--)
    {
        vector<int> tempV(CLOCKS);
        for(int i=0; i<CLOCKS; ++i)
        {
            cin >> tempV[i];
        }

        int count = getCount(tempV, 0);
        if(count == TEMP_NUM)
            cout << -1 << "\n";
        else 
            cout << count << "\n";
    }
    return 0;
}