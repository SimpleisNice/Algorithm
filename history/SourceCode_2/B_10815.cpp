#include <cstdio>
#include <set>

using namespace std;

int main(void)
{
    int num;
    scanf("%d",&num);
    set<int> tempSet;

    for(int i = 0; i < num; ++i)
    {
        int tempNum;
        scanf("%d",&tempNum);
        tempSet.insert(tempNum);
    }

    scanf("%d",&num);
    for(int i = 0; i < num; ++i)
    {
        int tempNum;
        scanf("%d",&tempNum);

        if(tempSet.find(tempNum) != tempSet.end())
        {
            printf("1 ");
        }
        else   
            printf("0 ");
    }
    return 0;
}