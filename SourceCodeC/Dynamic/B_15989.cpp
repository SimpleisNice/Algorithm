#include <cstdio>
#include <iostream>
int d[10001];
int nums[] = {1,2,3};
void GetResult(int n)
{
    for(int j = 0; j < 3; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(i - nums[j] >=0)
                d[i] += d[i-nums[j]];
        }
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);

    
    for(int i=0; i<n; ++i)
    {
        int m;
        scanf("%d", &m);
        std::fill_n(d, m, 0);
        d[0] = 1;

        GetResult(m);
        printf("%d\n", d[m]);
    }

}