#include <iostream>
#include <vector>

using namespace std;

int teamMap[20][20];
int main(void)
{
    cin.tie(0);
    int n; 
    cin >> n;

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cin >> teamMap[i][j];
        }
    }
    int ans = -1;
    for(int i=0; i<(1<<n); ++i)
    {
        vector<int> teamA, teamB;

        for(int j=0; j<n; ++j)
        {
            if(i & (1<<j))  teamA.push_back(j);
            else teamB.push_back(j);
        }

        if(teamA.size() != n/2) continue;

        int sumA = 0;
        int sumB = 0;
        for(int t1=0; t1< n/2; ++t1)
        {
            for(int t2=0; t2<n/2; ++t2)
            {
                if(t1 == t2)    continue;
                sumA += teamMap[teamA[t1]][teamA[t2]];
                sumB += teamMap[teamB[t1]][teamB[t2]];
            }
        }
        int diff = sumA - sumB;
        
        if(diff < 0) diff = -diff;
        if(ans == -1 || ans > diff) ans = diff;
    }
    cout << ans << '\n';
    return 0;
}