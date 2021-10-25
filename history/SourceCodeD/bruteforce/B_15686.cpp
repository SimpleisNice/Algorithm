#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int chickenDistance[250][13];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> houseInfo;
    vector<pair<int,int>> chickenInfo;

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            int temp;
            cin >> temp;
            if(temp == 0)
                continue;
            if(temp == 1)
                houseInfo.push_back(make_pair(i,j));
            else
                chickenInfo.push_back(make_pair(i,j));
        }
    }

    int houseCount = houseInfo.size();
    int chickenCount = chickenInfo.size();

    for(int i=0; i<houseCount; ++i)
    {
        for(int j=0; j<chickenCount; ++j)
        {
            int tempA = houseInfo[i].first > chickenInfo[j].first ? 
                houseInfo[i].first - chickenInfo[j].first  : chickenInfo[j].first - houseInfo[i].first;
            int tempB = houseInfo[i].second > chickenInfo[j].second ? 
                houseInfo[i].second - chickenInfo[j].second  : chickenInfo[j].second - houseInfo[i].second;                
            chickenDistance[i][j] = tempA + tempB;
        }
    }

    vector<int> setDistance(chickenCount);
    int index = 1;
    int smallDistance = INT_MAX;
    while(index <= m)
    {
        for(int i=0; i<index; ++i)
        {
            setDistance[i] = 1;
        }
        for(int i=index; i<chickenCount; ++i)
        {
            setDistance[i] = 0;
        }

        do
        {
            int tempDistance = 0;
            for(int i=0; i<houseCount; ++i)
            {
                int tempNum = INT_MAX;
                for(int j=0; j<chickenCount; ++j)
                {
                    if(setDistance[j] == 1)
                    {
                        if(tempNum > chickenDistance[i][j])
                            tempNum = chickenDistance[i][j];
                    }
                }
                tempDistance += tempNum;
            }
            if(smallDistance > tempDistance)
                smallDistance = tempDistance;
        }while(prev_permutation(setDistance.begin(), setDistance.end()));
        ++index;
    }

    cout << smallDistance << "\n";
    return 0;
}