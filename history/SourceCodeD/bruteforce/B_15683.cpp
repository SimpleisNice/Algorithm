#include <iostream>
#include <vector>

using namespace std;

int cctvMap[8][8];
vector<pair<int,int>> cctvInfo;
vector<int> cctvCount;
v
int main(void)
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> cctvMap[i][j];
            if(cctvMap[i][j] == 0 || cctvMap[i][j] == 6)
                continue;
            ccvtInfo.push_back(make_pair(i,j));
            cctvCount.push_back(0);
        }
    }
    
}