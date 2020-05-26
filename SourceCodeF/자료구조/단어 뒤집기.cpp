#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string input; 
    getline(cin, input);
    int tempInput = stoi(input);

    for(int i=0; i < tempInput; ++i) {
        string tempStr, tempStr2;
        getline(cin ,tempStr);

        stringstream ss(tempStr);
        string resultStr = "";

        while(getline(ss, tempStr2, ' ')) {
            reverse(tempStr2.begin(), tempStr2.end());
            resultStr += tempStr2 + " ";
        }

        cout << resultStr.substr(0, resultStr.length() - 1) << "\n";
    }
}