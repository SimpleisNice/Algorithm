#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int input;
    cin >> input;

    while(input--) {
        string tempStr;
        cin >> tempStr;

        int tokenItem = -1;
        if(tempStr[0] == '(') {     
            tokenItem = 1;
            for(int i=1; i<tempStr.length(); ++i) {
                if(tempStr[i] == '(') 
                    tokenItem++;
                else
                    tokenItem--;

                if(tokenItem < 0)
                    break;
            }
        }

        if(tokenItem != 0)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
    }
    return 0;
}