#include <iostream>
#include <queue>

using namespace std;

char localMap[100][100];
int countMap[100][100];
int moveX[] = {0,0,-1,1};
int moveY[] = {-1,1,0,0};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; ++i) {
        cin >> localMap[i];
    }

    queue<pair<int,int>> tempQ;
    tempQ.push({0,0});
    countMap[0][0] = 1;

    while(!tempQ.empty()) {
        int x = tempQ.front().first;
        int y = tempQ.front().second;
        tempQ.pop();

        for(int i=0; i<4; ++i) {
            int tempX = x + moveX[i];
            int tempY = y + moveY[i];

            if(tempX < 0 || tempX > n - 1 || tempY < 0 || tempY > m -1)
                continue;
            if(localMap[tempX][tempY] == '0')
                continue;
            
            if(countMap[tempX][tempY] == 0 || countMap[tempX][tempY] > countMap[x][y] + 1) {
                tempQ.push({tempX, tempY});
                countMap[tempX][tempY] = countMap[x][y] + 1;
            }
        }
    }

    cout << countMap[n -1][m -1] << "\n";
    return 0;
}