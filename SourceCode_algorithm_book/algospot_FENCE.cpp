#include <iostream>
#include <algorithm>

using namespace std;

int boardLength[20001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;

    while (c--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            cin >> boardLength[i];
        }

        int maxBoard = 0;
        // set length
        for (int i = 1; i <= n; ++i)
        {
            int tempLength = boardLength[i];
            int tempBoard =  tempLength;
            for (int j = i; j >= 0; --j)
            {
                if(tempLength > boardLength[j])
                {
                    tempLength = boardLength[j];   
                    if(tempLength == 1)
                    {
                        tempBoard = max(tempBoard, j); 
                        break;
                    }
                }
                tempBoard = max(tempBoard, tempLength * (i + 1 -j));  
            }
            maxBoard = max(maxBoard, tempBoard);
        }
        cout << maxBoard << "\n";
    }
    return 0;
}