#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int inputNum;
    set<int> tempSet;
    cin >> inputNum;

    for(int i = 0; i < inputNum; ++i)
    {
        int tempNum;
        cin >> tempNum;

        tempSet.insert(tempNum);
    }

    for(auto it = tempSet.begin(); it != tempSet.end(); ++it)
    {
        cout << *it << ' ';
    }
}