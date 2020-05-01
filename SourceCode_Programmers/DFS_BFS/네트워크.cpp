#include <string>
#include <vector>

using namespace std;

bool checkComputer[200];

void go(int index, const int n, const vector<vector<int>>::iterator it) {
    for(int i=0; i<n; ++i) {
        if(checkComputer[i])
            continue;
        if(*((it + index)->begin() + i) == 1)
        {
            checkComputer[i] = true;
            go(i, n, it);
        }     
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; ++i) {
        if(checkComputer[i])
            continue;
        
        checkComputer[i] = true;
        go(i, n, computers.begin());
        ++answer;
    }
    return answer;
}