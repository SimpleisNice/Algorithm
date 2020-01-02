#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int teamMap[100][100];
int n;

vector<int> setTeam;

bool makeTeam(int count)
{
    if (count == n / 2 + 1)
        return false;

    for (int i = 0; i < count; ++i)
    {
        setTeam[i] = 1;
    }
    for (int i = count; i < n; ++i)
    {
        setTeam[i] = 0;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> teamMap[i][j];
        }
    }

    setTeam.resize(n);

    int memberA = 1;
    int minCount = INT_MAX;
    while (true)
    {
        if (!makeTeam(memberA))
            break;
        do
        {
            vector<int> teamA;
            vector<int> teamB;

            int teamTotalScore = 0;
            int teamAScore = 0;
            int teamBScore = 0;
            for (int i = 0; i < n; ++i)
            {
                if (setTeam[i] == 1)
                    teamA.push_back(i);
                else
                    teamB.push_back(i);
            }

            if (teamA.size() != 1)
            {
                for (int i = 0, teamLen = teamA.size(); i < teamLen; ++i)
                {
                    int x = teamA[i];
                    for (int j = i + 1; j < teamLen; ++j)
                    {
                        int y = teamA[j];
                        teamAScore += teamMap[x][y] + teamMap[y][x];
                    }
                }
            }
            for (int i = 0, teamLen = teamB.size(); i < teamLen; ++i)
            {
                int x = teamB[i];
                for (int j = i + 1; j < teamLen; ++j)
                {
                    int y = teamB[j];
                    teamBScore += teamMap[x][y] + teamMap[y][x];
                }
            }
            teamTotalScore = teamAScore > teamBScore ? teamAScore - teamBScore : teamBScore - teamAScore;

            minCount = min(minCount, teamTotalScore);
        } while (prev_permutation(setTeam.begin(), setTeam.end()));

        ++memberA;
    }

    cout << minCount << '\n';
    return 0;
}