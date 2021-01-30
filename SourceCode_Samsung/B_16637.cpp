#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int main(void)
{
    int n;
    string tempStr;
    cin >> n >> tempStr;

    int num[10];
    vector<pair<int,char>> opInfo;
    int index = 0;
    for(int i=0; i<tempStr.length(); ++i) {
        if(tempStr[i] - '0' >= 0 && tempStr[i] - '0' <= 9)
            continue;
        opInfo.push_back(make_pair(index++, tempStr[i]));
    }

    int tempStrLen = tempStr.length();
    int tempLen = tempStr.length() - opInfo.size();
    long tempNum[10];
    bool checkNum[10];
    long maxNum = INT_MIN;
    do
    {
        for(int i=0; i<tempStrLen; ++i)
        {    
            tempNum[i] = num[i];
            checkNum[i] = true;
        }
        for(int i=0; i<tempLen; ++i) {
            int fNum = 0;
            int BNum = 0;
            int pos = opInfo[i].first;

            int tempIndex = 0;
            while(true)
            {
                if(checkNum[pos - tempIndex])
                {
                    fNum = tempNum[pos - tempIndex];
                    checkNum[pos- tempIndex] = true;
                    break;
                }
                --tempIndex;
            }

            tempIndex = 0;
            while(true)
            {
                if(checkNum[pos + 1 + tempIndex])
                {
                    BNum = tempNum[pos + 1 + tempIndex];
                    break;
                }
                ++tempIndex;
            }

            if(opInfo[i].second == '+'){
                tempNum[pos + 1 + tempIndex] = fNum + BNum;
            }else if(opInfo[i].second == '-') {
                tempNum[pos + 1 + tempIndex] = fNum - BNum;
            }else {
                tempNum[pos + 1 + tempIndex] = fNum * BNum;
            }
        }
        for(int i=0; i<tempStrLen; ++i)
        {    
            if(checkNum[i])
            {
                maxNum = max(maxNum, tempNum[i]);
                break;
            }
        }
        cout << maxNum << "\n";
    }while(next_permutation(opInfo.begin(), opInfo.end()));
    cout << maxNum << "\n";
}