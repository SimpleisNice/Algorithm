#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l,c;

    cin>> l >> c;

    vector<char> tempChar(c);
    for(int i=0; i<c; ++i) {
        cin >> tempChar[i];
    }
    sort(tempChar.begin(), tempChar.end());
    
    vector<int> tempV(c);
    for(int i=0; i<l; ++i) {
        tempV[i] = 1;
    }
    do {
        int consonantCnt = 0;
        int vowelCnt = 0;
        
        for(int i=0; i<c; ++i) {
            if(tempV[i] == 1) {
                if(tempChar[i] == 'a' || tempChar[i] == 'e' || tempChar[i] == 'i' || tempChar[i] == 'o' || tempChar[i] == 'u') {
                    vowelCnt++;
                }else {
                    consonantCnt++;
                }
            }
        }
        if(vowelCnt > 0 && consonantCnt > 1) {
            string tempStr = "";
            for(int i=0; i<c; ++i) {
                if(tempV[i] == 1)
                    tempStr += tempChar[i];
            }
            cout << tempStr << "\n";
        }
    }while(prev_permutation(tempV.begin(), tempV.end()));
}