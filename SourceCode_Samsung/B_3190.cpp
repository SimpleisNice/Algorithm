#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

bool gameMap[101][101];

pair<int, int> moveDir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, l;
    cin >> n >> k;

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        gameMap[x][y] = true;
    }

    cin >> l;
    deque<pair<int, char>> infoDirection(l);
    for (int i = 0; i < l; ++i)
    {
        int num;
        char order;
        cin >> num >> order;

        infoDirection[i] = make_pair(num, order);
    }

    deque<pair<int, int>> infoMove;
    infoMove.push_back(make_pair(1, 1));
    int snakeLen = 1;
    int timeCount = 1;
    int idx = 0;

    while (true)
    {
        int posX = infoMove.back().first + moveDir[idx].first;
        int posY = infoMove.back().second + moveDir[idx].second;

        if (posX <= 0 || posX > n || posY <= 0 || posY > n)
        {
            break;
        }

        int len = infoMove.size();
        bool checkCrash = false;
        for (int i = len - 1; i >= len - snakeLen; --i)
        {
            if (posX == infoMove[i].first && posY == infoMove[i].second)
            {
                checkCrash = true;
                break;
            }
        }
        if (checkCrash)
            break;
        if (gameMap[posX][posY])
        {
            ++snakeLen;
            gameMap[posX][posY] = false;
        }
        if (!infoDirection.empty())
        {
            if (timeCount == infoDirection.front().first)
            {
                if (infoDirection.front().second == 'L')
                    idx = (idx + 3) % 4;
                else
                    idx = (idx + 1) % 4;
                infoDirection.pop_front();
            }
        }

        infoMove.push_back(make_pair(posX, posY));
        ++timeCount;
    }
    cout << timeCount << "\n";
    return 0;
}