#include <iostream>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    // 하나의 테트로미노를 놓았을때 최대의 값을 구해라.
    int tempA[1][4] = {{1, 1, 1, 1}};
    int tempB[2][2] = {{1,1}, {1,1}};
    int tempC[3][2] = {{1, 0}, {1, 0}, {1, 1}};
    int tempD[3][2] = {{1, 0}, {1, 1}, {0, 1}};
    int tempF[2][3] = {{1, 1, 1}, {0, 1, 0}};

    int ** tempList;
    int tempN, tempM;
    int max = 0;
    cin >> tempN >> tempM;  

    *tempList = new int[tempN];
    for(int i = 0; i < tempN; i++)
    {
        tempList[i] = new int[tempM];
    }

    // set list
    for(int i = 0; i < tempN; i++)
    {
        for(int j = 0; j < tempM; j++)
        {
            cin >> tempList[i][j];
        }
    }

    // check max num
    for(int i = 0; i < tempN; i++)
    {
        for(int j = 0; j < tempM; j++)
        {
            
        }
    }
    
    return 0;
}