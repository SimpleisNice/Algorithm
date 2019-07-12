#include <iostream>
using namespace std;

int main(void)
{
    // input case count
    int tempT;
    int tempN;
    int * tempList;
    do
    {
        cin >> tempT;
    }while(tempT < 1 || tempT > 100);

    while(tempT--)
    {
        // input case info
        do
        {
            cin >> tempN;
        }while(tempN < 1 || tempN > 100);
        tempList = new int[tempN];
        
        while(tempN)
        {
            cin >> tempList[tempN];
            if(tempList[tempN] < 1000000)
                tempN++;
        }
        // get gcd
    }
    return 0;
}