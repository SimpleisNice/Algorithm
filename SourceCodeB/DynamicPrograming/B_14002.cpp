#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[10001];
int d[10001][2];    

void GetResult(int N)
{
    for(int i = 1; i <= N; ++i)
    {
        d[i][0] = 1;
        for(int j = i; j >= 1; --j)
        {
            if(A[i] > A[j])
            {
                if(d[i][0] < d[j][0] + 1)
                {
                    d[i][0] = d[j][0] + 1;
                    d[i][1] = j;
                }
            }
        }
    }
}
int main(void)
{
    int N;
    vector<int> tempV;

    scanf("%d", &N);

    for(int i = 1; i <= N; ++i)
    {
        scanf("%d", &A[i]);
    }
    GetResult(N);

    int tempMax = 0;
    int tempNum = 0;
    for(int i = 1; i <= N; ++i)
    {
        if(tempMax < d[i][0])
        {    
            tempMax = d[i][0];
            tempNum = i;
        }
    }
    
    printf("%d\n", tempMax);

    while(true)
    {
        if(tempNum == 0)
            break;
        tempV.push_back(tempNum);
        
        tempNum = d[tempNum][1];
    }
    
    sort(tempV.begin(), tempV.end());

    
    for(vector<int>::iterator it = tempV.begin(); it != tempV.end(); ++it)
    {
        printf("%d ", A[*it]);
    }
    printf("\n");
    
    return 0;
}