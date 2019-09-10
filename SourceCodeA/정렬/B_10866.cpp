#include <iostream>
#include <deque>
#include <string>

using namespace std;

int InputOrder(string temp)
{
    if(temp == "push_front")
        return 0;
    if(temp == "push_back")
        return 1;
    if(temp == "pop_front")
        return 2;
    if(temp == "pop_back") 
        return 3;
    if(temp == "size")
        return 4;
    if(temp == "empty")
        return 5;
    if(temp == "front")
        return 6;
    if(temp == "back")
        return 7;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    int N;
    deque<int> tempD;
    cin >> N;
    while(N--)
    {
        string orderStr;
        int orderNum;
        cin >> orderStr;

        orderNum = InputOrder(orderStr);

        int tempNum;
        switch(orderNum)
        {
            case 0:
                cin >> tempNum;
                tempD.push_front(tempNum);
                break;
            case 1:
                cin >> tempNum;
                tempD.push_back(tempNum);
                break;
            case 2:
                if(tempD.empty())
                    cout << "-1\n";
                else
                {   cout << tempD.front() << '\n'; 
                    tempD.pop_front();
                }
                break;
            case 3:
                if(tempD.empty())
                    cout << "-1\n";
                else
                {   
                    cout << tempD.back() << '\n'; 
                    tempD.pop_back();
                }
                break;
            case 4:
                cout << tempD.size() << '\n';
                break;
            case 5:
                if(tempD.empty())
                    cout << "1\n";
                else
                    cout << "0\n";
                break;
            case 6:
                if(tempD.empty())
                    cout << "-1\n";
                else
                {   
                    cout << tempD.front() << '\n'; 
                }
                break;
            case 7:
                if(tempD.empty())
                    cout << "-1\n";
                else
                {   
                    cout << tempD.back() << '\n'; 
                }
                break;
        }
    }
    return 0;
}