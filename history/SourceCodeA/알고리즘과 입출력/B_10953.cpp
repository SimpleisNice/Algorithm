#include <iostream>

int main(void)
{
    int temp;
    int tempA, tempB;
    char tempC;

    scanf("%d", &temp);

    for(int i = 0; i< temp; i++)
    {
        scanf("%d %*c %d", &tempA, &tempB);
        printf("%d\n", tempA + tempB);
    }
    return 0;
}