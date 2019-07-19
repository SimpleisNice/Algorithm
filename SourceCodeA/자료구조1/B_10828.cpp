#include <iostream>
#include <string>
#include <stack>

using namespace std;

void CheckQuery(string temp, stack<int>& tempStack)
{
    switch(temp.at(0))
    {
        case 'p':
            if("push" == temp)
            {
                int num;
                cin >> num;
                tempStack.push(num);
            }
            else
            {
                if(!tempStack.empty())
                {
                    cout << tempStack.top() << endl;
                    tempStack.pop();
                }
                else
                    cout << -1 << endl;
            }
            break;
        case 's':
            cout << tempStack.size() << endl;
            break;
        case 'e':
            if(!tempStack.empty())
                cout << 0 << endl;
            else
                cout << 1 << endl;
            break;
        case 't':
            if(!tempStack.empty())
                cout << tempStack.top() << endl;
            else
                cout << -1 << endl;
            break;
        default:
            break;
    }
}
int main(void)
{
    int inputTemp;
    stack<int> inputStack;
    string queryString;

    cin >> inputTemp;

    while(inputTemp--)
    {
        cin >> queryString;
        CheckQuery(queryString, inputStack);
    }
    return 0;
}