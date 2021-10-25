#include <iostream>

using namespace std;

int tempArray[101];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int tempN, tempM;
    cin >> tempN >> tempM;
    
    for(int i = 1; i <= tempM; ++i)
    {
        int tempJ, tempK, tempInput;
        cin >> tempJ >> tempK >> tempInput;

        for(; tempJ <= tempK; ++tempJ)
        {
            tempArray[tempJ] = tempInput;
        }
    }

    for(int i = 1; i <= tempN; ++i)
    {
        cout << tempArray[i] << " ";
    }
    return 0;
}