#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string temp;

    while(getline(cin, temp))
    {
        if(temp.length() > 100)
        {
            temp = temp.substr(0, 100);
        }
        cout << temp << endl;
    }
    return 0;
}