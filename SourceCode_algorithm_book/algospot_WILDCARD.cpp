#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string tempStr[50];
string w;
int n;
bool checkResult = false;
void checkStr(int index, int tempIndex, int num)
{
    if(index == w.length() && tempIndex == tempStr[num].length())
    {   
        checkResult = true; 
        return;    
    }
    if(index == w.length() || tempIndex > tempStr[num].length())
        return;
    if(w[index] == '*')
    {
        checkStr(index,   tempIndex + 1, num);
        checkStr(index+1, tempIndex, num);
        checkStr(index+1, tempIndex + 1, num);
    }
    else
    {
        if(w[index] == '?' || w[index] == tempStr[num][tempIndex])
        {
            checkStr(index + 1, tempIndex + 1, num);
        }
    }
}
int main(void)
{
    int c;
    cin >> c;
    while (c--)
    {
        cin >> w;
        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> tempStr[i];
        }
        vector<string> tempVector;
        for (int i = 0; i < n; ++i)
        {
            checkResult = false;
            checkStr(0, 0, i);

            if(checkResult)
            {
                tempVector.push_back(tempStr[i]);
            }
        }
        sort(tempVector.begin(), tempVector.end());
        for(int i=0; i<tempVector.size(); ++i){
            cout << tempVector[i] << '\n';
        }
    }
    return 0;
}