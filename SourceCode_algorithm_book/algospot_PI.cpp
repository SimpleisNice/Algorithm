#include <iostream>
#include <algorithm>

using namespace std;

int numCase[10000][10000];
string num;
int numLen;
int getSmall(int index) {
    int count = 0;

    if(numLen - index < 2)
        return 0;
    // 모든 숫자가 같은 경우
    int tempNum = num[index];
    int tempIndex = 1;
    while(true) {
        if(tempIndex + index > numLen || tempNum != num[index + tempIndex])
            break;
        if(tempIndex > 1 && tempIndex < 5) {
            getSmall(index + tempIndex + 1)
        }
    }

    
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;

    while(c--) {
        cin >> num;
        numLen = num.length() - 1;
        
        int num = getSmall(0);
        cout << num << "\n";
    }
}