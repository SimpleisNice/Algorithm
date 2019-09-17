#include <iostream>
#include <string>

using namespace std;

int tempArray[4];

int main(void)
{
    string tempStr;

    while(getline(cin, tempStr))
    {
        for(int i = 0; i < tempStr.length(); ++i)
        {
            if(tempStr[i] >= 'a' && tempStr[i] <= 'z')  ++tempArray[0];
            else if(tempStr[i] >= 'A' && tempStr[i] <= 'Z') ++tempArray[1];
            else if(tempStr[i] >= '0' && tempStr[i] <= '9') ++tempArray[2];
            else if(tempStr[i] == ' ')   ++tempArray[3];
        }
        
        for(int i = 0; i < 4; ++i)
        {
            cout << tempArray[i] << " ";
            tempArray[i] = 0;
        }
        cout << "\n";
    }

    return 0;
}