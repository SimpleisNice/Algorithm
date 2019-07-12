#include <iostream>
using namespace std;

int main(void)
{
    int temp;
    int * tempList;
    cin >> temp;

    tempList = new int[temp];

    for(int i = 0; i < temp; i++)
    {
        int tempA, tempB;

        cin >> tempA >> tempB;

        cout << tempA + tempB << endl;
    }
    return 0;
}