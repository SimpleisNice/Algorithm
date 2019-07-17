#include <iostream>
#include <list>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    list<int> tempA;
    int tempN;
    int temp;
    int totalSum = 0;
    int tempFirst;
    cin >> tempN;

    while(tempN--)
    {
        cin >> temp;

        tempA.push_back(temp);
    }

    tempA.sort();
    tempFirst = *(tempA.begin());

    while(!tempA.empty())
    {
        int tempSecond = 0;
        int max = 0;

        tempA.remove(tempFirst);

        for(list<int>::iterator it = tempA.begin() ; it != tempA.end(); ++it)
        {
            int tempMax = abs(tempFirst - *it);
            if(tempMax > max)
            {
                max = tempMax;
                tempSecond = *it;
            }
        }
        
        cout << max << " = " << tempFirst << " + " << tempSecond <<  endl;
        tempFirst = tempSecond;
        totalSum += max;
    }

    cout << totalSum << endl;
    return 0;
}