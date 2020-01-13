#include <iostream>
#include <cstring>
using namespace std;

bool student[10];
bool checkStudent[45][45];

int pairOfCount;
int studentNum;
int pairOfNum;

void findCombination()
{
    int findNum = -1;
    for (int i = 0; i < studentNum; ++i)
        if (!student[i])
        {
            findNum = i;
            break;
        }
    if (findNum == -1)
    {
        ++pairOfCount;
        return;
    }

    for (int i = findNum + 1; i < studentNum; ++i)
    {
        if (checkStudent[findNum][i])
        {
            if (!student[findNum] && !student[i])
            {
                student[i] = student[findNum] = true;
                findCombination();
                student[i] = student[findNum] = false;
            }
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
        cin >> studentNum >> pairOfNum;
        pairOfCount = 0;

        for (int i = 0; i < pairOfNum; ++i)
        {
            int tempA, tempB;
            cin >> tempA >> tempB;

            checkStudent[tempA][tempB] = checkStudent[tempB][tempA] = true;
        }

        findCombination();
        cout << pairOfCount << '\n';
        memset(checkStudent, false, sizeof(checkStudent));
    }
    return 0;
}