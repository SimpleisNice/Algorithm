#include <iostream>
#include <string>
#include <queue>

using namespace std;


int OrderFunc(string tempOrder)
{
    if(tempOrder == "push")
        return 0;
    if(tempOrder == "pop")
        return 1;
    if(tempOrder == "size")
        return 2;
    if(tempOrder == "empty")
        return 3;
    if(tempOrder == "front")
        return 4;
    if(tempOrder == "back")
        return 5;
}
int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    queue<int> tempQ;
    while(N--)
    {
        string tempStr;
        cin >> tempStr;
        int num = OrderFunc(tempStr);
        switch(num)
        {
            case 0:
                int tempNum;
                cin >> tempNum;
                tempQ.push(tempNum);
                break;
            case 1:
                if(!tempQ.empty())
                {
                    cout << tempQ.front() << '\n';
                    tempQ.pop();
                }
                else
                    cout << -1 << '\n';
                break;
            case 2:
                cout << tempQ.size() << '\n';
                break;
            case 3:
                if(tempQ.empty())
                    cout << 1 << '\n';
                else   
                    cout << 0 << '\n';
                break;
            case 4:
                if(!tempQ.empty())
                {
                    cout << tempQ.front() << '\n';
                }
                else
                    cout << -1 << '\n';            
                break;
            case 5:
                if(!tempQ.empty())
                {
                    cout << tempQ.back() << '\n';
                }
                else
                    cout << -1 << '\n';                        
                break;
        }
    }
    return 0;
}