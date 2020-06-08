#include <iostream>
#include <queue>

using namespace std;

bool islandMap[50][50];
bool checkMap[50][50];
int moveX[] = {0, 0, -1, 1, -1, -1, 1, 1};
int moveY[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w, tempNum, islandCnt;
    while (true)
    {
        islandCnt = 0;
        cin >> w >> h;

        if (h == 0 && w == 0)
            break;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> tempNum;
                if (tempNum == 1)
                    islandMap[i][j] = true;
                else
                    islandMap[i][j] = false;
            }
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (!islandMap[i][j] || checkMap[i][j])
                    continue;

                queue<pair<int, int>> tempQ;
                tempQ.push({i, j});
                checkMap[i][j] = true;

                while (!tempQ.empty())
                {
                    int x = tempQ.front().first;
                    int y = tempQ.front().second;
                    tempQ.pop();

                    for (int k = 0; k < 8; ++k)
                    {
                        int tempX = x + moveX[k];
                        int tempY = y + moveY[k];

                        if (tempX < 0 || tempX > h - 1 || tempY < 0 || tempY > w - 1)
                            continue;

                        if (!islandMap[tempX][tempY] || checkMap[tempX][tempY])
                            continue;
                        checkMap[tempX][tempY] = true;
                        tempQ.push({tempX, tempY});
                    }
                }
                islandCnt++;
            }
        }
        fill(&checkMap[0][0], &checkMap[0][0] + sizeof(checkMap), false);
        cout << islandCnt << "\n";
    }
}