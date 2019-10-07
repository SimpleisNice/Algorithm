#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string tempStr;
    getline(cin, tempStr);
    istringstream iStream(tempStr);

    while(getline(iStream, tempStr, ','))
    {
        cout << tempStr << endl;
    }
}