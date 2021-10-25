#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
    int tempINum;
    int checkNum;
    stack<int> tempStack;
    cin >> tempINum;

    while(tempINum--)
    {
        string tempStr;
        cin >> tempStr;
        checkNum = 0;
        for(int i =0; i< tempStr.length(); i++)
        {
            if(tempStr.at(i) == '(')
            {    
                tempStack.push(tempStr.at(i));
                checkNum++;
            }
            else
            {
                
                if(--checkNum < 0)
                {    
                    break;
                }
                else
                {
                    tempStack.pop();
                }
                
            }
        }
        printf("%s\n", checkNum == 0 ? "YES" : "NO");
    }
    return 0;
}