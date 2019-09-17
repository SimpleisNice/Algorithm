#include <iostream>
#include <string>
#include <cstring>

int alphabet[26];
using namespace std;

int main(void)
{
    string tempInput;
    cin >> tempInput;
    
    memset(alphabet, -1, sizeof(alphabet));

    for(int i = 0; i < tempInput.length(); ++i)
    {
        if(alphabet[tempInput[i] - 'a'] == -1)
            alphabet[tempInput[i] - 'a'] = i;
    }

    for(int i = 0; i < 26; ++i)
    {
        cout << alphabet[i] << " ";
    }
}