#include <iostream>
#include <vector>
using namespace std;

struct JO_LIST
{
    int num;
    bool isCheck;
};

struct JO_LIST tempList[5001];
vector<int> tempVector;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    tempVector.resize(n);
    
    for(int i=1; i<=n; ++i)
    {
        tempList[i].num = i;
        tempList[i].isCheck = false;
    }

    int useCount = 0;
    int index = 0;

    while(true)
    {
        int moveCheck = 0;
        if(useCount == n)
            break;

        while(true)
        {
            if(moveCheck == k)
            {   
                tempList[index].isCheck = true;
                tempVector[useCount] = tempList[index].num;
                ++useCount;
                break;
            }
            if (index + 1 > n)
                index = 1;
            else 
                ++index;

            if(tempList[index].isCheck)
                continue;
            ++moveCheck;
        }
    }

    cout << '<';
    for(int i=0; i<n-1; ++i)
    {
        cout << tempVector[i] << ", ";
    }
    cout << tempVector[n-1] << ">\n";

    return 0;
}