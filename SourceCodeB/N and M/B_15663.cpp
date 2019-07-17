#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tempVector;
bool checkArray[9] = {false,};
int intArray[9] = {0, };

void GetNM(int tempN, int tempM, int count)
{
    if(count == tempM)
    {
        for(int i = 0; i < count; i++)
        {
            cout << intArray[i] << " ";
        }
        cout << "\n";

        return;
    }

    for(int i  = 0 ; i < tempN; i++)
    {
        if(checkArray[i])
            continue;

        intArray[count] = tempVector[i];
        
        if( count != 0 && intArray[count] == intArray[count - 1])
            continue;
        GetNM(tempN, tempM, count + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    int tempN, tempM;

    cin >> tempN >> tempM;

    for(int i = 0; i < tempN; i++)
    {
        int temp;  
        cin >> temp;

        tempVector.push_back(temp);
    }
    
    sort(tempVector.begin(), tempVector.end());

    GetNM(tempN, tempM, 0);
}