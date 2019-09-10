#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n,k;
    cin >> n >> k;
    vector<int> tempQ(n);

    for(int i = 0; i < n; ++i)
    {
        tempQ[i] = i + 1;
    }

    for(auto it = tempQ.begin(); it != tempQ.end(); ++it)
    {
        cout << *it << endl;
    }
    
    int popIndex = 0;
    while(!tempQ.empty())
    {
        if(popIndex + k )
    }
    return 0;
}