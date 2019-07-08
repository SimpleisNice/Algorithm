#include <cstdio>

int main(void)
{
    int tempA, tempB;

    while(1)
    {
        scanf("%d %d", &tempA, &tempB);

        if(tempA == 0 && tempB == 0)
            break;
        printf("%d\n", tempA + tempB);
    }
    return 0;
}