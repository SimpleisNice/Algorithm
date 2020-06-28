#include <vector>

using namespace std;
int info[100001][4];
int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();
    for(int i=1; i<=len; ++i) {
        for(int j=0; j<4; ++j) {
            for(int k=0; k<4; ++k) {
                if(j == k)
                    continue;
                if(info[i][j] < info[i-1][k] + land[i-1][j])
                    info[i][j] = info[i-1][k] + land[i-1][j];
            }
        }
    }
    for(int i=0; i<4; ++i) {
        if(answer < info[len][i])
            answer = info[len][i];
    }

    return answer;
}