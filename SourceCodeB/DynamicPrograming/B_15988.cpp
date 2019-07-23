#include <iostream>
using namespace std;

int tempArray[1000001];
int GetSumList(int temp, int totalCount)
{
    if(temp == 0)
        return ++totalCount;
    if(temp < 0)
        return 0;
    if(tempArray[temp] > 0)
        return tempArray[temp];
    tempArray[temp] = GetSumList(temp-1, totalCount)  % 1000000009 + 
                        GetSumList(temp-2, totalCount) % 1000000009 + 
                        GetSumList(temp-3, totalCount) % 1000000009;
    
    return tempArray[temp];
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN;
    cin >> tempN;
    while(tempN--)
    {
        int tempNum;
        cin >> tempNum;
        cout << GetSumList(tempNum, 0) << '\n';
    }
    return 0;
}