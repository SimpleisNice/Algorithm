#include <iostream>

using namespace std;

int getNum(int num, int * saveNum)
{
    int pos = 0;
    while(true)
    {
        saveNum[pos] = num%10;
        num /= 10;
        if(num == 0)
            break;
        ++pos;
    }
    return pos + 1;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int saveNum[7];
    cin >> n;

    int nLength = getNum(n, saveNum);
    int minNum = nLength > 2 ? n - nLength * 9 : 0;
    int checkResult = 0;
    for(int i=n; i >= minNum; --i)
    {
        int numLength = getNum(i, saveNum);
        int sum = i;
        for(int j=0; j<numLength; ++j) 
        {
            sum += saveNum[j];
        }
        if(n == sum) checkResult = i;
    }    
    cout << checkResult << '\n';
    return 0;
}