#include <iostream>
using namespace std;

int main(void)
{
    int tempA, tempB;
    // eof전까지 받아야함.
    while(cin >> tempA >> tempB)
    {
        cout << tempA + tempB << endl;
    }
    return 0;
}