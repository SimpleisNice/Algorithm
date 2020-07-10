#include <string>
#include <vector>

using namespace std;
int moveInfo[101][101];
bool boardInfo[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0; i<puddles.size(); ++i) {
        boardInfo[puddles[i][1]][puddles[i][0]] = true;
    }
    
    for(int i=1; i<=m; ++i) {
        if(boardInfo[1][i])
            break;
        moveInfo[1][i] = 1;
    }
    for(int i=1; i<=n; ++i) {
        if(boardInfo[i][1])
            break;
        moveInfo[i][1] = 1;
    }
    
    for(int i=2; i<=n; ++i) {
        for(int j=i; j<=m; ++j) {
            if(boardInfo[i][j])
                continue;
            moveInfo[i][j] = (moveInfo[i-1][j] + moveInfo[i][j-1]) % 1000000007;
        }
        for(int j=i; j<=n; ++j) {
            if(boardInfo[j][i])
                continue;
            moveInfo[j][i] = (moveInfo[j-1][i] + moveInfo[j][i-1]) % 1000000007;
        }
    }
    
    return moveInfo[n][m];
}