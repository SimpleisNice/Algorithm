#include <iostream>
#include <string>
using namespace std;
/*
    tempStr[i]의 경우 const char이기 때문에 변환이 필요하다.
    이 경우 간단하게 '0' 또느 48을 빼주면 된다.
 */
int main(void)
{
    int temp;
    int sum = 0;
    string tempStr;

    cin >> temp >> tempStr;
    
    for(int i = 0; i < temp; i++)
    {
        sum += tempStr[i] - '0';
    }

    cout << sum << endl;
    return 0;
}