#include <iostream>
#include <queue>

using namespace std;

struct MoveInfo
{
    int x;
    int y;
    int moveCount;
    int blockCount;
};

char boardMap[1000][1000];
bool boardCheck[1000][1000][11];

int moveX[] = {0, 0, -1, 1};
int moveY[] = {-1, 1, 0, 0};
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, b;
    cin >> n >> m >> b;

    for (int i = 0; i < n; ++i)
    {
        cin >> boardMap[i];
    }

    queue<MoveInfo> tempQ;
    tempQ.push({0, 0, 1, 0});
    boardCheck[0][0][0] = true;
    int minMove = -1;
    
    while (!tempQ.empty())
    {
        MoveInfo tempM = tempQ.front();
        tempQ.pop();
        if(tempM.x == n - 1 && tempM.y == m - 1)
        {
            minMove = tempM.moveCount;
            break;
        }
        for (int i = 0; i < 4; ++i)
        {
            int tempX = tempM.x + moveX[i];
            int tempY = tempM.y + moveY[i];

            if (tempX < 0 || tempX >= n || tempY < 0 || tempY >= m)
                continue;
            if (boardMap[tempX][tempY] == '1')
            {
                if (tempM.blockCount + 1 <= b && !boardCheck[tempX][tempY][tempM.blockCount + 1])
                {
                    tempQ.push({tempX, tempY, tempM.moveCount + 1, tempM.blockCount + 1});
                    boardCheck[tempX][tempY][tempM.blockCount + 1] = true;
                }
            }
            else if (!boardCheck[tempX][tempY][tempM.blockCount])
            {
                tempQ.push({tempX, tempY, tempM.moveCount + 1, tempM.blockCount});
                boardCheck[tempX][tempY][tempM.blockCount] = true;
            }
        }
    }
    cout << minMove << '\n';
    return 0;
}