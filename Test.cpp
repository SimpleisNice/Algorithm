#include <algorithm>
#include<iostream>


using namespace std;

int main(void)
{
    int tempA, tempB, tempC;

    cin >> tempA >> tempB >> tempC;


    cout << max(max(tempA, tempB), tempC) << endl;
}