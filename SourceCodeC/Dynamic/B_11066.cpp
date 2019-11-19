#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int save_array[500][500];
int num_array[500];

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        memset(save_array, 0, sizeof(save_array));
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> num_array[i];
            sum += num_array[i];
            save_array[i][i] = num_array[i];
        }

        for (int i = 0; i < n - 1; ++i)
        {
            save_array[i][i + 1] = save_array[i][i] + save_array[i + 1][i + 1];
        }

        for (int i = 2; i < n - 1; ++i)
        {
            save_array[0][i] = save_array[0][i - 1] + save_array[i - 1][i] - num_array[i - 1];
        }

        for (int i = n - 3; i > 0; --i)
        {
            save_array[i][n - 1] = save_array[i + 1][n - 1] + save_array[i][i + 1] - num_array[i + 1];
        }

        int min_value = INT_MAX;

        for(int i=0; i<n-1; ++i)
        {
            int temp_num = save_array[0][i] + save_array[i+1][n-1];
            int temp_a = 0;
            int temp_b = 0;
            for(int j=i; j>0; --j)
            {
                temp_a += save_array[0][i];
            }
            for(int j=i+1; j<n-1; ++j)
            {
                temp_b += save_array[j][n-1];
            }

            min_value = min(min_value, temp_num + temp_a + temp_b);
        }
        cout << min_value << '\n';
    }
    return 0;
}