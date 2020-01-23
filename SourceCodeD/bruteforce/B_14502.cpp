#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int defaultMap[8][8];
int tempMap[8][8];
int moveX[] = {0, 0, -1, 1};
int moveY[] = {-1, 1, 0, 0};
queue<pair<int, int>> virusPos;
int n, m;
int safeSpace = 0;
void setPillar(int x, int y, int pillarCount)
{

    if (pillarCount == 3)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                tempMap[i][j] = defaultMap[i][j];
            }
        }
        queue<pair<int, int>> tempQ = virusPos;

        while (!tempQ.empty())
        {
            int x = tempQ.front().first;
            int y = tempQ.front().second;
            tempQ.pop();

            for (int i = 0; i < 4; ++i)
            {
                if (x + moveX[i] < 0 || x + moveX[i] >= n || y + moveY[i] < 0 || y + moveY[i] >= m)
                    continue;
                if (tempMap[x + moveX[i]][y + moveY[i]] == 0)
                {
                    tempMap[x + moveX[i]][y + moveY[i]] = 2;
                    tempQ.push(make_pair(x + moveX[i], y + moveY[i]));
                }
            }
        }
        int tempSafe = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (tempMap[i][j] == 0)
                    ++tempSafe;
            }
        }
        safeSpace = max(safeSpace, tempSafe);
        return;
    }
    for (int i = x; i < n; ++i)
    {
        if (y != 0 && i == x + 1)
            y = 0;
        for (int j = y; j < m; ++j)
        {
            if (defaultMap[i][j] == 0)
            {
                defaultMap[i][j] = 1;
                setPillar(i, j, pillarCount + 1);
                defaultMap[i][j] = 0;
            }
        }
    }
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> defaultMap[i][j];

            if (defaultMap[i][j] == 2)
                virusPos.push(make_pair(i, j));
        }
    }
    setPillar(0, 0, 0);
    cout << safeSpace << '\n';
    return 0;
}