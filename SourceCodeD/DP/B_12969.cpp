// n,k
// 문자열 s의 길이는 n 
// A,B,C로 이루어져있음
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
int set[31];

void getFunc(vector tempV, int index, int increase)
{
    if(index == n || increase == 3)
        return;
    tempV[index] = tempV[index] + increase;
    
}
int main(void)
{
    cin >> n >> k;
    vector tempV(n);

    getFunc(tempV, 0);
    return 0;
}