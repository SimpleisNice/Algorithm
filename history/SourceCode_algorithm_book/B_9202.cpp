// Boggle
// Brute force

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int moveX[] = {0, 0, -1, 1, -1, 1, -1, 1};
int moveY[] = {-1, 1, 0, 0, -1, 1, 1, -1};
char stringBoard[30][4][4];
bool checkBoard[30][4][4];

vector<string> stringList;

int stringPoint;
string longString;
int stringCount;
bool findCheck;

void searchChar(int boardIndex, string tempString, int pos, int x, int y)
{
    if (pos == tempString.length())
    {    
        findCheck = true;
        return;
    }
    for(int i=0; i<8; ++i) 
    {
        int tempX = x + moveX[i];
        int tempY = y + moveY[i];

        if(tempX < 0 || tempX > 3  || tempY < 0 || tempY > 3)
            continue;
        if(checkBoard[boardIndex][tempX][tempY])
            continue;
        if(stringBoard[boardIndex][tempX][tempY] == tempString[pos])
        {    
            checkBoard[boardIndex][tempX][tempY] = true; 
            searchChar(boardIndex, tempString, pos + 1, tempX, tempY);
            checkBoard[boardIndex][tempX][tempY] = false; 
        }
    }
}

int checkPoint(int stringLength)
{
    if (stringLength == 1 || stringLength == 2)
        return 0;
    if (stringLength == 3 || stringLength == 4)
        return 1;
    if (stringLength == 5)
        return 2;
    if (stringLength == 6)
        return 3;
    if (stringLength == 7)
        return 5;
    if (stringLength == 8)
        return 11;
}
void findString(int boardIndex, int stringIndex)
{
    findCheck = false;
    string tempString = stringList[stringIndex];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (tempString[0] == stringBoard[boardIndex][i][j])
            {   
                checkBoard[boardIndex][i][j] = true; 
                searchChar(boardIndex, tempString, 1, i, j);
                checkBoard[boardIndex][i][j] = false;
            }
        }
    }
    if (findCheck)
    {
        stringPoint += checkPoint(tempString.length());
        ++stringCount;

        if (tempString.length() > longString.length())
        {
            longString = tempString;
        }
        else if (tempString.length() == longString.length())
        {
            if (tempString < longString)
                longString = tempString;
        }
    }
}

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // string
    int w;
    cin >> w;
    for (int i = 0; i < w; ++i)
    {
        string tempString;
        cin >> tempString;

        stringList.push_back(tempString);
    }

    // board
    int b;
    cin >> b;

    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            string tempString;
            cin >> tempString;

            for (int k = 0; k < 4; ++k)
            {
                stringBoard[i][j][k] = tempString[k];
            }
        }
    }

    for (int i = 0; i < b; ++i)
    {
        stringPoint = 0;
        longString = "";
        stringCount = 0;

        for (int j = 0; j < w; ++j)
            findString(i, j);

        cout << stringPoint << " " << longString << " " << stringCount << '\n';
    }

    return 0;
}