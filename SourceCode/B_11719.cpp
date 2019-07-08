#include <iostream>
#include <string>

using namespace std;
/* 
    11718과 동일해도 문제가 없는 이유는, string getline으로 처리하기 때문에
    입력에 문제가 없으며, 길이상 문제는 length()를 통해 확인 및 길이를 넘는 경우
    substr()을 통해 길이를 줄여서 temp를 변경해줌
*/
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