#include <iostream>
#include <string>

int alphabet[26];
using namespace std;

int main(void)
{
    string tempInput;
    cin >> tempInput;
    
    for(int i = 0; i < tempInput.length(); ++i)
    {
        ++alphabet[tempInput[i] - 'a'];
    }

    for(int i = 0; i < 26; ++i)
    {
        cout << alphabet[i] << " ";
    }
}