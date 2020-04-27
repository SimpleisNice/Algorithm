#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> goRoom;

long long findPos(long long num) {
    if(!goRoom[num]) return num;
    else return goRoom[num] = findPos(goRoom[num]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    int roomCnt = room_number.size();
    vector<long long> answer(roomCnt);
    
    for(int i=0; i<roomCnt; ++i) {
        if(!goRoom[room_number[i]]) {
            goRoom[room_number[i]] = findPos(room_number[i] + 1);
            answer[i] = room_number[i];
        } else {
            long long tempNum = findPos(goRoom[room_number[i]]);
            answer[i] = tempNum;
            goRoom[tempNum] = findPos(tempNum + 1);
        }
    }
    return answer;
}