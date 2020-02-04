#include <iostream>
#include <cstring>
using namespace std;

int board[100][100];
bool checkBoard[100][100];
int n;
bool endCheck = false;

void jump(int x, int y) 
{
    if((x == n-1 && y == n -1) || endCheck)
    {
        endCheck = true;
        return;
    }
    
    int jumpValue = board[x][y];

    if(x + jumpValue < n && !checkBoard[x + jumpValue][y])
    {   
        checkBoard[x + jumpValue][y] = true;
        jump(x + jumpValue, y);
    }
    if(y + jumpValue < n && !checkBoard[x][y + jumpValue])
    {   
        checkBoard[x][y + jumpValue] = true; 
        jump(x, y + jumpValue);
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;
    while(c--)
    {
        cin >> n;
        endCheck = false;

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                cin >> board[i][j];
            }
        }
        jump(0,0);
        if(endCheck)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        memset(checkBoard, false, sizeof(checkBoard));
    }
    return 0;
}