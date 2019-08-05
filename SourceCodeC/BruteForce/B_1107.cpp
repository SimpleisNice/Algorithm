#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<int> N, tempV;
int channel;
int M;
string tempN;
int stringLen;
int minCount;
bool errorBtn[11];

int CheckMinus(int num)
{
    if(num < 0)
        return num * -1;
    return num;
}

void GetCloseNum()
{
    int goN = stoi(tempN);
    int tempA;
    int tempB = 0;
    

    for(int i = 0; i < stringLen; ++i)
    {

        int tempMax = -100;
        for(int j = 0; j < 10; ++j)
        {
            if(!errorBtn[j])
            {
                int temp = N[i] - j;

                temp = CheckMinus(temp);
                if(N[i] - tempMax > temp)
                    tempMax = j;
            }
        }
        tempV[i] = tempMax;        
    }

    for(int i = tempV.size() -1; i >= 0; --i )
    {
        tempB += tempV[tempV.size() -1 - i] * pow(10, i);
    }
    cout << goN <<" " << tempB << '\n';
    int useNum;
    if(CheckMinus(goN - channel) > CheckMinus(goN - tempB))
    {
        useNum = tempB;
        minCount += stringLen;
        
        if(tempV[tempV.size() -1] == 0)
            minCount -= 1;
    }
    else
    {
        useNum = channel;
    }
    while(true)
    {
        if(useNum == goN)
            break;
        if(useNum < goN)
        {
            ++useNum;
        }
        else
        {
            --useNum;
        }
        ++minCount;
    }
    cout << minCount << '\n';
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    channel = 100;
    minCount = 0;

    cin >> tempN;
    
    stringLen = tempN.length();

    N.resize(stringLen);
    tempV.resize(stringLen);
    
    for(int i =0; i < stringLen; ++i)
    {
        N[i] = tempN[i] - '0';
    }

    cin >> M;
    // check error btn
    for(int i = 0; i <M; i++)
    {
        int temp;
        cin >> temp;
        errorBtn[temp] = true;
    }

    GetCloseNum();
}