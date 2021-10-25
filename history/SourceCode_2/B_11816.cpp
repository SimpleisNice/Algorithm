#include <iostream>
#include <string>

using namespace std;

int GetPow(int num, int index)
{
    int tempNum = 1;
    for(int i = 0; i < index; ++i)
    {
        tempNum *= num;
    }
    return tempNum;
}
void HexFunc(string tempS)
{
    string hexStr = tempS.substr(2);
    int totalSum = 0;
    for(int i = 0; i < hexStr.length(); ++i)
    {
        if(hexStr[i] < 'a' || hexStr[i] > 'f')
        {
            totalSum += GetPow(16, hexStr.length() - i - 1) * (hexStr[i] - '0');
        }
        else
        {
            totalSum += GetPow(16, hexStr.length() - i - 1) * (hexStr[i] - 'a' + 10);
        }
    }

    cout << totalSum;
}
void OctFunc(string tempS)
{
    string octStr = tempS.substr(1);
    int totalSum = 0;

    for(int i = 0; i < octStr.length(); ++i)
    {
        totalSum += GetPow(8, octStr.length() - i - 1) * (octStr[i] - '0');
    }
    cout << totalSum;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string tempStr;
    cin >> tempStr;

    if(tempStr[0] == '0' && tempStr.length() > 1)
    {
        if(tempStr[1] == 'x')
        {
            HexFunc(tempStr);
        }
        else
        {
            OctFunc(tempStr);
        }
    }
    else
    {
        cout << tempStr;
    }

}