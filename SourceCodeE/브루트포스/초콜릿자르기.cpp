#include <iostream>

using namespace std;

int cutInfo[301][301];

int cutChocolate(int n, int m) {
    int cut = 0;
    
    if(n == 1 || m == 1 || cutInfo[n][m] != 0) 
        cut += cutInfo[n][m];
    else if(m % 2  == 0){
        cut += cutInfo[n][m] = 2 * cutChocolate(n, m/2) + 1;
    } else {
        cut += cutInfo[n][m] = cutChocolate(n, m/2) + cutChocolate(n, m/2 + 1) + 1;
    }
    return cut;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    int maxLen = n > m ? n : m;
    for(int i=2; i<= maxLen; ++i) {
        cutInfo[i][1] = cutInfo[1][i] = i -1;  
    }

    int cutCnt = cutChocolate(n,m);
    cout << cutCnt << "\n";
    return 0;
}