#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> dwarf(9);
    for(int i=0; i<9; ++i) {
        cin >> dwarf[i];
    }
    sort(dwarf.begin(), dwarf.end());

    vector<int> findD(9);
    for(int i=0; i<7; ++i) {
        findD[i] = 1;
    }

    do {
        int tempSum = 0;
        for(int i=0; i<9; ++i) {
            if(findD[i] == 1) {
                tempSum += dwarf[i];
            }
        }
        if(tempSum == 100)
            break;
    }while(prev_permutation(findD.begin(), findD.end()));

    for(int i=0; i<9; ++i) {
        if(findD[i] == 1) {
            cout << dwarf[i] << "\n";
        }
    }
    return 0;
}