#include <iostream>

using namespace std;

int card[100];
int n,m;
int maxCase = 0;
void selectCard(int pos, int sum, int count) {
    if(sum > m)
        return;
    if(count == 3)
    {    
        if(maxCase < sum)
            maxCase = sum;
        return;
    }

    for(int i = pos; i < n; ++i)
    {
        selectCard(i + 1, sum + card[i], count + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i=0; i<n; ++i)
    {
        cin >> card[i];
    }

    selectCard(0, 0, 0);

    cout << maxCase << '\n';
    return 0;
}