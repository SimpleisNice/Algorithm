#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int count = 1;
    int len = numbers.size();
    vector<int> setPos(len, 0);

    while(count != len) {
        for(int i=0; i<count; ++i) {
            setPos[i] = 1;
        }
        for(int i=count; i<len; ++i) {
            setPos[i] = 0;
        }
        
        do {
            int sum = 0;
            for(int i=0; i<len; ++i) {
                int index = setPos[i] == 1 ? 1 : -1;
                
                sum += (index * numbers[i]);
            }
            if(sum == target) {
                ++answer;
            }
        }while(prev_permutation(setPos.begin(), setPos.end()));
        ++count;
    }
    return answer;
}