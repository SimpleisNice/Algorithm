// h * w
// 검, 흰칸으로 구성된 격자 모양을 하고 있음
// 이 중 모든 흰칸을 3칸짜리 L자 모양의 블록으로 덮고 싶음.
// 자유롭게 회전해서 놓을 수 있음.
// 서로 겹치거나 검은 칸을 덮거나 게임판 밖으로 나가서는 안됨

// c, w, h
// # : 검은, . : 흰칸

#include <iostream>
#include <string>
using namespace std;

// 격자 모양
int gameShape[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}};

int h, w;
int totalCount;
bool checkMap[20][20];

void findCombination()
{
    int tempX = -1, tempY = -1;
    
    for (int i = 0; i < h; ++i)
    {
        bool isWhite = false;
        for (int j = 0; j < w; ++j)
        {
            if (!checkMap[i][j])
            {
                tempX = i;
                tempY = j;
                isWhite = true;
                break;
            }
        }

        if(isWhite) break;
    }

    if (tempX == -1)
    {
        ++totalCount;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        bool isPossible = true;
        for (int j = 0; j < 3; ++j)
        {
            if (gameShape[i][j][0] + tempX < 0 || gameShape[i][j][0] + tempX >= h || gameShape[i][j][1] + tempY < 0 || gameShape[i][j][1] + tempY >= w)
            {
                isPossible = false;
                break;
            }
            if(checkMap[gameShape[i][j][0] + tempX][gameShape[i][j][1] + tempY])
            {
                isPossible = false;
                break;
            }
        }
        if (isPossible)
        {
            for (int j = 0; j < 3; ++j)
                checkMap[gameShape[i][j][0] + tempX][gameShape[i][j][1] + tempY] = true;

            findCombination();

            for (int j = 0; j < 3; ++j)
                checkMap[gameShape[i][j][0] + tempX][gameShape[i][j][1] + tempY] = false;
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;



    while (c--)
    {
        cin >> h >> w;
        totalCount = 0;
        for (int i = 0; i < h; ++i)
        {
            string tempStr;
            cin >> tempStr;
            // map init
            for (int j = 0, len = tempStr.length(); j < len; ++j)
            {
                if (tempStr[j] == '#')
                    checkMap[i][j] = true;
                else
                    checkMap[i][j] = false;
            }
        }

        findCombination();

        cout << totalCount << '\n';
    }
}