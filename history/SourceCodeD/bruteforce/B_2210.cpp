#include <iostream>
#include <set>
#include <tuple>
using namespace std;

set<tuple<int, int, int, int, int, int>> tempS;
int numBoard[5][5];
int moveX[] = {0,0,-1,1};
int moveY[] = {-1,1,0,0};
int tempV[6];
void getNums(int x, int y, int index)
{
    if(index == 5)
    {
        tempS.insert(make_tuple(tempV[0],tempV[1],tempV[2],tempV[3],tempV[4],tempV[5]));
        return;
    }
    for(int i=0; i<4; ++i)
    {
        int tempX = x + moveX[i];
        int tempY = y + moveY[i];

        if(tempX < 0 || tempX > 4 || tempY < 0 || tempY > 4)
            continue;
        
        tempV[index + 1] = numBoard[tempX][tempY];
        getNums(tempX, tempY, index + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> numBoard[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            tempV[0] = numBoard[i][j];
            getNums(i,j,0);
        }
    }

    cout << tempS.size() << "\n";
    return 0;
}