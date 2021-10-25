#include <iostream>
#include <string>

using namespace std;

int alpabat[3];
int totalLength = 0;
string resultStr = "";
bool findCheck = false;

void getPattern(string tempStr, int a, int b, int c)
{   
    bool passCheck = true;

    for(int i=0; i< a+b+c; ++i)
    {
        char tempC = tempStr[i];
        if(tempC == 'A')
            continue;
        if(tempC == 'B')
            if(i + 1 < a + b + c && tempStr[i + 1] == 'B')
                return;
        if(tempC == 'C')
        {
            if(i + 1 < a + b + c && tempStr[i + 1] == 'C')
                return;
            if(i + 2 < a + b + c && tempStr[i + 2] == 'C')
                return;                
        }
    }
    if(a + b + c == totalLength && passCheck)
    {
        resultStr = tempStr;
        findCheck = true;
        return;
    }
    if(findCheck)
        return;
    if(a < alpabat[0])
        getPattern(tempStr + "A", a + 1, b, c);
    if(b < alpabat[1])
    {
        getPattern(tempStr + "B", a, b + 1, c);
    }
    if(c < alpabat[2])
    {
        getPattern(tempStr + "C", a, b, c + 1);
    }    
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string tempStr;
    cin >> tempStr;
    totalLength = tempStr.length();
    for(int i=0; i<totalLength; ++i)
    {
        if(tempStr[i] == 'A')
            alpabat[0] += 1;
        else if(tempStr[i] == 'B')
            alpabat[1] += 1;
        else
            alpabat[2] += 1;
    }
    getPattern("", 0,0,0);
    if(resultStr.length() == 0)
        cout << "-1" << "\n";
    else    
        cout << resultStr << "\n";
}