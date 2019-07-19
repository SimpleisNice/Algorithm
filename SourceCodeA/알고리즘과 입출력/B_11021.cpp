#include <iostream>

int main(void)
{
    int temp;
    int tempA, tempB;

    scanf("%d", &temp);

    for(int i = 0; i< temp; i++)
    {
        scanf("%d %d", &tempA, &tempB);
        printf("Case #%d: %d\n", i+1, tempA + tempB);
    }
    return 0;
}