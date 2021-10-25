#include <iostream>
#include <algorithm>

using namespace std;

int sampleCase[500];
int checkCase[500];

void getLIS(int index, int move, const int n)
{
    if(index == n)
        return;
    if(move < checkCase[index])
        return;
    if(move == 1)
        getLIS(index + 1, move, n);
    
    for(int i = index + 1; i < n; ++i)
    {
        if(sampleCase[index] < sampleCase[i] && checkCase[i] < move + 1)
        {
            checkCase[i] = move + 1;
            getLIS(i, move + 1, n);
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
    int c;
    cin >> c;
    while(c--)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; ++i)
        {
            cin >> sampleCase[i];
            checkCase[i] = 1;
        }
        getLIS(0, 1, n);
        int maxLIS = 0;
        for(int i=0; i<n; ++i)
        {
            if(maxLIS < checkCase[i])
                maxLIS = checkCase[i];
        }
        cout << maxLIS << '\n';
    }
    return 0;
}