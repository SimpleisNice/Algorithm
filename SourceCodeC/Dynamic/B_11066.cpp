#include <iostream>
#include <algorithm>

using namespace std;

int temp_array[500][500];
int temp_item[500];
int main(void)
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        
        for(int i=0; i<n; ++i)
        {
            cin >> temp_item[i];
            temp_array[i][i] = temp_item[i];
        }

        for(int i=0; i<n-1; ++i)
        {
            temp_array[i][i+1] = temp_item[i] + temp_item[i + 1];
        }

        for(int i=2; i<n; ++i)
        {
            temp_array[0][i] = temp_array[0][i-1] * 2 + temp_item[i];
        }
        for(int i = n -2; i >)
    }
    return 0;
}