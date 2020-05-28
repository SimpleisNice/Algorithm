#include <iostream>
#include <queue>
using namespace std;

int gardenMap[1000][1000];
int gardenInfo[1000][1000];
int moveX[] = {0,0,-1,1};
int moveY[] = {-1,1,0,0};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m,n;
    cin >> m >> n;

    queue<pair<int, int>> tomatoInfo;
    for(int i=0; i<n; ++i)  {
        for(int j=0; j<m; ++j) {
            cin >> gardenMap[i][j];
            if(gardenMap[i][j] == 1)
                tomatoInfo.push(make_pair(i,j));
        }
    }

    while(!tomatoInfo.empty()) {
        int x = tomatoInfo.front().first;
        int y = tomatoInfo.front().second;
        int day = gardenInfo[x][y];
        tomatoInfo.pop();

        for(int i=0; i<4; ++i) {
            int tempX = x + moveX[i];
            int tempY = y + moveY[i];

            if(tempX < 0 || tempX > n - 1 || tempY < 0 || tempY > m - 1)
                continue;
            if(gardenMap[tempX][tempY] != -1) {
                if(gardenMap[tempX][tempY] == 0){
                    gardenMap[tempX][tempY] = 1;
                    gardenInfo[tempX][tempY] = day + 1;
                    tomatoInfo.push({tempX, tempY});
                } else if(day + 1 < gardenInfo[tempX][tempY]) {
                    gardenInfo[tempX][tempY] = day + 1;
                    tomatoInfo.push({tempX, tempY});
                }
            }
        }
    }
    int token = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            
            if(gardenMap[i][j] == 0) {
                token = -1;
                break;
            }
            else
                token = token > gardenInfo[i][j] ? token : gardenInfo[i][j];
        }
        if(token == -1)
            break;
    }
    cout << token << "\n";
}