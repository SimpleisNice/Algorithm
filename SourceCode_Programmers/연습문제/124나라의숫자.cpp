#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> tempV;
    const int divItem = 3;
    int tempNum = n;
    while(tempNum > 0) {
        int tempD = tempNum / divItem;
        int tempM = tempNum % divItem;
        if(tempM == 0) {
            tempD -= 1;
            tempV.push_back(4);
        } else {
            tempV.push_back(tempM);
        }
        tempNum = tempD;
    }
    for(int i=tempV.size() -1; i >=0; --i) {
        char tempNum = '0' + tempV[i];
        answer += tempNum;
    }
    return answer;
}