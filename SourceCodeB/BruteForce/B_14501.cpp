#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int tempN; 
    int max = 0;
    cin >> tempN;

    vector<int> tempDay(tempN);
    vector<int> tempMoney(tempN); 


    for(int i = 0; i < tempN; ++i)
    {
        cin >> tempDay[i] >> tempMoney[i];
    }
    
    for(int i = 0; i < tempN; ++i)
    {
        int pos = i;
        int posAdd = 0;
        int tempMax = 0;
        
        while(true)
        {
			if (i + tempDay[i] + posAdd >= tempN)
				break;

            tempMax = tempMoney[i];
            pos = tempDay[i] + posAdd++;
                
            while(true)
            {
                if(pos + tempDay[pos] >= tempN)
                    break;
                tempMax += tempMoney[pos];    
                pos += tempDay[pos];

                cout << tempMoney[pos] << " ";
            }
            cout <<"\n";
            if(tempMax > max)
            {
                max = tempMax;
            }
        }
    }
    cout << max <<"\n";
    return 0;
}