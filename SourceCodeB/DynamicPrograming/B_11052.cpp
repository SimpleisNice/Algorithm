#include <iostream>
using namespace std;

int cardPrice[1001] = {0,};
int tempArray[1001];

int GetMaxPrice(int tempN, int getN)
{
    if(tempN <= 0)
        return 0;

    if(tempArray[tempN] > 0)
        return tempArray[tempN]; 

    tempArray[tempN] = GetMaxPrice(tempN - getN, getN + 1) + cardPrice[getN];


    return tempArray[tempN];
}

int main(void)
{
    int tempN;
    cin >> tempN;

    for(int i = 1; i <= tempN; i++)
    {
        cin >> cardPrice[i];
    }


}