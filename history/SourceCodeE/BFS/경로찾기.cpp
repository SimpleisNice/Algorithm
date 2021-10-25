#include <iostream>
#include <queue>

using namespace std;

bool checkNode[101];
int mapNode[101][101];

int main(void)
{
    int n;
    cin >> n;
    
    queue<pair<int,int>> tempQ;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; ++j)
        {
            int nodeInfo;
            cin >> nodeInfo;

            if(nodeInfo == 1)
                tempQ.push(make_pair(i,j));
        }
    }

    while(!tempQ.empty()) {
        int fNode = tempQ.front().first;
        int sNode = tempQ.front().second;
        tempQ.pop();

        
    }
}