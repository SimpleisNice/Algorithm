#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int tempN, int tempS;

    cin >> tempN >> tempS;

    vector<int> tempVector(tempN);

    for(int i = 0; i < tempN; ++i)
    {
        cin >> tempVector[i];
    }

    
    return 0;
}