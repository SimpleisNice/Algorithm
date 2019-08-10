#include <algorithm>
#include<iostream>


using namespace std;

int main(void)
{
    int i = 5;
    int num = 2;
    int result = 1;
    while(i--) 
    {    
        result *=  num;
        cout << result << endl;
    }
    cout << 0 % 10 << endl;
}