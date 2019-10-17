#include <iostream>
#include <queue>

using namespace std;

char tempMap[21][21];
int moveMap[21][21][2];

int movX[] = {0,0,-1,1};
int movY[] = {-1,1,0,0};

int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int h,w;
        int furniture = 0;
        int clean = 0;
        int space = 0;
        int totalMove = 0;
        queue<pair<int, int>> tempQ;

        cin >> h >> w;
        totalMove = h * w;

        for(int i=0; i<h; ++i)
        {
            for(int j=0; j<w; ++j)
            {
                cin >> tempMap[i][j];

                if(tempMap[i][j] == 'o')    
                    tempQ.push(make_pair(i,j));
                else if(tempMap[i][j] == 'x')
                    ++furniture;
                else if(tempMap[i][j] == '*')
                    ++clean;
            }
        }

        moveMap[tempQ.front().first][tempQ.front().second][0] = 1;
        space = 1;

        while(!tempQ.empty())
        {
            int tempX = tempQ.front().first;
            int tempY = tempQ.front().second;

            tempQ.pop();
            
            for(int i=0; i<4; ++i)
            {
                int posX = tempX + movX[i];
                int posY = tempY + movY[i];

                if(posX < 0 || posX >= h || posX < 0 || posY >= w)
                    continue;
                if(tempMap[posX][posY] == '.' || tempMap[posX][posY] == 'o')
                {
                    if(moveMap[posX][posY][0] == 0)
                        ++space;

                    moveMap[posX][posY][1] += moveMap[tempX][tempY][1];
                    moveMap[posX][posY][0] += moveMap[tempX][tempY][0] + 1;
                    tempQ.push(make_pair(posX, posY));
                }    
                else if(tempMap[posX][posY] == '*')
                {
                    if(moveMap[posX][posY][1] == 0)
                        moveMap[posX][posY][1] += moveMap[tempX][tempY][1] + 1;
                    else
                        moveMap[posX][posY][1] += moveMap[tempX][tempY][1];
                    tempQ.push(make_pair(posX, posY))
                }
            }
            if(moveMap[posX][posY][1] == clean)
            {
                cout << moveMap[posX][posY] - 1 << '\n';
                break;
            }
            if(totalSum == (space + furniture) || moveMap[posX][posY][0] >= totalSum)
            {
                cout << -1 << '\n';
                break;
            }
        }
    }
    return 0;
}