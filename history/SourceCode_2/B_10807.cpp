#include <iostream>
#include <map>

using namespace std;

int main(void)
{
    int n,v;    
    map<int, int> tempM;

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int tempNum;
        cin >> tempNum;

        auto itf = tempM.find(tempNum);

        if(itf != tempM.end())
        {
            tempM[tempNum] = itf->second + 1;
        }
        else
            tempM.insert(make_pair(tempNum, 1));
    }
    cin >> v;
    cout << tempM[v] << '\n';
    return 0;
}