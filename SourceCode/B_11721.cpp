#include <iostream>
#include <string>

using namespace std;
/*
    string substr를 활용하여 문자를 10개씩 짤라서 받아올 수 있다.
    추가적으로 substr 2개의 값을 받을 수 있으며, 1번째는 위치, 2번쨰는 개수 이다.
    개수란, 해당 위치부터 몇개를 받아올건지를 의미하며, 많이 개수가 문자열의 개수보다 많은경우
    문자열 길이 이상을 반환하지 않고 문자열의 끝 까지만 리턴함
    -> 참고 링크(https://modoocode.com/235)
 */
int main(void)
{
    string temp;
    string tempString;

    cin >> temp;

    for(int i=0; i < temp.length(); i+=10)
    {
        if((i + 10) <= temp.length())
        {
            tempString = temp.substr(i, 10);
        }
        else
        {
            tempString = temp.substr(i, temp.length()- i);
        }

        cout << tempString << endl;
        
    }
    return 0;
}