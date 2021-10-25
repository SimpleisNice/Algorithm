#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void)
{
    string tempStr;
    cin >> tempStr;


    istringstream iStream(tempStr);
    
    int sum = 0;
    while(getline(iStream, tempStr, ','))
    {
        sum += stoi(tempStr);
    }

    cout << sum;
    return 0;
}