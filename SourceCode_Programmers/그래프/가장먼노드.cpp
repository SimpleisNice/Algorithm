#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> tempV[20001];
int cntMap[20001];
bool checkMap[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxMove = 0;
    for(int i=0; i<edge.size(); ++i) {
        tempV[edge[i][1]].push_back(edge[i][0]);
        tempV[edge[i][0]].push_back(edge[i][1]);
    }
    
    queue<int> tempQ;
    tempQ.push(1);
    checkMap[1] = true;
    
    while(!tempQ.empty()) {
        int pos = tempQ.front();
        tempQ.pop();
        
        for(int i=0; i<tempV[pos].size(); ++i) {
            int tempPos = tempV[pos][i];
            if(checkMap[tempPos])
                continue;
            
            tempQ.push(tempPos);
            checkMap[tempPos] = true;
            cntMap[tempPos] = cntMap[pos] + 1;       
            
            if(maxMove < cntMap[tempPos]) {
                maxMove = cntMap[tempPos];
                answer = 1;
            }
            else  if(maxMove == cntMap[tempPos]){
                answer++;
            }
        }
    }
        
    return answer;
}