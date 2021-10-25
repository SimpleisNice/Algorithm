#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
    string temp;
    getline(cin ,temp);

    istringstream inputStream(temp);
    int tempCount = 0;
    while(getline(inputStream, temp, ','))
    {
        ++tempCount;
    }
    cout << tempCount;
    return 0;
}