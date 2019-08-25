#include <iostream>

using namespace std;


int N;
char map[10][10];
int tempArray[10];

void Go(int index)
{
    if(index == N + 1)
    {
        return 0;
    }

    for(int i = -10; i <= 10; ++i)
    {
        char tempChar;
        if(i < 0)
            tempChar = '-';
        else if( i > 0)
            tempChar = '+';
        else    
            tempChar = '0';
        
        if(map[index][index] == tempChar)
            continue;
        
        tempArray[index] = i;
        for(int i = 0; i < index; ++i)
        {
            int temp = 0;
            for(int j = i; j < index; ++j)
            {
                temp += tempArray[
            }
        }
    }

    for(int i = 0; i < index; ++i)
    {
        for(int j = i; j < index; ++j)
        {
            
        }
    }
}

int main(void)
{   cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int nLen = N * (N + 1) / 2;

    for(int i = 0; i < N; ++i)
    {
        for(int j = i; j < N; ++j)
        {
            cin >> map[i][j];
        }
    }
    Go(0, 0);
    return 0;
}