#include <iostream>

using namespace std;


int minList[1000001];
int GetMinList(int tempX)
{
    if(tempX == 1)
        return 0;
    
    if(minList[tempX] > 0)
        return minList[tempX];

    minList[tempX] = GetMinList(tempX - 1) + 1;

    if(tempX % 2 == 0)
    {
        int temp = GetMinList(tempX / 2) + 1;
        if(minList[tempX] > temp) 
            minList[tempX] = temp;
    }
    if(tempX % 3 == 0)
    {
        int temp = GetMinList(tempX / 3) + 1;
        if(minList[tempX] > temp)
            minList[tempX] = temp;
    }
    return minList[tempX];
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempX;
    cin >> tempX;

    cout << GetMinList(tempX) << endl;
    return 0;
}